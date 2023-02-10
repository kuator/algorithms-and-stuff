#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

string angryProfessor(int k, vector<int> a) {
  vector<int>result;
  copy_if(a.begin(), a.end(), back_inserter(result), [](int k) { return k<=0; });
  return result.size() < k ? "YES": "NO";
}

int main (int argc, char *argv[])
{
  return 0;
}
