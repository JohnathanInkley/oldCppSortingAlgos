// Filename: main.cpp
// Author: Johnathan Inkley
// Date: 2016 11 13
// Description: An implementation of the counting sort

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "counting.h"


int main()
{
  // Open data file to sort
  std::ifstream inputFile;
  inputFile.open("max100.dat");
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
  int* b = countingSort(a, 100, eltCount);

  // Write sorted data into file
  std::ofstream outputFile;
  outputFile.open("sortedList.dat");
  if (outputFile.fail())
    {
      std::cerr << "File failed to open";
      exit(1);
    }

  writeArray(outputFile, b, eltCount);
  outputFile.close();

  return 0;
}
