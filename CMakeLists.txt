cmake_minimum_required(VERSION 3.30)
project(movie_ticket_booking_system_10th_grade_GSDimitrov22)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(movie_ticket_booking_system_10th_grade_GSDimitrov22
        include/Booking.h
        include/Cinema.h
        include/Hall.h
        include/Movie.h
        include/MovieManager.h
        include/NotificationManager.h
        include/Payment.h
        include/Seat.h
        include/Show.h
        include/User.h
        main.cpp


)