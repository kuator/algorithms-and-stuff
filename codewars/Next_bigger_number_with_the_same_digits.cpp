#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

long nextBigger(long n) {
  string number_string = to_string(n);
  sort(number_string.begin(), number_string.end(), std::greater<>());
  return n == stoi(number_string) ? -1:stoi(number_string);
}

int main (int argc, char *argv[])
{
  cout << nextBigger(12);
  return 0;
}
