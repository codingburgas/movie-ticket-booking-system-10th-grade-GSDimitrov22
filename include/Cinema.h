#pragma once
#include <string>
#include <vector>
#include "Hall.h"

struct Cinema {
    int id;
    std::string name;
    std::vector<Hall> halls;

    Cinema(int id, const std::string& name) : id(id), name(name) {}

    void addHall(const Hall& hall) {
        halls.push_back(hall);
    }
};
