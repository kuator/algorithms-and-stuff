#include <bits/stdc++.h>
using namespace std;

long aVeryBigSum(vector<long> ar) {
   long sum_of_elems = std::accumulate(ar.begin(), ar.end(), 0L);
   return sum_of_elems;
}

int main (int argc, char *argv[])
{
  vector<long>first = {1000000001, 1000000002, 1000000003, 1000000004, 1000000005};
  std::cout << aVeryBigSum(first) << std::endl;
  return 0;
}
