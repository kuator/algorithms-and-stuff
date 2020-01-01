#include <iostream>

int main(int argc, char *argv[])
{
  int x, tmp, n, result=0;
  std::cin >> x;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    result += tmp;
  }
  std::cout << x*(n+1)-result << std::endl;
  return 0;
}
