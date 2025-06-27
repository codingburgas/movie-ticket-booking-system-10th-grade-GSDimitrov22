#pragma once
#include <string>
using namespace std;

enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
public:
    string seatNumber;
    SeatType type;
    bool isBooked;

    Seat(string sn, SeatType st) : seatNumber(sn), type(st), isBooked(false) {}

    double getPrice() const {
        switch (type) {
        case SeatType::SILVER: return 100.0;
        case SeatType::GOLD: return 150.0;
        case SeatType::PLATINUM: return 200.0;
        }
        return 0.0;
    }
};
