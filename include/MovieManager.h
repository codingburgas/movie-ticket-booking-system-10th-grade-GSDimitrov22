#pragma once
#include <vector>
#include <string>
#include "Movie.h"
using namespace std;

class MovieManager {
private:
    vector<Movie> movies;

public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    vector<Movie> searchByTitle(const string& title) const {
        vector<Movie> results;
        for (const auto& movie : movies) {
            if (movie.title == title)
                results.push_back(movie);
        }
        return results;
    }

    vector<Movie> searchByLanguage(const string& language) const {
        vector<Movie> results;
        for (const auto& movie : movies) {
            if (movie.language == language)
                results.push_back(movie);
        }
        return results;
    }

    vector<Movie> searchByGenre(const string& genre) const {
        vector<Movie> results;
        for (const auto& movie : movies) {
            if (movie.genre == genre)
                results.push_back(movie);
        }
        return results;
    }

    vector<Movie> searchByReleaseDate(const string& date) const {
        vector<Movie> results;
        for (const auto& movie : movies) {
            if (movie.releaseDate == date)
                results.push_back(movie);
        }
        return results;
    }

    vector<Movie> getAllMovies() const {
        return movies;
    }
};
