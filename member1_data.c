#include <stdio.h>
#include <string.h>
#include "member1_data.h"

Showtime showtimes[MAX_MOVIES * MAX_SHOWTIMES];
int showtimeCount = 0;

void initializeData() {
    // Movie 1: Avengers: Endgame
    strcpy(showtimes[0].movieName, "Avengers: Endgame");
    strcpy(showtimes[0].time, "3:00 PM");
    memset(showtimes[0].seatMap, '.', ROWS * COLS);
    showtimes[0].bookingCount = 0;
    showtimes[0].totalRevenue = 0;
    showtimes[0].totalTicketsSold = 0;
    
    strcpy(showtimes[1].movieName, "Avengers: Endgame");
    strcpy(showtimes[1].time, "7:00 PM");
    memset(showtimes[1].seatMap, '.', ROWS * COLS);
    showtimes[1].bookingCount = 0;
    showtimes[1].totalRevenue = 0;
    showtimes[1].totalTicketsSold = 0;
    
    strcpy(showtimes[2].movieName, "Inception");
    strcpy(showtimes[2].time, "2:00 PM");
    memset(showtimes[2].seatMap, '.', ROWS * COLS);
    showtimes[2].bookingCount = 0;
    showtimes[2].totalRevenue = 0;
    showtimes[2].totalTicketsSold = 0;
    
    strcpy(showtimes[3].movieName, "Inception");
    strcpy(showtimes[3].time, "6:30 PM");
    memset(showtimes[3].seatMap, '.', ROWS * COLS);
    showtimes[3].bookingCount = 0;
    showtimes[3].totalRevenue = 0;
    showtimes[3].totalTicketsSold = 0;
    
    strcpy(showtimes[4].movieName, "The Dark Knight");
    strcpy(showtimes[4].time, "4:30 PM");
    memset(showtimes[4].seatMap, '.', ROWS * COLS);
    showtimes[4].bookingCount = 0;
    showtimes[4].totalRevenue = 0;
    showtimes[4].totalTicketsSold = 0;
    
    strcpy(showtimes[5].movieName, "The Dark Knight");
    strcpy(showtimes[5].time, "9:00 PM");
    memset(showtimes[5].seatMap, '.', ROWS * COLS);
    showtimes[5].bookingCount = 0;
    showtimes[5].totalRevenue = 0;
    showtimes[5].totalTicketsSold = 0;
    
    showtimeCount = 6;
}