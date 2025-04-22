#pragma once
#include <string>

using namespace std;

class Movie {
public:
    string title;
    string language;
    string genre;
    string releaseDate;

    Movie(string t, string l, string g, string r)
        : title(t), language(l), genre(g), releaseDate(r) {}
};
