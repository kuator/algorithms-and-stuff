#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

int hurdleRace(int k, vector<int> height) {
  sort(height.begin(), height.end(), greater<int>());
  int max_height = height[0];
  return max_height > k ? max_height - k : 0;
}

int main (int argc, char *argv[])
{
  return 0;
}
