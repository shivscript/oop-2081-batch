// Tic-Tac-Toe Game  By Ankit Belbase(HCE081BEI007) /
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

#define BOLD    "\033[1m"

class GameBase {
public:
    virtual void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
    virtual ~GameBase() {}
};

class BasePlayer {
public:
    virtual char getSymbol() const = 0;
    virtual int getMove(char board[3][3]) = 0;
    virtual ~BasePlayer() {}
};

class HumanPlayer : public BasePlayer {
public:
    char symbol;
    HumanPlayer(char s) : symbol(s) {}
    char getSymbol() const override { return symbol; }
    int getMove(char board[3][3]) override {
        int choice;
        cout << BOLD << GREEN << "Player " << (symbol == 'X' ? RED : BLUE) << symbol << RESET << GREEN << ", enter your move (1-9): " << RESET;
        cin >> choice;
        return choice;
    }
};

class AIPlayer : public BasePlayer {
public:
    int aiDifficulty;
    AIPlayer(int diff) : aiDifficulty(diff) {}
    char getSymbol() const override { return 'O'; }

    bool checkWin(char board[3][3], char player) {
        for (int i = 0; i < 3; ++i)
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
                return true;
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            return true;
        return false;
    }

    bool isDraw(char board[3][3]) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    int minimax(char board[3][3], bool isMaximizing) {
        if (checkWin(board, 'O')) return 1;
        if (checkWin(board, 'X')) return -1;
        if (isDraw(board)) return 0;

        int bestScore = isMaximizing ? -1000 : 1000;
        char symbol = isMaximizing ? 'O' : 'X';

        for (int i = 0; i < 9; ++i) {
            int r = i / 3;
            int c = i % 3;
            if (board[r][c] != 'X' && board[r][c] != 'O') {
                char temp = board[r][c];
                board[r][c] = symbol;
                int score = minimax(board, !isMaximizing);
                board[r][c] = temp;
                bestScore = isMaximizing ? max(score, bestScore) : min(score, bestScore);
            }
        }
        return bestScore;
    }

    int getMove(char board[3][3]) override {
        if (aiDifficulty == 1) {
            // Easy: Random move
            int c;
            do {
                c = rand() % 9 + 1;
            } while (board[(c - 1) / 3][(c - 1) % 3] == 'X' || board[(c - 1) / 3][(c - 1) % 3] == 'O');
            return c;
        } else if (aiDifficulty == 2) {
            // Moderate: Win > Block > Random
            for (int i = 1; i <= 9; i++) {
                int row = (i - 1) / 3;
                int col = (i - 1) % 3;
                if (board[row][col] != 'X' && board[row][col] != 'O') {
                    // Try winning move
                    char temp = board[row][col];
                    board[row][col] = 'O';
                    if (checkWin(board, 'O')) {
                        board[row][col] = temp;
                        return i;
                    }
                    board[row][col] = temp;
                }
            }
            for (int i = 1; i <= 9; i++) {
                int row = (i - 1) / 3;
                int col = (i - 1) % 3;
                if (board[row][col] != 'X' && board[row][col] != 'O') {
                    // Try blocking move
                    char temp = board[row][col];
                    board[row][col] = 'X';
                    if (checkWin(board, 'X')) {
                        board[row][col] = temp;
                        return i;
                    }
                    board[row][col] = temp;
                }
            }
            // Else random
            int c;
            do {
                c = rand() % 9 + 1;
            } while (board[(c - 1) / 3][(c - 1) % 3] == 'X' || board[(c - 1) / 3][(c - 1) % 3] == 'O');
            return c;
        } else {
            // Hard: Minimax
            int bestScore = -1000, bestMove = -1;
            for (int i = 1; i <= 9; ++i) {
                int r = (i - 1) / 3;
                int c = (i - 1) % 3;
                if (board[r][c] != 'X' && board[r][c] != 'O') {
                    char temp = board[r][c];
                    board[r][c] = 'O';
                    int score = minimax(board, false);
                    board[r][c] = temp;
                    if (score > bestScore) {
                        bestScore = score;
                        bestMove = i;
                    }
                }
            }
            return bestMove;
        }
    }
};

class TicTacToeGame : public GameBase {
public:
    char board[3][3];
    char currentPlayer;
    int player1Score, player2Score, draws;
    bool vsComputer;
    int aiDifficulty;
    BasePlayer* playerX;
    BasePlayer* playerO;

    TicTacToeGame() {
        player1Score = 0;
        player2Score = 0;
        draws = 0;
        vsComputer = false;
        aiDifficulty = 1;
        playerX = nullptr;
        playerO = nullptr;
    }
    ~TicTacToeGame() {
        delete playerX;
        delete playerO;
    }

    void initializeBoard() {
        char cell = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = cell++;
    }

    void drawBoard() {
        cout << CYAN << BOLD << "\n      TIC-TAC-TOE\n" << RESET;
        cout << YELLOW << "   Player " << RED << "X" << RESET << YELLOW << "  vs  " << BLUE << "O" << RESET << "\n";
        cout << CYAN << "   -------------\n" << RESET;
        for (int i = 0; i < 3; i++) {
            cout << CYAN << "   | " << RESET;
            for (int j = 0; j < 3; j++) {
                char cell = board[i][j];
                if (cell == 'X') cout << RED << cell << RESET;
                else if (cell == 'O') cout << BLUE << cell << RESET;
                else cout << YELLOW << cell << RESET;
                cout << CYAN << " | " << RESET;
            }
            cout << "\n   -------------\n";
        }
        cout << "\n";
    }

