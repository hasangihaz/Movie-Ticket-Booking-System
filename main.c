#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "member1_data.h"
#include "member2_display.h"
#include "member3_booking.h"
#include "member4_cancel_search.h"
#include "member5_revenue.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int getValidatedIntInput(int min, int max) {
    int input;
    char buffer[100];
    int valid = 0;
    
    while (!valid) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &input) == 1) {
                if (input >= min && input <= max) {
                    valid = 1;
                } else {
                    printf("Please enter a number between %d and %d: ", min, max);
                }
            } else {
                printf("Invalid input. Please enter a number between %d and %d: ", min, max);
            }
        }
    }
    return input;
}

char getValidatedCharInput(char option1, char option2) {
    char input;
    char buffer[100];
    int valid = 0;
    
    while (!valid) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%c", &input) == 1) {
                input = tolower(input);
                if (input == option1 || input == option2) {
                    valid = 1;
                } else {
                    printf("Please enter '%c' or '%c': ", option1, option2);
                }
            } else {
                printf("Invalid input. Please enter '%c' or '%c': ", option1, option2);
            }
        }
    }
    return input;
}

// Only accepts single letter A-E, returns row index 0-4
int getValidatedRow() {
    char buffer[100];
    int valid = 0;
    int row = -1;
    
    while (!valid) {
        printf("Enter row (A-E): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strlen(buffer) == 1) {
                char c = toupper(buffer[0]);
                if (c >= 'A' && c <= 'E') {
                    row = c - 'A';
                    valid = 1;
                } else {
                    printf("Invalid row! Please enter a letter between A and E.\n");
                }
            } else {
                printf("Invalid input! Please enter a single letter (A-E).\n");
            }
        }
    }
    return row;
}

int isValidSeat(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

void pressEnterToContinue() {
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}

void clearScreen() {
    system(CLEAR);
}

int main() {
    initializeData();
    
    int choice;
    do {
        clearScreen();
        displayMainMenu();
        choice = getValidatedIntInput(1, 7);
        
        switch(choice) {
            case 1:
                viewShowtimes();
                break;
            case 2:
                viewShowtimes();
                if (showtimeCount > 0) {
                    printf("\nEnter showtime number (1-%d): ", showtimeCount);
                    int index = getValidatedIntInput(1, showtimeCount) - 1;
                    viewSeatMap(index);
                }
                break;
            case 3:
                viewShowtimes();
                if (showtimeCount > 0) {
                    printf("\nEnter showtime number (1-%d): ", showtimeCount);
                    int index = getValidatedIntInput(1, showtimeCount) - 1;
                    bookSeat(index);
                }
                break;
            case 4:
                viewShowtimes();
                if (showtimeCount > 0) {
                    printf("\nEnter showtime number (1-%d): ", showtimeCount);
                    int index = getValidatedIntInput(1, showtimeCount) - 1;
                    cancelBooking(index);
                }
                break;
            case 5:
                searchBooking();
                break;
            case 6:
                viewRevenueReport();
                break;
            case 7:
                printf("\nThank you for using the Movie Ticket Booking System!\n");
                continue;
        }
        pressEnterToContinue();
    } while(choice != 7);
    
    return 0;
}