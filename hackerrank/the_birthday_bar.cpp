#include <bits/stdc++.h>
using namespace std;

int birthday(vector<int> s, int d, int m) {
  int total = 0;
  for (int i = 0; i <= s.size() - m; i++) {
    int sum = 0;
    for (int j = i; j<i+m; j++)
      sum+=s[j];
    if (sum == d)
      total++;
  }
  return total;
}

int main (int argc, char *argv[])
{
  cout << birthday({4}, 4, 1);
  return 0;
}
