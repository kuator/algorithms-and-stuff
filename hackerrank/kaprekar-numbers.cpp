#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void kaprekarNumbers(int p, int q) {
  bool is_invalid = true;
  for (long i = p; i <=q; i++) {
    int d = to_string(i).size();
    string number_string = to_string(i*i);
    long right = stoi(number_string.substr(number_string.size()-d, d));
    string left_string = number_string.substr(0, number_string.size()-d);
    long left = left_string.size() ? stoi(left_string): 0;
    if ((right + left) == i) {
      std::cout << i << " ";
      is_invalid = false;
    }
  }
  if (is_invalid)
    std::cout << "INVALID RANGE" << std::endl;
}

int main (int argc, char *argv[])
{
  kaprekarNumbers(1, 99999);
  return 0;
}
