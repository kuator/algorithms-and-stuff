#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int squares(int a, int b) {
  int total = 0;
  for (int i = sqrt(a); i<=sqrt(b); i++)
    if (i*i >= a && i*i <=b)
      total++;
  return total;
}

int main (int argc, char *argv[])
{
  return 0;
}
