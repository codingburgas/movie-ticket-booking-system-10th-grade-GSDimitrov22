#pragma once
#include <vector>
#include "Seat.h"
using namespace std;

class Hall {
public:
    int hallId;
    vector<Seat> seats;

    Hall(int id) : hallId(id) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    Seat* getSeat(const string& seatNumber) {
        for (auto& seat : seats) {
            if (seat.seatNumber == seatNumber) return &seat;
        }
        return nullptr;
    }
};
