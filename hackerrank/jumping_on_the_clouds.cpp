#include <bits/stdc++.h>
#include <vector>
using namespace std;

int jumpingOnClouds(vector<int> c) {
  int accumulator = 0;
  for (int i = 0; i< c.size()-1;) {
    if (i+2 <c.size() && c[i+2] == 0) {
      /* std::cout << i << ":" << c[i] << std::endl; */
      accumulator++;
      i+=2;
      continue;
    }
    /* std::cout << i << ":" << c[i] << std::endl; */
    accumulator++;
    i++;
  }
  return accumulator;
}

int main (int argc, char *argv[])
{
  /* vector<int>arr = {0, 0, 1, 0, 0, 1, 0}; */
  /* int result = jumpingOnClouds(arr); */
  /* std::cout << result << std::endl; */
  return 0;
}
