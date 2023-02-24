#include <bits/stdc++.h>
#include <cmath>
#include <map>
using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
  map<int, int> cache;
  int total = 0;
  for (int i =0; i< arr.size(); i++) {
    if (cache.count(arr[i]-d) && cache.count(arr[i]-2*d)) 
      total+= cache[arr[i]-d] * cache[arr[i]-2*d];
    cache[arr[i]] = cache[arr[i]]+1;
  }
  return total;
}

int main (int argc, char *argv[])
{
  cout << beautifulTriplets(3, {1, 6, 7, 7, 8, 10, 12, 13, 14, 19});
  return 0;
}

