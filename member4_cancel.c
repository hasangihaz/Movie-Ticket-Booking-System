#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "member4_cancel_search.h"
#include "member1_data.h"
#include "main.h"

void cancelBooking(int showtimeIndex) {
    if (showtimeIndex < 0 || showtimeIndex >= showtimeCount) {
        printf("Invalid showtime!\n");
        return;
    }

    int row = getValidatedRow();
    printf("Enter seat number (1-10): ");
    int col = getValidatedIntInput(1, COLS) - 1;

    if (!isValidSeat(row, col)) {
        printf("Invalid seat selection!\n");
        return;
    }

    if (showtimes[showtimeIndex].seatMap[row][col] != 'X') {
        printf("Seat %c%d is not booked!\n", 'A' + row, col + 1);
        return;
    }

    int found = 0;
    Booking* bookings = showtimes[showtimeIndex].bookings;
    int count = showtimes[showtimeIndex].bookingCount;

    for (int i = 0; i < count; i++) {
        if (bookings[i].row == row && bookings[i].col == col && bookings[i].isActive) {
            showtimes[showtimeIndex].seatMap[row][col] = '.';
            showtimes[showtimeIndex].totalRevenue -= bookings[i].pricePaid;
            showtimes[showtimeIndex].totalTicketsSold -= bookings[i].groupSize;
            bookings[i].isActive = 0;
            found = 1;

            printf("\nBooking cancelled successfully!\n");
            printf("Seat %c%d is now available.\n", 'A' + row, col + 1);
            printf("Refund amount: Rs. %.2f\n", bookings[i].pricePaid);
            break;
        }
    }

    if (!found) {
        printf("Booking not found for seat %c%d!\n", 'A' + row, col + 1);
    }
}

void searchBooking() {
    printf("\n========== SEARCH BOOKING ==========\n");
    printf("1. Search by Customer Name\n");
    printf("2. Search by Seat\n");
    printf("Enter your choice: ");

    int choice = getValidatedIntInput(1, 2);
    char name[MAX_NAME_LEN];
    int row, col;
    int found = 0;

    if (choice == 1) {
        printf("Enter customer name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("\n========== SEARCH RESULTS ==========\n");
        for (int s = 0; s < showtimeCount; s++) {
            Booking* bookings = showtimes[s].bookings;
            for (int i = 0; i < showtimes[s].bookingCount; i++) {
                if (bookings[i].isActive &&
                    strcasecmp(bookings[i].customerName, name) == 0) {
                    printf("Customer: %s\n", bookings[i].customerName);
                    printf("Movie: %s\n", showtimes[s].movieName);
                    printf("Time: %s\n", showtimes[s].time);
                    printf("Seat: %c%d\n", 'A' + bookings[i].row, bookings[i].col + 1);
                    printf("Price: Rs. %.2f\n", bookings[i].pricePaid);
                    printf("---------------------------\n");
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("No bookings found for '%s'\n", name);
        }
    } else {
        row = getValidatedRow();
        printf("Enter seat number (1-10): ");
        col = getValidatedIntInput(1, COLS) - 1;

        printf("\n========== SEARCH RESULTS ==========\n");
        for (int s = 0; s < showtimeCount; s++) {
            Booking* bookings = showtimes[s].bookings;
            for (int i = 0; i < showtimes[s].bookingCount; i++) {
                if (bookings[i].isActive &&
                    bookings[i].row == row && bookings[i].col == col) {
                    printf("Customer: %s\n", bookings[i].customerName);
                    printf("Movie: %s\n", showtimes[s].movieName);
                    printf("Time: %s\n", showtimes[s].time);
                    printf("Seat: %c%d\n", 'A' + row, col + 1);
                    printf("Price: Rs. %.2f\n", bookings[i].pricePaid);
                    printf("---------------------------\n");
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("No booking found for seat %c%d\n", 'A' + row, col + 1);
        }
    }
    printf("====================================\n");
}
