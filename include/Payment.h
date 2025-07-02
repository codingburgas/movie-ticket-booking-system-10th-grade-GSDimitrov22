#pragma once
#include <string>

struct Payment {
    std::string method;
    double amount;

    Payment(const std::string& method, double amount)
        : method(method), amount(amount) {}
};
