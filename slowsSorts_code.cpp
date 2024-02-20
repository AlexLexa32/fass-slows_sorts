#include <utility>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <iomanip>

std::vector<int64_t> sizes = {4, 10, 100, 400, 1000, 1200, 3000, 7500, 10000, 30000};

std::vector<int64_t> randVec(int64_t n) {
  std::random_device rd;
  std::mt19937_64 get(random());

  std::vector<int64_t> arr(n);
  for (auto &elm: arr) {
    elm = get();
  }

  std::shuffle(arr.begin(), arr.end(), rd);

  return arr;
}




std::pair<int64_t, int64_t> bubbleSort(std::vector<int64_t> arr) {
  int64_t i = (int64_t)arr.size() - 1;

  int64_t compare = 0;
  int64_t assigment = 0;

  while (true) {
    int64_t last = 0;
    for (int64_t j = 0; j < i; ++j) {
      ++compare;
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        ++assigment;
        last = j;
      }
    }

    i = last;
    if (i == 0) break;
  }

  return std::make_pair(compare, assigment);
}

std::pair<int64_t, int64_t> insertionBinSort(std::vector<int64_t> arr) {
  int64_t compare = 0;
  int64_t assigment = 0;

  for (int64_t i = 1; i < arr.size(); ++i) {
    int64_t lhs = -1, rhs = i;
    while (lhs + 1 < rhs) {
      int64_t mid = (lhs + rhs) / 2;
      ++compare;
      if (arr[mid] > arr[i]) {
        rhs = mid;
      } else {
        lhs = mid;
      }
    }

    std::reverse(arr.begin() + rhs, arr.begin() + i);
    std::reverse(arr.begin() + rhs, arr.begin() + i + 1);
    assigment += i - rhs + 1;
  }

  return std::make_pair(compare, assigment);
}

std::pair<int64_t, int64_t> selectionSort(std::vector<int64_t> arr) {
  int64_t compare = 0;
  int64_t assigment = 0;

  for (int64_t i = (int64_t)arr.size() - 1; i > 0; --i) {
    int64_t max_idx = 0;
    for (int64_t j = 0; j <= i; ++j) {
      ++compare;
      if (arr[j] > arr[max_idx]) {
        max_idx = j;
      }
    }

    if (max_idx >= i) {
      continue;
    }
    std::swap(arr[max_idx], arr[i]);
    ++assigment;
  }

  return std::make_pair(compare, assigment);
}

std::pair<int64_t, int64_t> insertionLinSort(std::vector<int64_t> arr) {
  int64_t compare = 0;
  int64_t assigment = 0;

  for (int64_t i = 1; i < arr.size(); ++i) {
    int64_t pos = i;
    for (int64_t j = 0; j < i; ++j) {
      ++compare;
      if (arr[i] < arr[j]) {
        pos = j;
        break;
      }
    }

    std::reverse(arr.begin() + pos, arr.begin() + i);
    std::reverse(arr.begin() + pos, arr.begin() + i + 1);
    assigment += i - pos + 1;
  }

  return std::make_pair(compare, assigment);
}

std::pair<int64_t, int64_t> cocktailSort(std::vector<int64_t> arr) {
    int64_t compare = 0;
    int64_t assigment = 0;
    int64_t lhs = 0, rhs = (int64_t)arr.size() - 1;
    int64_t iteration = 0;
    while (lhs != rhs) {
        if (iteration&1) {
            int64_t last = rhs;
            for (int64_t j = rhs; j > lhs; ++j) {
                ++compare;
                if (arr[j] < arr[j - 1]) {
                    std::swap(arr[j], arr[j - 1]);
                    ++assigment;
                    last = j;
                }
            }
            lhs = last;
        } else {
            int64_t last = lhs;
            for (int64_t j = lhs; j < rhs; ++j) {
                ++compare;
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    ++assigment;
                    last = j;
                }
            }
            rhs = last;
        }
        
    }
    return std::make_pair(compare, assigment);
}

int main() {
    for (int i = 0; i < 10; ++i) {
        int64_t r = 0;
        for (int j = 0; j < 7; ++j) {
            auto ans = cocktailSort(randVec(sizes[i]));
            r += ans.first;
            std::cout << ans.first << '\n';
        }
        std::cout << r/7 << '\n';
        std::cout << "\n";
    }
  return 0;
}
