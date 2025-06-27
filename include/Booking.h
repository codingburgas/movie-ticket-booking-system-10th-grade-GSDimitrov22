#pragma once
#include <vector>
#include "User.h"
#include "Show.h"
#include "Seat.h"
#include "Payment.h"
using namespace std;

class Booking {
public:
    User user;
    Show show;
    vector<string> seatNumbers;
    Payment payment;

    Booking(User u, Show s, vector<string> seats, Payment p)
        : user(u), show(s), seatNumbers(seats), payment(p) {}
};
