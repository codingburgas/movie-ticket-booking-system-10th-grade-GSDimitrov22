#pragma once

using namespace std;

class Hall {
public:
    int hallId;
    int totalSeats;

    Hall(int id, int seats) : hallId(id), totalSeats(seats) {}
};
