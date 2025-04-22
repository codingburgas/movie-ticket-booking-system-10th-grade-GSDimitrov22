#pragma once
#include <string>
#include <vector>
#include "Hall.h"

using namespace std;

class Cinema {
public:
    string name;
    string city;
    vector<Hall> halls;

    Cinema(string n, string c) : name(n), city(c) {}

    void addHall(Hall hall) {
        halls.push_back(hall);
    }
};
