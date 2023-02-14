#include <bits/stdc++.h>
using namespace std;

int findDigits(int n) {
  int total = 0;
  int orig = n;
  for (; n!=0 ; n = n/10) {
    if (n%10 == 0) 
      continue;
    total+=(orig%(n%10) == 0);
  }
  return total;
}

int main (int argc, char *argv[])
{
  std::cout << findDigits(1012) << std::endl;
  return 0;
}
