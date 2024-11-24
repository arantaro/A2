#include "SortTester.h"

void SortTester::InsertionSort(std::vector<int>& arr) {
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = i - 1; j >= 0 && arr[j + 1] < arr[j]; --j) {
      std::swap(arr[j], arr[j + 1]);
    }
  }
}

std::vector<int> SortTester::CopyPart(const std::vector<int>& source, int l, int r) {
  std::vector<int> destination(r - l);
  for (int i = l; i < r; ++i) {
    destination[i - l] = source[i];
  }
  return destination;
}

void SortTester::MergeInsertionSort(std::vector<int>& arr, int switch_param) {
  if (arr.size() <= switch_param) {
    return InsertionSort(arr);
  }
  int n = static_cast<int>(arr.size());

  std::vector<int> left = CopyPart(arr, 0, n / 2);
  MergeInsertionSort(left, switch_param);
  std::vector<int> right = CopyPart(arr, n / 2, n);
  MergeInsertionSort(right, switch_param);

  for (int i = 0, j = 0; i < left.size() || j < right.size();) {
    if (j == right.size() || i != left.size() && left[i] <= right[j]) {
      arr[i++ + j] = left[i];
    } else {
      arr[i + j++] = right[j];
    }
  }
}

void SortTester::Sort() {
  int const cnt = 5;
  std::ofstream out;
  for (std::string folder_name : {"../random_array", "../almost_sorted_array", "../reversed_array"}) {
    for (int switching_param : {1, 5, 15, 30, 50, 100}) {
      out.open(folder_name + "/" + "switching_param = " + std::to_string(switching_param) + ".csv");
      for (int n = 500; n <= 10000; n += 100) {
        std::vector<int> arr;
        if (folder_name == "../random_array") {
          arr = arrayGenerator_.GetRandomArr(n);
        } else if (folder_name == "../almost_sorted_array") {
          arr = arrayGenerator_.GetAlmostSortedArr(n);
        } else if (folder_name == "../reversed_array") {
          arr = arrayGenerator_.GetReversedArr(n);
        }

        int64_t total = 0;
        for (int j = 0; j < cnt; j++) {
          std::vector<int> tmp(arr.size());
          std::copy(arr.begin(), arr.end(), tmp.begin());
          auto start = std::chrono::high_resolution_clock::now();
          MergeInsertionSort(tmp, switching_param);
          auto elapsed = std::chrono::high_resolution_clock::now() - start;
          int64_t sec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
          total += sec;
        }
        out << n << " " << static_cast<double>(total) / cnt << "\n";
      }
      out.close();
    }
  }
}
