#include <iostream>
#include <limits>
#include <map>
#include "MovieManager.h"
using namespace std;

struct User {
    string username;
    string password;
    string role;
};

void displayMovie(const Movie& movie) {
    cout << "ID: " << movie.id << " | Title: " << movie.title
        << " | Language: " << movie.language
        << " | Genre: " << movie.genre
        << " | Release Date: " << movie.releaseDate << endl;
}

int main() {
    map<string, User> users;
    users["admin"] = { "admin", "admin123", "admin" };

    MovieManager movieManager;
    movieManager.addMovie(Movie(1, "Avengers", "English", "Action", "2023-11-10"));
    movieManager.addMovie(Movie(2, "Inception", "English", "Sci-Fi", "2010-07-16"));

    User currentUser;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "\n1. Login\n2. Register\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string u, p;
            cout << "Username: ";
            getline(cin, u);
            cout << "Password: ";
            getline(cin, p);
            if (users.count(u) && users[u].password == p) {
                currentUser = users[u];
                loggedIn = true;
                cout << "Logged in as " << currentUser.role << endl;
            }
            else {
                cout << "Invalid credentials.\n";
            }
        }
        else if (choice == 2) {
            string u, p, r;
            cout << "Choose username: ";
            getline(cin, u);
            if (users.count(u)) {
                cout << "Username already exists.\n";
                continue;
            }
            cout << "Choose password: ";
            getline(cin, p);
            cout << "Role (admin/user): ";
            getline(cin, r);
            if (r != "admin" && r != "user") r = "user";
            users[u] = { u, p, r };
            cout << "Registered successfully. Please login.\n";
        }
    }

    int choice;
    do {
        cout << "\nMovie Ticket Booking System\n";
        cout << "1. Show All Movies\n";
        cout << "2. Search Movies\n";
        if (currentUser.role == "admin") {
            cout << "3. Add New Movie\n";
            cout << "4. Delete Movie\n";
            cout << "5. Edit Movie\n";
            cout << "6. Logout\n";
        }
        else {
            cout << "3. Logout\n";
        }
        cout << "Enter choice: ";
        cin >> choice;

        if (currentUser.role == "admin") {
            switch (choice) {
            case 1: {
                auto movies = movieManager.getAllMovies();
                for (const auto& m : movies) displayMovie(m);
                break;
            }
            case 2: {
                cout << "Search by:\n1. Title\n2. Language\n3. Genre\n4. Release Date\nChoice: ";
                int s;
                cin >> s;
                cin.ignore();
                cout << "Enter search text: ";
                string q;
                getline(cin, q);
                vector<Movie> results;
                if (s == 1) results = movieManager.searchByTitle(q);
                else if (s == 2) results = movieManager.searchByLanguage(q);
                else if (s == 3) results = movieManager.searchByGenre(q);
                else if (s == 4) results = movieManager.searchByReleaseDate(q);
                for (const auto& m : results) displayMovie(m);
                if (results.empty()) cout << "No results.\n";
                break;
            }
            case 3: {
                int id;
                string title, language, genre, date;
                cout << "Enter ID: "; cin >> id;
                cin.ignore();
                cout << "Title: "; getline(cin, title);
                cout << "Language: "; getline(cin, language);
                cout << "Genre: "; getline(cin, genre);
                cout << "Release Date (YYYY-MM-DD): "; getline(cin, date);
                movieManager.addMovie(Movie(id, title, language, genre, date));
                cout << "Movie added.\n";
                break;
            }
            case 4: {
                int id;
                cout << "Enter Movie ID to delete: ";
                cin >> id;
                movieManager.deleteMovie(id);
                cout << "Movie deleted.\n";
                break;
            }
            case 5: {
                int id;
                cout << "Enter Movie ID to edit: ";
                cin >> id;
                cin.ignore();
                cout << "New Title: ";
                string title;
                getline(cin, title);
                cout << "New Language: ";
                string language;
                getline(cin, language);
                cout << "New Genre: ";
                string genre;
                getline(cin, genre);
                cout << "New Release Date: ";
                string date;
                getline(cin, date);
                if (movieManager.updateMovie(id, title, language, genre, date)) {
                    cout << "Movie updated successfully.\n";
                }
                else {
                    cout << "Movie ID not found.\n";
                }
                break;
            }

            case 6:
                loggedIn = false;
                main();
                return 0;
            default:
                cout << "Invalid option.\n";
            }
        }
        else {
            switch (choice) {
            case 1: {
                auto movies = movieManager.getAllMovies();
                for (const auto& m : movies) displayMovie(m);
                break;
            }
            case 2: {
                cout << "Search by:\n1. Title\n2. Language\n3. Genre\n4. Release Date\nChoice: ";
                int s;
                cin >> s;
                cin.ignore();
                cout << "Enter search text: ";
                string q;
                getline(cin, q);
                vector<Movie> results;
                if (s == 1) results = movieManager.searchByTitle(q);
                else if (s == 2) results = movieManager.searchByLanguage(q);
                else if (s == 3) results = movieManager.searchByGenre(q);
                else if (s == 4) results = movieManager.searchByReleaseDate(q);
                for (const auto& m : results) displayMovie(m);
                if (results.empty()) cout << "No results.\n";
                break;
            }
            case 3:
                loggedIn = false;
                main();
                return 0;
            default:
                cout << "Invalid option.\n";
            }
        }
    } while (loggedIn);

    return 0;
}
