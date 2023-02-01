#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b) {
  vector<int>shared;
  bill.erase(bill.begin() + k);
  int total = accumulate(bill.begin(), bill.end(), 0);
  int anna_share = total/2;
  if (anna_share == b) 
    std::cout << "Bon Appetit" << std::endl;
  else
    std::cout << b - anna_share << std::endl;
}

int main (int argc, char *argv[])
{
  return 0;
}
