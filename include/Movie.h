#pragma once
#include <string>

struct Movie {
    int id;
    std::string title;
    std::string language;
    std::string genre;
    std::string releaseDate;

    Movie(int id, const std::string& t, const std::string& l, const std::string& g, const std::string& d)
        : id(id), title(t), language(l), genre(g), releaseDate(d) {}
};
