#include <stdio.h>
#include <string.h>
#include "member3_booking.h"
#include "member1_data.h"
#include "member2_display.h"
#include "main.h"

float calculatePrice(int row, int isStudent, int isSenior, int groupSize) {
    float basePrice = getBasePrice(row);
    float discount = 0.0;

    if (isStudent) {
        discount = 0.10;
    } else if (isSenior) {
        discount = 0.20;
    }

    float priceAfterCategoryDiscount = basePrice * (1 - discount);

    if (groupSize >= 4) {
        priceAfterCategoryDiscount *= 0.90;
    }

    return priceAfterCategoryDiscount;
}

void bookSeat(int showtimeIndex) {
    if (showtimeIndex < 0 || showtimeIndex >= showtimeCount) {
        printf("Invalid showtime!\n");
        return;
    }

    viewSeatMap(showtimeIndex);

    char name[MAX_NAME_LEN];
    char studentFlag, seniorFlag;
    int isStudent = 0, isSenior = 0;
    int groupSize = 1;
    float totalPrice = 0.0;

    printf("\nEnter customer name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Is this a student booking? (y/n): ");
    studentFlag = getValidatedCharInput('y', 'n');
    if (studentFlag == 'y') isStudent = 1;

    printf("Is this a senior citizen booking? (y/n): ");
    seniorFlag = getValidatedCharInput('y', 'n');
    if (seniorFlag == 'y') isSenior = 1;

    printf("How many seats are you booking? (1-10): ");
    groupSize = getValidatedIntInput(1, 10);

    int rows[groupSize];
    int cols[groupSize];
    int valid = 1;

    // Collect all seat selections
    for (int i = 0; i < groupSize; i++) {
        printf("\nSeat %d of %d:\n", i+1, groupSize);
        int row = getValidatedRow();
        printf("Enter seat number (1-10): ");
        int col = getValidatedIntInput(1, COLS) - 1;

        if (!isValidSeat(row, col)) {
            printf("Invalid seat selection!\n");
            valid = 0;
            break;
        }

        if (showtimes[showtimeIndex].seatMap[row][col] == 'X') {
            printf("Seat %c%d is already taken!\n", 'A' + row, col + 1);
            valid = 0;
            break;
        }

        // Check duplicate within this transaction
        for (int j = 0; j < i; j++) {
            if (rows[j] == row && cols[j] == col) {
                printf("Seat %c%d already selected in this booking!\n", 'A' + row, col + 1);
                valid = 0;
                break;
            }
        }
        if (!valid) break;

        rows[i] = row;
        cols[i] = col;
    }

    if (!valid) {
        printf("Booking cancelled. No seats were booked.\n");
        return;
    }

    // Book each seat
    for (int i = 0; i < groupSize; i++) {
        int row = rows[i], col = cols[i];
        float price = calculatePrice(row, isStudent, isSenior, groupSize);
        totalPrice += price;

        showtimes[showtimeIndex].seatMap[row][col] = 'X';

        Booking* bookings = showtimes[showtimeIndex].bookings;
        int count = showtimes[showtimeIndex].bookingCount;

        strcpy(bookings[count].customerName, name);
        bookings[count].row = row;
        bookings[count].col = col;
        bookings[count].pricePaid = price;
        bookings[count].isStudent = isStudent;
        bookings[count].isSenior = isSenior;
        bookings[count].isGroup = (groupSize >= 4);
        bookings[count].groupSize = groupSize;
        bookings[count].isActive = 1;

        showtimes[showtimeIndex].bookingCount++;
    }

    showtimes[showtimeIndex].totalRevenue += totalPrice;
    showtimes[showtimeIndex].totalTicketsSold += groupSize;

    printf("\n========== BOOKING CONFIRMATION ==========\n");
    printf("Customer: %s\n", name);
    printf("Movie: %s\n", showtimes[showtimeIndex].movieName);
    printf("Time: %s\n", showtimes[showtimeIndex].time);
    printf("Seats booked: ");
    for (int i = 0; i < groupSize; i++) {
        printf("%c%d", 'A' + rows[i], cols[i] + 1);
        if (i < groupSize - 1) printf(", ");
    }
    printf("\n");
    printf("Ticket Type: ");
    if (isStudent) printf("Student");
    else if (isSenior) printf("Senior Citizen");
    else printf("Regular");
    if (groupSize >= 4) printf(" + Group Discount");
    printf("\n");
    printf("Total Price Paid: Rs. %.2f\n", totalPrice);
    printf("===========================================\n");
}
