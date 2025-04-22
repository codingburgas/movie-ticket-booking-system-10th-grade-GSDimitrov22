#include <iostream>
#include "include/Movie.h"
#include "include/Hall.h"
#include "include/Cinema.h"
#include "include/Show.h"
#include "include/MovieManager.h"

using namespace std;

int main() {
    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    MovieManager movieManager;
    Movie m1("Avengers", "English", "Action", "2023-11-10");
    Movie m2("3 Idiots", "Hindi", "Comedy", "2009-12-25");

    movieManager.addMovie(m1);
    movieManager.addMovie(m2);

    cout << "\nSearch results for 'Avengers':\n";
    auto results = movieManager.searchByTitle("Avengers");
    for (const auto& movie : results) {
        cout << "Title: " << movie.title << ", Language: " << movie.language
             << ", Genre: " << movie.genre << ", Release Date: " << movie.releaseDate << endl;
    }

    return 0;
}
