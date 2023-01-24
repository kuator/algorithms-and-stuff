#include <bits/stdc++.h>
#include <vector>
using namespace std;

int simpleArraySum(vector<int> ar) {
  int acc{0};
  for(int el : ar)
    acc+=el;
  return acc;
}

int main (int argc, char *argv[])
{
  vector<int>vec = {1,2,3};
  std::cout << simpleArraySum(vec) << std::endl;
  return 0;
}
