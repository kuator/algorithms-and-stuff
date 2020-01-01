#include <iostream>

int main(int argc, char *argv[])
{
  int arr[6] = {1, 1, 2, 2,2,8 };
  for (int i = 0; i < 6; ++i) {
    int piece = 0;
    std::cin >> piece;
    std::cout << arr[i] - piece << std::endl;
  }
  return 0;
}
