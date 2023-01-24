#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
  int size = a.size();
  vector<int> res(2);
  for (int i = 0; i < size; i++) {
    res[0] = res[0] + (a[i] > b[i] ? 1 : 0);
    res[1] = res[1] + (b[i] > a[i] ? 1 : 0);
  }
  return res;
}

int main (int argc, char *argv[])
{
  vector<int>first = {1,2,3};
  vector<int>second = {1,2,3};
  return 0;
}

