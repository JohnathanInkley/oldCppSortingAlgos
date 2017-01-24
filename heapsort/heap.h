// Filename: heap.h
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: Header file for an implementation of the heap sort

#ifndef HEAP_H
#define HEAP_H

int* createArray(std::ifstream& inputFile, int& eltCount);
// Precondition: a valid inputFile has been opened;
// Postcondition: An array containing the numbers to sort has been created and a pointer to the first element returned

void writeArray(std::ofstream& outputFile, int* array, int eltCount);

void heapSort(int* a, int n);

void buildMaxHeap(int* a, int n);

void maxHeapify(int* a, int i, int n, int heapSize);
  


#endif
