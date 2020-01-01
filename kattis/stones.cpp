#include <iostream>

int main(int argc, char *argv[])
{
  int n;
  std::cin >> n;
  std::cout << (n % 2 ? "Alice" : "Bob") << std::endl;
  return 0;
}
