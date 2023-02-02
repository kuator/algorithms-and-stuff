#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
  int result = -1;
  for (int k : keyboards) {
    for (int d : drives) {
      if (k + d <= b && k + d > result) {
        result = k+d;
        break;
      }
    }
  }
  return result;
}

int main (int argc, char *argv[])
{
  return 0;
}
