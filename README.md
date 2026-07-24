# Movie Ticket Booking System

## Overview
A command-line movie theater ticket booking system implemented in C with a modular structure suitable for team development.

## Features
- View showtimes for 3 movies (2 showtimes each)
- Interactive seat map display (5 rows × 10 seats)
- Seat tiers: Regular (A-B), Premium (C-D), VIP (E)
- Discounts: Student (10%), Senior (20%), Group (10% for 4+ seats)
- Book multiple seats in one transaction (no duplicate seats allowed)
- Cancel bookings with automatic revenue update
- Search bookings by customer name or seat
- Revenue report per showtime and total
- Robust input validation (row letters only, numeric seat numbers)
- Screen clearing after each command for clean interface

## Compilation
Compile all `.c` files together:
```bash
gcc -o booking main.c member1_data.c member2_display.c member3_booking.c member4_cancel_search.c member5_revenue.c
