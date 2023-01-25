#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
  int length = arr.size();
  int res = 0;
  for (int i = 0; i < length; i++) 
    res = res + arr[i][i] - arr[i][length-1-i];
  res = abs(res);
  return res;
}

int main (int argc, char *argv[])
{
  vector<int>first = {1,2,3};
  vector<int>second = {1,2,3};
  return 0;
}
