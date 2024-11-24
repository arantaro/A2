#include "ArrayGenerator.h"

int ArrayGenerator::Rnd(std::mt19937& rnd) {
  return min_number_ + static_cast<int>(rnd() % (max_number_ - min_number_ + 1));
}

ArrayGenerator::ArrayGenerator() {
  std::mt19937 rnd(1);

  std::vector<int> arr(max_length_);
  for (int i = 0; i < max_length_; ++i) {
    arr[i] = Rnd(rnd);
  }

  default_arr_ = std::vector<int>(max_length_);
  std::copy(arr.begin(), arr.end(), default_arr_.begin());

  std::sort(arr.begin(), arr.end());
  std::reverse(arr.begin(), arr.end());
  reversed_arr_ = std::vector<int>(max_length_);
  std::copy(arr.begin(), arr.end(), reversed_arr_.begin());

  std::sort(arr.begin(), arr.end());
  for (int i = 0; i < 50; ++i) {
    std::swap(arr[rnd() % max_length_], arr[rnd() % max_length_]);
  }
  almost_sorted_arr_ = std::vector<int>(max_length_);
  std::copy(arr.begin(), arr.end(), almost_sorted_arr_.begin());
}

std::vector<int> ArrayGenerator::GetRandomArr(int n) {
  return CopyPart(default_arr_, n);
}

std::vector<int> ArrayGenerator::GetReversedArr(int n) {
  return CopyPart(reversed_arr_, n);
}

std::vector<int> ArrayGenerator::GetAlmostSortedArr(int n) {
  return CopyPart(almost_sorted_arr_, n);
}

std::vector<int> ArrayGenerator::CopyPart(std::vector<int>& source, int n) {
  if (n > max_length_) {
    throw std::logic_error("The array length is too big");
  }
  std::vector<int> res(n);
  std::copy(source.begin(), source.begin() + n, res.begin());
  return res;
}
