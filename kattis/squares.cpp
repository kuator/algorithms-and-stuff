#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
  int a;
  int result = 1;
  int points = 2;
  std::cin >> a;
  for (int i = 0; i < a; ++i) {
    points +=result;
    result = result * 2;
  }
  std::cout << points*points << std::endl;
  return 0;
}
