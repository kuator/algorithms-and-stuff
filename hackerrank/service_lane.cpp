#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> serviceLane(int n, vector<vector<int>> cases, vector<int>width) {
  vector<int>result;
  for (vector<int> c : cases) 
    result.push_back(*min_element(width.begin() + c[0], width.begin() + c[1] + 1));
  return result; 
}

int main (int argc, char *argv[])
{
  vector<int>result = serviceLane(5, {{2,3}, {1,4}, {2,4}, {2,4}, {2,3}}, {1,2,2,2,1});
  for (auto r : result) {
    cout << r << endl;
  }
  return 0;
}
