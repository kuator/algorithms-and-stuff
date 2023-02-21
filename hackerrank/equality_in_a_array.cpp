#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int equalizeArray(vector<int> arr) {
  int max_ = 0;
  int tmp = 1;
  sort(arr.begin(), arr.end());
  for (int i = 1; i< arr.size();i++) {
    if (arr[i] != arr[i-1]) {
      std::cout << arr[i] << " " << arr[i-1] << " " << tmp << " "<< max_ << std::endl;
      max_ = max(max_, tmp);
      tmp = 0;
    }
    std::cout << arr[i] << std::endl;
    tmp++;
  }
  max_ = max(max_, tmp);
  return arr.size()-max_;
}

int main (int argc, char *argv[])
{
  int result = equalizeArray({3, 3, 2, 1, 3});
  cout << result;
  return 0;
}
