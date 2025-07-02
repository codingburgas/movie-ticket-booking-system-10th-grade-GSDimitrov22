#pragma once
#include <string>
#include <vector>
#include "Seat.h"
#include "Show.h"

struct Hall {
    int id;
    std::string name;
    std::vector<Seat> seats;
    std::vector<Show> shows;

    Hall(int id, const std::string& name) : id(id), name(name) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    Seat* getSeat(const std::string& seatNumber) {
        for (auto& seat : seats)
            if (seat.seatNumber == seatNumber)
                return &seat;
        return nullptr;
    }

    void addShow(const Show& show) {
        shows.push_back(show);
    }
};
