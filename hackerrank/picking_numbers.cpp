#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int pickingNumbers(vector<int> a) {
  map<int, int>cache;
  for (int el : a) 
    cache[el]++;

  int result = 0;
  for (auto const& item : cache){
    int key = item.first;
    int next = cache.count(key+1) > 0 ? cache[key+1] : 0;
    result = max(result, cache[key]+next);
  }
  return result;
}

int main (int argc, char *argv[])
{


  vector<int> array= { 4, 2, 3, 4, 4, 9, 98, 98, 3, 3, 3, 4, 2, 98, 1, 98, 98, 1, 1, 4, 98, 2, 98, 3, 9, 9, 3, 1, 4, 1, 98, 9, 9, 2, 9, 4, 2, 2, 9, 98, 4, 98, 1, 3, 4, 9, 1, 98, 98, 4, 2, 3, 98, 98, 1, 99, 9, 98, 98, 3, 98, 98, 4, 98, 2, 98, 4, 2, 1, 1, 9, 2, 4};
  /* pickingNumbers(array); */
  std::cout << pickingNumbers(array) << std::endl;
  return 0;
}
