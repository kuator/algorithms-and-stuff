#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int workbook(int n, int k, vector<int> arr) {
  int page = 1;
  int result = 0;
  for (auto problems_count: arr) {
    for (int j =0;j<ceil(static_cast<float>(problems_count)/k);j++) {
      for (int x = 1; x<=k; x++) {
        int problem = j*k + x;
        if (problem > problems_count) 
          break;
        if (problem == page)
          result++;
      }
      page++;
    }
  }
  return result;
}

int main (int argc, char *argv[])
{
  /* cout << workbook(15, 20, {1, 8, 19, 15, 2, 29, 3, 2, 25, 2, 19, 26, 17, 33, 22}); */
  cout << workbook(5, 3, {4, 2, 6, 1, 10});
  return 0;
}
