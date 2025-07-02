#pragma once
#include <string>

enum class SeatType { SILVER = 1, GOLD = 2, PLATINUM = 3 };

struct Seat {
    std::string seatNumber;
    SeatType type;
    bool isBooked;

    Seat(const std::string& number, SeatType type)
        : seatNumber(number), type(type), isBooked(false) {}

    double getPrice() const {
        switch (type) {
        case SeatType::SILVER: return 10.0;
        case SeatType::GOLD: return 15.0;
        case SeatType::PLATINUM: return 20.0;
        }
        return 0.0;
    }
};
