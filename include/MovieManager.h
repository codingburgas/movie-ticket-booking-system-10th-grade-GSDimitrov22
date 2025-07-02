#pragma once
#include <vector>
#include <string>
#include "Movie.h"

struct MovieManager {
    std::vector<Movie> movies;

    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void deleteMovie(int movieId) {
        movies.erase(
            std::remove_if(
                movies.begin(),
                movies.end(),
                [movieId](const Movie& m) { return m.id == movieId; }
            ),
            movies.end()
        );
    }

    std::vector<Movie> searchByTitle(const std::string& title) const {
        std::vector<Movie> result;
        for (const auto& m : movies)
            if (m.title.find(title) != std::string::npos)
                result.push_back(m);
        return result;
    }

    std::vector<Movie> searchByLanguage(const std::string& language) const {
        std::vector<Movie> result;
        for (const auto& m : movies)
            if (m.language.find(language) != std::string::npos)
                result.push_back(m);
        return result;
    }

    std::vector<Movie> searchByGenre(const std::string& genre) const {
        std::vector<Movie> result;
        for (const auto& m : movies)
            if (m.genre.find(genre) != std::string::npos)
                result.push_back(m);
        return result;
    }

    std::vector<Movie> searchByReleaseDate(const std::string& date) const {
        std::vector<Movie> result;
        for (const auto& m : movies)
            if (m.releaseDate.find(date) != std::string::npos)
                result.push_back(m);
        return result;
    }

    const std::vector<Movie>& getAllMovies() const {
        return movies;
    }
};
