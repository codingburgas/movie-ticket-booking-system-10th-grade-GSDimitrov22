

/*
#include <iostream>
#include <sstream>
#include <limits>


#include "include/Hall.h"
#include "include/MovieManager.h"
#include "include/NotificationManager.h"
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
    cout << "Movie added successfully!\n";
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

void searchMovies(const MovieManager& movieManager) {
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
            cout << "Exiting... Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}



*/






#include <iostream>
#include <vector>
#include <limits>
#include "Cinema.h"
#include "Hall.h"
#include "Seat.h"
#include "Movie.h"
#include "Show.h"
#include "User.h"
#include "Booking.h"
#include "Payment.h"
#include "NotificationManager.h"

using namespace std;

void displayMovie(const Movie& movie) {
    cout << "Title: " << movie.title << endl;
    cout << "Language: " << movie.language << endl;
    cout << "Genre: " << movie.genre << endl;
    cout << "Release Date: " << movie.releaseDate << endl;
}

void listMovies(const vector<Movie>& movies) {
    for (const auto& m : movies) displayMovie(m);
}

void searchMovies(const vector<Movie>& movies) {
    cout << "Search by:\n1. Title\n2. Language\n3. Genre\n4. Release Date\nChoice: ";
    int option;
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter query: ";
    string query;
    getline(cin, query);
    bool found = false;
    for (const auto& m : movies) {
        if ((option == 1 && m.title == query) ||
            (option == 2 && m.language == query) ||
            (option == 3 && m.genre == query) ||
            (option == 4 && m.releaseDate == query)) {
            displayMovie(m);
            found = true;
        }
    }
    if (!found) cout << "No movies found.\n";
}

void bookSeats(User& user, Show& show) {
    cout << "Available Seats:\n";
    for (auto& s : show.hall->seats) {
        if (!s.isBooked) cout << s.seatNumber << " (" << (int)s.type << ")\n";
    }
    cout << "Enter seat numbers to book (comma separated): ";
    string line;
    getline(cin, line);
    vector<string> seatNumbers;
    double total = 0.0;
    size_t pos = 0;
    while ((pos = line.find(',')) != string::npos) {
        string token = line.substr(0, pos);
        Seat* seat = show.hall->getSeat(token);
        if (seat && !seat->isBooked) {
            seat->isBooked = true;
            seatNumbers.push_back(token);
            total += seat->getPrice();
        }
        line.erase(0, pos + 1);
    }
    Seat* seat = show.hall->getSeat(line);
    if (seat && !seat->isBooked) {
        seat->isBooked = true;
        seatNumbers.push_back(line);
        total += seat->getPrice();
    }
    string method = user.role == "Customer" ? "Credit Card" : "Cash";
    Payment payment(method, total);
    Booking booking(user, show, seatNumbers, payment);
    NotificationManager::notifyBookingConfirmation(booking);
    cout << "Booking complete. Total: $" << total << endl;
}

void adminAddMovie(vector<Movie>& movies) {
    string t, l, g, d;
    cout << "Title: "; getline(cin, t);
    cout << "Language: "; getline(cin, l);
    cout << "Genre: "; getline(cin, g);
    cout << "Release Date: "; getline(cin, d);
    movies.push_back(Movie(movies.size() + 1, t, l, g, d));
    NotificationManager::notifyNewMovie(movies.back());
}

void adminDeleteMovie(vector<Movie>& movies) {
    cout << "Enter movie ID to delete: ";
    int id; cin >> id; cin.ignore();
    movies.erase(remove_if(movies.begin(), movies.end(),
        [id](const Movie& m) { return m.id == id; }), movies.end());
    cout << "Deleted.\n";
}

int main() {
    vector<Movie> movies;
    movies.push_back(Movie(1, "Avengers", "English", "Action", "2023-11-10"));
    movies.push_back(Movie(2, "Dune", "English", "Sci-Fi", "2024-05-20"));

    Cinema cinema(1, "Central Cinema");
    Hall hall1(1, "Hall 1");
    for (int i = 1; i <= 5; i++) hall1.addSeat(Seat("S" + to_string(i), SeatType::SILVER));
    for (int i = 6; i <= 8; i++) hall1.addSeat(Seat("G" + to_string(i), SeatType::GOLD));
    for (int i = 9; i <= 10; i++) hall1.addSeat(Seat("P" + to_string(i), SeatType::PLATINUM));
    cinema.addHall(hall1);

    Show show1(1, movies[0], "18:00");
    cinema.halls[0].addShow(show1);

    User user(1, "Alice", "Customer");
    User admin(2, "Bob", "Admin");

    int choice;
    do {
        cout << "\n1. List Movies\n2. Search Movies\n3. Book Seats\n4. Admin Add Movie\n5. Admin Delete Movie\n6. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: listMovies(movies); break;
        case 2: searchMovies(movies); break;
        case 3: bookSeats(user, cinema.halls[0].shows[0]); break;
        case 4: adminAddMovie(movies); break;
        case 5: adminDeleteMovie(movies); break;
        case 6: cout << "Exiting.\n"; break;
        default: cout << "Invalid.\n";
        }
    } while (choice != 6);

    return 0;
}
