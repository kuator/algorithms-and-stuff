#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

void plusMinus(vector<int> arr) {
  int positive = accumulate(arr.begin(), arr.end(), 0,
                            [](int a, int b) { return b > 0 ? a + 1 : a; });
  int negative = accumulate(arr.begin(), arr.end(), 0,
                            [](int a, int b) { return b < 0 ? a + 1 : a; });
  int zero = accumulate(arr.begin(), arr.end(), 0,
                            [](int a, int b) { return b == 0 ? a + 1 : a; });
  int size = arr.size();
  std::cout << std::setprecision(6) << static_cast<float>(positive)/size << std::endl;
  std::cout << std::setprecision(6) << static_cast<float>(negative)/size << std::endl;
  std::cout << std::setprecision(6) << static_cast<float>(zero)/size << std::endl;
}

int main(int argc, char *argv[]) {
  plusMinus({-4, 3, -9, 0, 4, 1});
  return 0;
}
