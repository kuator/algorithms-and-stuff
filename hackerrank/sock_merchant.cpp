#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
  map<int, int>socks_cache;
  int total = 0;
  for (int sock : ar) {
    if (socks_cache.count(sock) == 0) 
      socks_cache[sock] = 0;
    socks_cache[sock] = socks_cache[sock] + 1;
  }
  for (auto socks : socks_cache) {
    total+=socks.second/2;
  }
  return total;
}

int main (int argc, char *argv[])
{
  vector<int>socks =  {10, 20, 20, 10, 10, 30, 50, 10, 20};
  sockMerchant(socks.size(), socks);
  return 0;
}
