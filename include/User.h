#pragma once
#include <string>

struct User {
    int id;
    std::string name;
    std::string role;

    User(int id, const std::string& name, const std::string& role)
        : id(id), name(name), role(role) {}
};
