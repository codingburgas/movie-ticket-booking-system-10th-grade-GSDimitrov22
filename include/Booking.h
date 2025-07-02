#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Show.h"
#include "Payment.h"

struct Booking {
    User user;
    Show show;
    std::vector<std::string> seats;
    Payment payment;

    Booking(const User& u, const Show& s, const std::vector<std::string>& seats, const Payment& p)
        : user(u), show(s), seats(seats), payment(p) {}
};
