#pragma once
#include <vector>
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
            if (movie.title == title) {
                results.push_back(movie);
            }
        }
        return results;
    }

    vector<Movie> getAllMovies() const {
        return movies;
    }
};
