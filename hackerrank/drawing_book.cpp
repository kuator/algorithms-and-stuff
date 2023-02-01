#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

int pageCount(int n, int p) {
  int last = n / 2;
  int goal = p / 2;
  return min(goal, last-goal);
}

int main (int argc, char *argv[])
{
  cout << pageCount(6, 5);
  return 0;
}
