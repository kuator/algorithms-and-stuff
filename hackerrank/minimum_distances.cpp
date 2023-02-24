#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

int minimumDistances(vector<int> a) {
  map<int, vector<int>> cache;
  for (int i =0; i<a.size(); i++)
    cache[a[i]].push_back(i);
  int min_diff = INT_MAX;
  for (auto el : cache) {
    int diff = INT_MAX;
    for (int i = 1; i<el.second.size(); i++)
      diff = min(el.second[i] - el.second[i-1], diff);
    min_diff = min(min_diff, diff);
  }
  return min_diff == INT_MAX ? -1 : min_diff;
}

int main (int argc, char *argv[])
{
  cout << minimumDistances({3,2,1,2,3});
  return 0;
}
