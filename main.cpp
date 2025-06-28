
#include <iostream>
#include <sstream>
#include <limits>
#include "MovieManager.h"
#include "NotificationManager.h"
#include "Show.h"
#include "User.h"
#include "Booking.h"
#include "include/Hall.h"
#include "include/MovieManager.h"
#include "include/Seat.h"
#include "include/Show.h"
using namespace std;

void displayMovie(const Movie& movie) {
    cout << "\n--- Movie ---\n";
    cout << "Title       : " << movie.title << endl;
    cout << "Language    : " << movie.language << endl;
    cout << "Genre       : " << movie.genre << endl;
    cout << "Release Date: " << movie.releaseDate << endl;
}

void addNewMovie(MovieManager& movieManager) {
    string title, language, genre, releaseDate;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter movie title: ";
    getline(cin, title);
    cout << "Enter language: ";
    getline(cin, language);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter release date (YYYY-MM-DD): ";
    getline(cin, releaseDate);

    Movie newMovie(title, language, genre, releaseDate);
    movieManager.addMovie(newMovie);
    NotificationManager::notifyNewMovie(newMovie);
    cout << "\u2705 Movie added successfully!\n";
}

void bookTicket(User& user, Show& show) {
    vector<string> selectedSeats;
    string seatInput;
    double totalCost = 0.0;

    cin.ignore();
    cout << "Available seats:\n";
    for (const auto& seat : show.hall->seats) {
        if (!seat.isBooked)
            cout << seat.seatNumber << " (" << (int)seat.type << ")\n";
    }

    cout << "Enter seat numbers to book (comma separated): ";
    getline(cin, seatInput);

    stringstream ss(seatInput);
    string seatNumber;
    while (getline(ss, seatNumber, ',')) {
        Seat* seat = show.hall->getSeat(seatNumber);
        if (seat && !seat->isBooked) {
            seat->isBooked = true;
            totalCost += seat->getPrice();
            selectedSeats.push_back(seat->seatNumber);
        }
    }

    string method = user.role == "Customer" ? "Credit Card" : "Cash";
    Payment payment(method, totalCost);
    Booking booking(user, show, selectedSeats, payment);
    NotificationManager::notifyBooking(booking);
    cout << "\nBooking completed. Total Cost: $" << totalCost << "\n";
}

void searchMovies(MovieManager& movieManager) {
    string query;
    cout << "Search by:\n1. Title\n2. Language\n3. Genre\n4. Release Date\nChoice: ";
    int option;
    cin >> option;
    cin.ignore();
    cout << "Enter your query: ";
    getline(cin, query);

    vector<Movie> results;
    switch (option) {
        case 1: results = movieManager.searchByTitle(query); break;
        case 2: results = movieManager.searchByLanguage(query); break;
        case 3: results = movieManager.searchByGenre(query); break;
        case 4: results = movieManager.searchByReleaseDate(query); break;
        default: cout << "Invalid option"; return;
    }

    for (const auto& movie : results)
        displayMovie(movie);
    if (results.empty())
        cout << "No movies found.\n";
}

int main() {
    MovieManager movieManager;
    movieManager.addMovie(Movie("Avengers", "English", "Action", "2023-11-10"));

    Hall hall(1);
    for (int i = 1; i <= 10; ++i)
        hall.addSeat(Seat("S" + to_string(i), SeatType::SILVER));
    for (int i = 11; i <= 15; ++i)
        hall.addSeat(Seat("G" + to_string(i), SeatType::GOLD));
    for (int i = 16; i <= 18; ++i)
        hall.addSeat(Seat("P" + to_string(i), SeatType::PLATINUM));

    Show show(movieManager.getAllMovies()[0], &hall, "18:00");
    User user("Alice", "Customer");

    int choice;
    do {
        cout << "\n Movie Ticket Booking System \n";
        cout << "1. Show All Movies\n";
        cout << "2. Add New Movie\n";
        cout << "3. Book Ticket\n";
        cout << "4. Search Movies\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (const auto& movie : movieManager.getAllMovies())
                    displayMovie(movie);
                break;
            case 2:
                addNewMovie(movieManager);
                break;
            case 3:
                bookTicket(user, show);
                break;
            case 4:
                searchMovies(movieManager);
                break;
            case 5:
                cout << "\U0001F44B Exiting... Goodbye!\n";
                break;
            default:
                cout << "\u26A0\uFE0F Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
