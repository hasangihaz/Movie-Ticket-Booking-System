#ifndef MEMBER1_DATA_H
#define MEMBER1_DATA_H

#define ROWS 5
#define COLS 10
#define MAX_MOVIES 3
#define MAX_SHOWTIMES 2
#define MAX_BOOKINGS 100
#define MAX_NAME_LEN 50

typedef enum {
    REGULAR,
    PREMIUM,
    VIP
} SeatTier;

typedef struct {
    int row;
    int col;
    char customerName[MAX_NAME_LEN];
    float pricePaid;
    int isStudent;
    int isSenior;
    int isGroup;
    int groupSize;
    int isActive;
} Booking;

typedef struct {
    char movieName[MAX_NAME_LEN];
    char time[MAX_NAME_LEN];
    char seatMap[ROWS][COLS];
    Booking bookings[MAX_BOOKINGS];
    int bookingCount;
    float totalRevenue;
    int totalTicketsSold;
} Showtime;

extern Showtime showtimes[MAX_MOVIES * MAX_SHOWTIMES];
extern int showtimeCount;

void initializeData();

#endif