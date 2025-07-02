#pragma once
#include <iostream>
#include "Movie.h"
#include "Booking.h"

struct NotificationManager {
    static void notifyNewMovie(const Movie& movie) {
        std::cout << "New movie added: " << movie.title << std::endl;
    }

    static void notifyBookingConfirmation(const Booking& booking) {
        std::cout << "Booking confirmed for " << booking.user.name << std::endl;
    }
};
