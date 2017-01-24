// Filename: quick.h
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: Header file for an implementation of the quick sort

#ifndef QUICK_H
#define QUICK_H

int* createArray(std::ifstream& inputFile, int& eltCount);
// Precondition: a valid inputFile has been opened;
// Postcondition: An array containing the numbers to sort has been created and a pointer to the first element returned

void writeArray(std::ofstream& outputFile, int* array, int eltCount);

void quickSort(int* array, int p, int r); // p is start index in array, r is end

int pivot(int* array, int p, int r); // Finds the index of a pivot for an array for quick sort

#endif
