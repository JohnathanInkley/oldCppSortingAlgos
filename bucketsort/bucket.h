// Filename: bucket.h
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: Header file for an implementation of the bucket sort

#ifndef BUCKET_H
#define BUCKET_H

double* createArray(std::ifstream& inputFile, int& eltCount);
// Precondition: a valid inputFile has been opened;
// Postcondition: An array containing the numbers to sort has been created and a pointer to the first element returned

void writeArray(std::ofstream& outputFile, double* array, int eltCount);

double* bucketSort(double* a, int n);

void insertionSort(std::vector<double>& vec);


#endif