    bool checkWin(char player) {
        for (int i = 0; i < 3; i++)
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
                return true;

        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            return true;

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    bool makeMove(int choice, char player) {
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
            return false;
        board[row][col] = player;
        return true;
    }

    void playGame() {
        initializeBoard();
        currentPlayer = 'X';
        while (true) {
            drawBoard();
            int choice;
            if (currentPlayer == 'X')
                choice = playerX->getMove(board);
            else
                choice = playerO->getMove(board);
            clearScreen();
            if (!makeMove(choice, currentPlayer)) {
                cout << YELLOW << "Invalid move! Try again.\n" << RESET;
                cin.ignore();
                cin.get();
                clearScreen();
                continue;
            }
            if (checkWin(currentPlayer)) {
                drawBoard();
                if (vsComputer && currentPlayer == 'O') {
                    cout << RED << BOLD << "\nSorry, you lost! The AI wins!\n" << RESET;
                    player2Score++;
                } else if (vsComputer && currentPlayer == 'X') {
                    cout << GREEN << BOLD << "\nCongratulations! You beat the AI!\n" << RESET;
                    player1Score++;
                } else {
                    cout << GREEN << BOLD << "\nCongratulations! Player " << currentPlayer << " wins!\n" << RESET;
                    (currentPlayer == 'X') ? player1Score++ : player2Score++;
                }
                cout << CYAN << "Press Enter to continue..." << RESET;
                cin.ignore();
                cin.get();
                break;
            }
            if (checkDraw()) {
                drawBoard();
                cout << YELLOW << "It's a draw!\n" << RESET;
                draws++;
                cout << CYAN << "Press Enter to continue..." << RESET;
                cin.ignore();
                cin.get();
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    void showScores() {
        clearScreen();
        cout << CYAN << BOLD << "\n==== SCOREBOARD ====" << RESET << endl;
        cout << GREEN << BOLD << "Player " << GREEN << "Scores" << RESET << ":\n";
        cout << RED << "Player X: " << player1Score << RESET << "\n";
        if (vsComputer)
            cout << BLUE << "Computer (O): " << player2Score << RESET << "\n";
        else
            cout << BLUE << "Player O: " << player2Score << RESET << "\n";
        cout << YELLOW << "Draws: " << draws << RESET << "\n\n";
        cout << CYAN << "Press Enter to return to menu..." << RESET;
        cin.ignore();
        cin.get();
    }

    void saveScoresToFile() {
        ofstream file("tictactoe_scores.txt");
        if (file) {
            file << player1Score << " " << player2Score << " " << draws;
            file.close();
            cout << GREEN << "Scores saved to file!\n" << RESET;
        } else {
            cout << RED << "Error saving scores.\n" << RESET;
        }
    }

    void loadScoresFromFile() {
        ifstream file("tictactoe_scores.txt");
        if (file) {
            file >> player1Score >> player2Score >> draws;
            file.close();
            cout << GREEN << "Scores loaded from file!\n" << RESET;
        } else {
            cout << RED << "No saved score file found.\n" << RESET;
        }
    }

    void gameMenu() {
        int choice;
        do {
            clearScreen();
            cout << CYAN << BOLD << "\n==== TIC-TAC-TOE MENU ====\n" << RESET;
            cout << GREEN << "1. Start New Game\n" << RESET;
            cout << YELLOW << "2. View Scores\n" << RESET;
            cout << BLUE << "3. Save Scores\n" << RESET;
            cout << CYAN << "4. Load Scores\n" << RESET;
            cout << RED << "5. Exit\n" << RESET;
            cout << BOLD << "Enter your choice: " << RESET;
            cin >> choice;
            clearScreen();
            switch (choice) {
            case 1:
                cout << YELLOW << "Select Mode:\n" << RESET << GREEN << "1. Player vs Player\n" << RESET << BLUE << "2. Player vs Computer\n" << RESET << BOLD << "Enter: " << RESET;
                int mode;
                cin >> mode;
                clearScreen();
                vsComputer = (mode == 2);
                if (playerX) delete playerX;
                if (playerO) delete playerO;
                playerX = new HumanPlayer('X');
                if (vsComputer) {
                    cout << CYAN << "Select AI Difficulty:\n" << RESET << GREEN << "1. Easy\n" << RESET << YELLOW << "2. Moderate\n" << RESET << RED << "3. Hard\n" << RESET << BOLD << "Enter: " << RESET;
                    cin >> aiDifficulty;
                    clearScreen();
                    playerO = new AIPlayer(aiDifficulty);
                } else {
                    playerO = new HumanPlayer('O');
                }
                playGame();
                break;
            case 2:
                showScores();
                clearScreen();
                break;
            case 3:
                saveScoresToFile();
                clearScreen();
                break;
            case 4:
                loadScoresFromFile();
                clearScreen();
                break;
            case 5:
                cout << YELLOW << "Exiting game. Goodbye!\n" << RESET;
                break;
            default:
                cout << RED << "Invalid choice!\n" << RESET;
                clearScreen();
            }
        } while (choice != 5);
    }
};

int main() {
    srand(time(0));
    TicTacToeGame game;
    game.loadScoresFromFile();
    game.clearScreen();
    cout << CYAN << BOLD << "Welcome to the Colorful Tic-Tac-Toe Game!\n" << RESET;
    game.gameMenu();
    return 0;
}
