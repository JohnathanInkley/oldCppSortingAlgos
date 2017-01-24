// Filename: counting.cpp
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: Definition for the counting sort function

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "counting.h"

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

int* countingSort(int* a, int k, int n)
{
  int *b, *c;
  b = new int[n];
  c = new int[k];

  for (int i = 0; i < k; i++)
    {
      c[i] = 0;
    }
  for (int j = 0; j < n; j++)
    {
      c[a[j]-1]++;
    }
  for (int i = 1; i < k; i++)
    {
      c[i] += c[i-1];
    }
  for (int j = 0; j < n; j++)
    {
      b[c[a[j]-1]-1] = a[j];
      c[a[j]-1]--;
    }
  return b;
}
