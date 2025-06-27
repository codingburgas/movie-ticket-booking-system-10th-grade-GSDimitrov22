#pragma once
#include <string>
using namespace std;

class User {
public:
    string name;
    string role;

    User(string n, string r) : name(n), role(r) {}
};
