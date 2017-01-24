// Filename: merge.cpp
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: Definition for the merge sort function

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "merge.h"

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

void mergeSort(int* a, int p, int r)
{
  if (p < r)
    {
      int q = p + (r - p)/2;

      mergeSort(a, p, q);
      mergeSort(a, q+1, r);
      merge(a, p, q, r);
    }
  return;
}

void merge(int* a,int p, int q, int r)
{
  int* b = new int[r - p + 1];
  int i = p, j = q + 1;
  for (int k = 0; k < r - p + 1; k++)
    {
      if (i <= q && j <= r)
	{
	  if (a[i] < a[j])
	    {
	      b[k] = a[i];
	      i++;
	    }
	  else
	    {
	      b[k] = a[j];
	      j++;
	    }
	}
      else if (i == q + 1)
	{
	  b[k] = a[j];
	  j++;
	}
      else
	{
	  b[k] = a[i];
	  i++;
	}
    }
  for (int k = 0; k < r - p + 1; k++)
    {
      a[p + k] = b[k];
    }
  delete[] b;
  return;
}
