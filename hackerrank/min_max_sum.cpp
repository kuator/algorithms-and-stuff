#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

void miniMaxSum(vector<int> arr) {
  sort(arr.begin(), arr.end());
  vector<int> min_vec(arr.begin(), arr.begin() + 4);
  vector<int> max_vec(arr.end() - 4, arr.end());
  long min = std::accumulate(min_vec.begin(), min_vec.end(), 0L);
  long max = std::accumulate(max_vec.begin(), max_vec.end(), 0L);
  /* for (auto i : min_vec) */ 
  /*   std::cout << i << " "; */ 
  /* std::cout << endl; */ 
  /* for (auto i : max_vec) */ 
  /*   std::cout << i << " "; */ 
  std::cout << min << ' ' << max <<std::endl;
}

int main (int argc, char *argv[])
{
  
  miniMaxSum({256741038, 623958417, 467905213, 714532089, 938071625});
  return 0;
}
