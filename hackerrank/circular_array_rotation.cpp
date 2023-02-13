#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
  vector<int> a_copy(a.size());
  vector<int> result(queries.size());
  for (int i = 0; i<a.size(); i++) {
    int diff = (i + k)%a.size();
    a_copy[diff] = a[i];
  }
  for (int i = 0; i<queries.size(); i++) 
    result[i] = a_copy[queries[i]];
  return result;
}

int main (int argc, char *argv[])
{
  return 0;
}
