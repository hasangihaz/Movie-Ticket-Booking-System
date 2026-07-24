#include <stdio.h>
#include "member5_revenue.h"


void viewRevenueReport() {
    printf("\n========== REVENUE REPORT ==========\n");
    printf("%-25s %-15s %-15s %-15s\n", "Movie", "Time", "Tickets Sold", "Revenue");
    printf("------------------------------------------------------------\n");

    float totalRevenueAll = 0;
    int totalTicketsAll = 0;

     for (int i = 0; i < showtimeCount; i++) {
        printf("%-25s %-15s %-15d Rs. %.2f\n",
               showtimes[i].movieName,
               showtimes[i].time,
               showtimes[i].totalTicketsSold,
               showtimes[i].totalRevenue);
        totalRevenueAll += showtimes[i].totalRevenue;
        totalTicketsAll += showtimes[i].totalTicketsSold;
    }

    printf("------------------------------------------------------------\n");
    printf("%-25s %-15s %-15d Rs. %.2f\n",
           "TOTAL", "", totalTicketsAll, totalRevenueAll);
    printf("=========================================\n");
}
