#pragma once
#include <string>
#include "Movie.h"
#include "Hall.h"

struct Show {
    int id;
    Movie movie;
    std::string time;
    Hall* hall;

    Show(int id, const Movie& movie, const std::string& time)
        : id(id), movie(movie), time(time), hall(nullptr) {}

    void setHall(Hall* h) { hall = h; }
};
