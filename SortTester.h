#ifndef MAIN_SORTTESTER_H
#define MAIN_SORTTESTER_H

#include <vector>
#include <chrono>
#include <fstream>
#include "ArrayGenerator.h"

class SortTester {
 public:
  void Sort();

 private:
  ArrayGenerator arrayGenerator_;

  void InsertionSort(std::vector<int>& arr);
  std::vector<int> CopyPart(const std::vector<int>& source, int l, int r);
  void MergeInsertionSort(std::vector<int>& arr, int switch_param);
};

#endif  // MAIN_SORTTESTER_H
