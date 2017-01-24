// Filename: heap.cpp
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: Definition for the heap sort function

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "heap.h"

int* createArray(std::ifstream& inputFile, int& eltCount)
{
  // First count elts in file
  eltCount = std::distance(std::istream_iterator<int>(inputFile), std::istream_iterator<int>());
  inputFile.clear();
  inputFile.seekg(0, std::ios::beg);

  // Create blank array of correct size
  int *numArray = new int[eltCount];

  // Read numbers into array
  int currentNum, eltNum = 0;
  inputFile >> currentNum;
  while (!inputFile.eof())
    {
      numArray[eltNum] = currentNum;
      eltNum++;
      inputFile >> currentNum;
    }

  return numArray;
}

void writeArray(std::ofstream& outputFile, int* array, int eltCount)
{
  for (int i = 0; i < eltCount; i++)
    {
      outputFile << array[i] << " ";
    }

  return;
}

void heapSort(int* a, int n)
{
  int temp;
  buildMaxHeap(a, n);
  for (int j = n - 1; j >= 0; j--)
    {
      temp = a[0];
      a[0] = a[j];
      a[j] = temp;
      maxHeapify(a, 0, n, j - 1);
    }
  return;
}

void buildMaxHeap(int* a, int n)
{
  for (int i = (n/2)-1; i >= 0; i--)
    {
      maxHeapify(a, i, n, n-1);
    }
  return;
}

void maxHeapify(int* a, int i, int n, int heapSize)
{
  if (4 * ((i+1)/2) > n)
    return;
  int left, right, temp, max;
  left = 4 * ((i+1)/2) + 2 * (i+1 - 2 * ((i+1)/2)) - 1;
  right = left + 1;
  if (a[left] > a[i] && left  <= heapSize)
    max = left;
  else
    max = i;
  if (a[right] > a[max] && right <= heapSize)
    max = right;

  if (max != i)
    {
      temp = a[i];
      a[i] = a[max];
      a[max] = temp;
      maxHeapify(a, max, n, heapSize);
    }
  return;
}
