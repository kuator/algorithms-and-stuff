#include <algorithm>
#include <bits/stdc++.h>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;

int distanceFromStation(vector<int> v, int number)
{
  int first = v[0];
  int last = v[v.size()-1];

  if (number < first) 
    return first - number;
  if (number > last) 
    return number - last;

  int lo = 0, hi = v.size() - 1;
  int mid;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    if (v[mid] == number) {
      return 0;
    }

    if (v[mid] < number)
      lo = mid + 1;

    else 
      hi = mid - 1;
  }

  if (v[lo] == number) {
    return 0;
  }
  else if (v[hi] == number) {
    return 0;
  }
  return min(abs(number - v[hi]), abs(number - v[lo]));
}

int flatlandSpaceStations(int n, vector<int> c) {
  sort(c.begin(), c.end());
  int max_distance = INT_MIN;
  for (int i = 0; i <n; i++)
    max_distance = max(distanceFromStation(c, i), max_distance);
  return max_distance;
}

int main (int argc, char *argv[])
{
  /* int result = flatlandSpaceStations(20, {13, 1, 11, 10, 6}); */
  int result = flatlandSpaceStations(95, {68,81,46,54,30,11,19,23,22,12,38,91,48,75,26,86,29,83,62});
  std::cout << result << std::endl;
  return 0;
}

