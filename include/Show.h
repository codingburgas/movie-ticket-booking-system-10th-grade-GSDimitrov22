#pragma once
#include <string>
#include "Movie.h"
#include "Hall.h"

using namespace std;

class Show {
public:
    Movie movie;
    Hall* hall;
    string time;

    Show(Movie m, Hall* h, string t) : movie(m), hall(h), time(t) {}
};
