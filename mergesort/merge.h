// Filename: merge.h
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: Header file for an implementation of the merge sort

#ifndef MERGE_H
#define MERGE_H

int* createArray(std::ifstream& inputFile, int& eltCount);
// Precondition: a valid inputFile has been opened;
// Postcondition: An array containing the numbers to sort has been created and a pointer to the first element returned

void writeArray(std::ofstream& outputFile, int* array, int eltCount);

void mergeSort(int* a, int p, int r);

void merge(int* a, int p, int q, int r);
  


#endif
