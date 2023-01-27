#include <bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
  float distance = x2 -x1;
  float velocity = v1 - v2;
  float f_time = distance/velocity;
  int i_time = distance/velocity;
  return f_time > 0 && f_time == i_time ? "YES" : "NO";
}

int main (int argc, char *argv[])
{
  float distance = 10;
  float velocity = 3;
  float f_time = distance/velocity;
  int i_time = distance/velocity;
  std::cout << i_time << std::endl;
  std::cout << f_time << std::endl;
  std::cout << (f_time == i_time) << std::endl;
  return 0;
}
