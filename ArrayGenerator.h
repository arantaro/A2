#ifndef MAIN_ARRAYGENERATOR_H
#define MAIN_ARRAYGENERATOR_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class ArrayGenerator {
 public:
  ArrayGenerator();

  std::vector<int> GetRandomArr(int);
  std::vector<int> GetReversedArr(int);
  std::vector<int> GetAlmostSortedArr(int);

 private:
  const int min_number_ = 0;
  const int max_number_ = 6000;
  int max_length_ = 10000;
  std::vector<int> default_arr_;
  std::vector<int> almost_sorted_arr_;
  std::vector<int> reversed_arr_;

  int Rnd(std::mt19937&);
  std::vector<int> CopyPart(std::vector<int>&, int);
};

#endif  // MAIN_ARRAYGENERATOR_H
