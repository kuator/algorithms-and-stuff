#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> stones(int n, int a, int b) {
  set<int>final_stones;
  for (int i = 0; i<n; i++)
    final_stones.insert(a*i + b*(n-i-1));
  vector<int>result = vector<int>(final_stones.begin(), final_stones.end());
  return result;
}

int main (int argc, char *argv[])
{
  auto res = stones(3, 1, 2);
  for (auto el : res) {
    cout << el << " ";
  }
  return 0;
}
