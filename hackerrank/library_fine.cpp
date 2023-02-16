#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
  if (y1 - y2 > 0) return 10000;
  if (y1 - y2 < 0) return 0;
  if (m1 - m2 > 0) return (m1-m2)*500;
  if (m1 - m2 < 0) return 0;
  if (d1 - d2 > 0) return (d1-d2)*15;
  if (d1 - d2 < 0) return 0;
  return 0;
}

int main (int argc, char *argv[])
{
  return 0;
}
