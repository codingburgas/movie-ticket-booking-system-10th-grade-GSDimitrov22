#include <iostream>
#include <limits>
#include "include/Movie.h"
#include "include/MovieManager.h"

using namespace std;

void displayMovie(const Movie& movie) {
    cout << "\n--- Movie ---\n";
    cout << "Title       : " << movie.title << endl;
    cout << "Language    : " << movie.language << endl;
    cout << "Genre       : " << movie.genre << endl;
    cout << "Release Date: " << movie.releaseDate << endl;
}

void showAllMovies(const MovieManager& movieManager) {
    auto movies = movieManager.getAllMovies();
    if (movies.empty()) {
        cout << "No movies available.\n";
    } else {
        for (const auto& movie : movies) {
            displayMovie(movie);
        }
    }
}

void addNewMovie(MovieManager& movieManager) {
    string title, language, genre, releaseDate;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter movie title: ";
    getline(cin, title);

    cout << "Enter language: ";
    getline(cin, language);

    cout << "Enter genre: ";
    getline(cin, genre);

    cout << "Enter release date (YYYY-MM-DD): ";
    getline(cin, releaseDate);

    Movie newMovie(title, language, genre, releaseDate);
    movieManager.addMovie(newMovie);
    cout << "✅ Movie added successfully!\n";
}

void searchMovieByTitle(const MovieManager& movieManager) {
    string title;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter title to search: ";
    getline(cin, title);

    auto results = movieManager.searchByTitle(title);
    if (results.empty()) {
        cout << "❌ No movies found with title: " << title << endl;
    } else {
        for (const auto& movie : results) {
            displayMovie(movie);
        }
    }
}

int main() {
    MovieManager movieManager;

    // Sample data
    movieManager.addMovie(Movie("Avengers", "English", "Action", "2023-11-10"));
    movieManager.addMovie(Movie("3 Idiots", "Hindi", "Comedy", "2009-12-25"));

    int choice;

    do {
        cout << "\n Movie Ticket Booking System \n";
        cout << "1. Show All Movies\n";
        cout << "2. Add New Movie\n";
        cout << "3. Search Movie by Title\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showAllMovies(movieManager);
                break;
            case 2:
                addNewMovie(movieManager);
                break;
            case 3:
                searchMovieByTitle(movieManager);
                break;
            case 4:
                cout << "👋 Exiting... Goodbye!\n";
                break;
            default:
                cout << "⚠️ Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
