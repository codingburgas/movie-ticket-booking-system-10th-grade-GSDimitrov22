#pragma once
#include <string>
using namespace std;

class Payment {
public:
    string method;
    double amount;

    Payment(string m, double a) : method(m), amount(a) {}
};
