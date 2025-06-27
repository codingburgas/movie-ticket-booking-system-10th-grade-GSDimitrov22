#pragma once
#include <iostream>
#include "Movie.h"
#include "Booking.h"
using namespace std;

class NotificationManager {
public:
    static void notifyNewMovie(const Movie& movie) {
        cout << "\U0001F4E2 New Movie Released: " << movie.title << endl;
    }

    static void notifyBooking(const Booking& booking) {
        cout << "\U0001F4E2 Booking Confirmed for: " << booking.user.name << endl;
    }

    static void notifyCancellation(const Booking& booking) {
        cout << "\U0001F4E2 Booking Canceled for: " << booking.user.name << endl;
    }
};
