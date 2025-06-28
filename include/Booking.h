#pragma once
#include <utility>
#include <vector>
#include "User.h"
#include "Show.h"
#include "Payment.h"
using namespace std;

class Booking {
public:
    User user;
    Show show;
    vector<string> seatNumbers;
    Payment payment;
    vector<string> seats_;

    Booking(User u, Show s, vector<string> seats, Payment p);
};

inline Booking::Booking(User u, Show s, vector<string> seats, Payment p): user(std::move(u)), show(s), seatNumbers(std::move(seats)), payment(p), seats_(std::move(seats))
{}
