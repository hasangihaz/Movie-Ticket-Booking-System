#include <stdio.h>
#include "member2_display.h"
#include "member1_data.h"

void displayMainMenu() {
    printf("\n========================================\n");
    printf("   MOVIE TICKET BOOKING SYSTEM\n");
    printf("========================================\n");
    printf("1. View Showtimes\n");
    printf("2. View Seat Map\n");
    printf("3. Book a Seat\n");
    printf("4. Cancel a Booking\n");
    printf("5. Search Booking\n");
    printf("6. View Revenue Report\n");
    printf("7. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

void viewShowtimes() {
    printf("\n========== SHOWTIMES ==========\n");
    for (int i = 0; i < showtimeCount; i++) {
        printf("%d. %s - %s\n", i+1, showtimes[i].movieName, showtimes[i].time);
    }
    printf("================================\n");
}

void viewSeatMap(int showtimeIndex) {
    if (showtimeIndex < 0 || showtimeIndex >= showtimeCount) {
        printf("Invalid showtime!\n");
        return;
    }

    printf("\n========== SEAT MAP ==========\n");
    printf("Movie: %s\n", showtimes[showtimeIndex].movieName);
    printf("Time: %s\n", showtimes[showtimeIndex].time);
    printf("\nLegend: . = Available, X = Booked\n");
    printf("Rows A-B: Regular (Rs. 500)\n");
    printf("Rows C-D: Premium (Rs. 750)\n");
    printf("Row E: VIP (Rs. 1000)\n\n");

    printf("    ");
    for (int j = 0; j < COLS; j++) {
        printf("%2d ", j+1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c   ", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            printf(" %c ", showtimes[showtimeIndex].seatMap[i][j]);
        }
        printf("\n");
    }
    printf("================================\n");
}

int getSeatTier(int row) {
    if (row < 2) return REGULAR;
    else if (row < 4) return PREMIUM;
    else return VIP;
}

float getBasePrice(int row) {
    int tier = getSeatTier(row);
    switch(tier) {
        case REGULAR: return 500.0;
        case PREMIUM: return 750.0;
        case VIP: return 1000.0;
        default: return 0.0;
    }
}
