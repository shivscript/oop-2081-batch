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

char board[3][3];
char currentPlayer;
int player1Score = 0, player2Score = 0, draws = 0;
bool vsComputer = false;
int aiDifficulty = 1; // 1 = Easy, 2 = Moderate, 3 = Hard

void initializeBoard() {
    char cell = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = cell++;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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

int minimax(char b[3][3], bool isMaximizing) {
    for (int i = 0; i < 3; i++) {
        if ((b[i][0] == b[i][1] && b[i][1] == b[i][2])) {
            if (b[i][0] == 'O') return 1;
            if (b[i][0] == 'X') return -1;
        }
        if ((b[0][i] == b[1][i] && b[1][i] == b[2][i])) {
            if (b[0][i] == 'O') return 1;
            if (b[0][i] == 'X') return -1;
        }
    }
    if ((b[0][0] == b[1][1] && b[1][1] == b[2][2])) {
        if (b[0][0] == 'O') return 1;
        if (b[0][0] == 'X') return -1;
    }
    if ((b[0][2] == b[1][1] && b[1][1] == b[2][0])) {
        if (b[0][2] == 'O') return 1;
        if (b[0][2] == 'X') return -1;
    }

    bool movesLeft = false;
    for (int i = 0; i < 3 && !movesLeft; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] != 'X' && b[i][j] != 'O')
                movesLeft = true;

    if (!movesLeft) return 0;

    if (isMaximizing) {
        int best = -1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (b[i][j] != 'X' && b[i][j] != 'O') {
                    char backup = b[i][j];
                    b[i][j] = 'O';
                    best = max(best, minimax(b, false));
                    b[i][j] = backup;
                }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (b[i][j] != 'X' && b[i][j] != 'O') {
                    char backup = b[i][j];
                    b[i][j] = 'X';
                    best = min(best, minimax(b, true));
                    b[i][j] = backup;
                }
        return best;
    }
}

int getComputerMove() {
    if (aiDifficulty == 1) {
        int c;
        do {
            c = rand() % 9 + 1;
        } while (!makeMove(c, 'O'));
        return c;
    }

    if (aiDifficulty == 2) {
        for (int c = 1; c <= 9; c++) {
            int r = (c - 1) / 3, col = (c - 1) % 3;
            if (board[r][col] != 'X' && board[r][col] != 'O') {
                char temp = board[r][col];
                board[r][col] = 'O';
                if (checkWin('O')) return c;
                board[r][col] = 'X';
                if (checkWin('X')) return c;
                board[r][col] = temp;
            }
        }
        int c;
        do {
            c = rand() % 9 + 1;
        } while (!makeMove(c, 'O'));
        return c;
    }

    int bestScore = -1000, bestMove = 1;
    for (int c = 1; c <= 9; c++) {
        int r = (c - 1) / 3, col = (c - 1) % 3;
        if (board[r][col] != 'X' && board[r][col] != 'O') {
            char temp = board[r][col];
            board[r][col] = 'O';
            int score = minimax(board, false);
            board[r][col] = temp;
            if (score > bestScore) {
                bestScore = score;
                bestMove = c;
            }
        }
    }
    makeMove(bestMove, 'O');
    return bestMove;
}

void playerTurn() {
    int choice;
    cout << BOLD << GREEN << "Player " << (currentPlayer == 'X' ? RED : BLUE) << currentPlayer << RESET << GREEN << ", enter your move (1-9): " << RESET;
    cin >> choice;
    clearScreen(); // Clear after input
    if (!makeMove(choice, currentPlayer)) {
        cout << YELLOW << "Invalid move! Try again.\n" << RESET;
        cin.ignore();
        cin.get();
        clearScreen(); // Clear after invalid input
        playerTurn();
    }
}

void computerTurn() {
    int move = getComputerMove();
    clearScreen(); // Clear after computer move
    cout << CYAN << "Computer chose position: " << YELLOW << move << RESET << "\n";
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    initializeBoard();
    currentPlayer = 'X';

    while (true) {
        drawBoard();

        if (vsComputer && currentPlayer == 'O')
            computerTurn();
        else
            playerTurn();

        if (checkWin(currentPlayer)) {
            drawBoard();
            if (vsComputer) {
                if (currentPlayer == 'O') {
                    cout << RED << BOLD << "\nSorry, you lost! The AI wins!\n" << RESET;
                    player2Score++;
                } else {
                    cout << GREEN << BOLD << "\nCongratulations! You beat the AI!\n" << RESET;
                    player1Score++;
                }
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

        switchPlayer();
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
        clearScreen(); // Clear after input

        switch (choice) {
        case 1:
            cout << YELLOW << "Select Mode:\n" << RESET << GREEN << "1. Player vs Player\n" << RESET << BLUE << "2. Player vs Computer\n" << RESET << BOLD << "Enter: " << RESET;
            int mode;
            cin >> mode;
            clearScreen(); // Clear after input
            vsComputer = (mode == 2);
            if (vsComputer) {
                cout << CYAN << "Select AI Difficulty:\n" << RESET << GREEN << "1. Easy\n" << RESET << YELLOW << "2. Moderate\n" << RESET << RED << "3. Hard\n" << RESET << BOLD << "Enter: " << RESET;
                cin >> aiDifficulty;
                clearScreen(); // Clear after input
            }
            playGame();
            break;
        case 2:
            showScores();
            clearScreen(); // Clear after viewing scores
            break;
        case 3:
            saveScoresToFile();
            clearScreen(); // Clear after saving scores
            break;
        case 4:
            loadScoresFromFile();
            clearScreen(); // Clear after loading scores
            break;
        case 5:
            cout << YELLOW << "Exiting game. Goodbye!\n" << RESET;
            break;
        default:
            cout << RED << "Invalid choice!\n" << RESET;
            clearScreen(); // Clear after invalid input
        }

    } while (choice != 5);
}

int main() {
    srand(time(0));
    loadScoresFromFile();
    clearScreen();
    cout << CYAN << BOLD << "Welcome to the Colorful Tic-Tac-Toe Game!\n" << RESET;
    gameMenu();
    return 0;
}

