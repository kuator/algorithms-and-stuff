#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

bool all_factors(vector<int> arr, int factor) {
    for (int number : arr) 
      if (factor % number != 0) 
        return false;
    return true;
}

bool all_multiple(vector<int> arr, int multiple) {
  for (int number : arr) 
    if (number % multiple != 0) 
      return false;
  return true;
}

int getTotalX(vector<int> a, vector<int> b) {
  int min = *min_element(b.begin(), b.end());
  vector<int> factors;
  for (int i = 1; i <= min; i++) 
    if (min % i == 0) 
      factors.push_back(i);
  std::vector<int> result;
  std::copy_if(factors.begin(), factors.end(), std::back_inserter(result), [a, b](int i) {
      return all_factors(a, i) && all_multiple(b, i);
  });
  return result.size();
}

int main (int argc, char *argv[])
{
  std::cout << getTotalX({2, 4}, {16, 32, 96}) << std::endl;
}
