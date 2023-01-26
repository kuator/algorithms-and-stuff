#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void staircase(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0 ; j < n - 1 - i; j++) 
      std::cout << " ";
    for (int j = n - 1 - i; j < n; j++) 
      std::cout << "#";
    std::cout << '\n';
  }
}

int main (int argc, char *argv[])
{
  
  staircase(5);
  return 0;
}
