#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

enum Genre {
    POP,
    ROCK,
    JAZZ,
    CLASSICAL,
    OTHER
};

string genreToString(Genre g) {
    const string genres[] = {
        "Pop",
        "Rock",
        "Jazz",
        "Classical",
        "Other"
    };
    return genres[g];
}

Genre inputGenre() {
    int choice;
    cout << "\nSelect a music genre:\n";
    cout << "1. Pop\n";
    cout << "2. Rock\n";
    cout << "3. Jazz\n";
    cout << "4. Classical\n";
    cout << "5. Other\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice >= 1 && choice <= 5) {
        return static_cast<Genre>(choice - 1);
    } else {
        return OTHER;
    }
}

class Song {
public:
    string title;
    string artist;
    Genre genre;
    int duration;

    Song(string t, string a, Genre g, int d) {
        title = t;
        artist = a;
        genre = g;
        duration = d;
    }

    void display() const {
        cout << "Song Title: " << title << "\n";
        cout << "Artist Name: " << artist << "\n";
        cout << "Genre: " << genreToString(genre) << "\n";
        cout << "Duration: " << duration << " seconds\n";
        cout << "------------------\n";
    }
};

class Playlist {
    vector<Song> songs;
    string name;

public:
    Playlist(string n) {
        name = n;
        cout << "New playlist created: " << name << "\n";
    }

    void addSong() {
        string title;
        string artist;
        int duration;
        Genre genre;

        cin.ignore();
        cout << "Enter the song title: ";
        getline(cin, title);
        cout << "Enter the artist name: ";
        getline(cin, artist);
        genre = inputGenre();
        cout << "Enter duration (in seconds): ";
        cin >> duration;

        Song newSong(title, artist, genre, duration);
        songs.push_back(newSong);
        cout << "Song added to playlist!\n";
    }

    void removeSong() {
        string title;
        bool found = false;

        cin.ignore();
        cout << "Enter the song title to remove: ";
        getline(cin, title);

        for (auto it = songs.begin(); it != songs.end(); ++it) {
            if (it->title == title) {
                songs.erase(it);
                found = true;
                cout << "Song removed from playlist!\n";
                break;
            }
        }
        if (!found) {
            cout << "Song not found in playlist.\n";
        }
    }

    void displaySongs() const {
        if (songs.empty()) {
            cout << "The playlist is empty.\n";
            return;
        }
        cout << "\nSongs in playlist '" << name << "':\n";
        for (const auto& song : songs) {
            song.display();
        }
    }

    void saveToFile() const {
        ofstream file;
        file.open("playlist.txt");
        if (!file.is_open()) {
            cout << "Error: Could not open file for saving.\n";
            return;
        }
        for (const auto& song : songs) {
            file << song.title << ",";
            file << song.artist << ",";
            file << genreToString(song.genre) << ",";
            file << song.duration << "\n";
        }
        file.close();
        cout << "Playlist saved to playlist.txt\n";
    }
};

int main() {
    string userName;
    string playlistName;
    int choice;

    cout << "Enter your name: ";
    getline(cin, userName);
    cout << "Welcome, " << userName << "!\n";

    cout << "Enter playlist name: ";
    getline(cin, playlistName);

    Playlist playlist(playlistName);

    do {
        cout << "\n=== Playlist Menu ===\n";
        cout << "1. Add a new song\n";
        cout << "2. Remove a song\n";
        cout << "3. Display all songs\n";
        cout << "4. Save playlist to file\n";
        cout << "5. Exit program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playlist.addSong();
                break;
            case 2:
                playlist.removeSong();
                break;
            case 3:
                playlist.displaySongs();
                break;
            case 4:
                playlist.saveToFile();
                break;
            case 5:
                cout << "Goodbye, " << userName << "!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}