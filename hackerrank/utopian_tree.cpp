#include <bits/stdc++.h>
using namespace std;

int utopianTree(int n) {
  int height = 1;
  for (int i = 0; i<n; i++) 
    height = (i % 2 == 0) ? height *2: height +1;
  return height;
}

int main (int argc, char *argv[])
{
  return 0;
}
