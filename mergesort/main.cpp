// Filename: main.cpp
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: An implementation of the merge sort

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "merge.h"


int main()
{
  // Open data file to sort
  std::ifstream inputFile;
  inputFile.open("smallListOfNum.dat");
  if (inputFile.fail())
    {
      std::cerr << "File failed to open";
      exit(1);
    }

  // Read data into an array
  int *a;
  int eltCount;
  a = createArray(inputFile, eltCount);
  inputFile.close();

  // Sort array
  mergeSort(a, 0, eltCount - 1);

  // Write sorted data into file
  std::ofstream outputFile;
  outputFile.open("sortedList.dat");
  if (outputFile.fail())
    {
      std::cerr << "File failed to open";
      exit(1);
    }

  writeArray(outputFile, a, eltCount);
  outputFile.close();

  return 0;
}
