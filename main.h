#ifndef MAIN_H
#define MAIN_H

// Utility functions
void clearInputBuffer();
int getValidatedIntInput(int min, int max);
char getValidatedCharInput(char option1, char option2);
int getValidatedRow();   // returns row index 0-4 (A-E)
int isValidSeat(int row, int col);
void pressEnterToContinue();
void clearScreen();

#endif