#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

string catAndMouse(int x, int y, int z) {
  if (abs(x - z) == abs(y-z)) return "Mouse C";
  return abs(x - z) < abs(y-z) ? "Cat A" : "Cat B";
}

int main (int argc, char *argv[])
{
  return 0;
}
