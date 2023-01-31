#include <bits/stdc++.h>
#include <map>
using namespace std;

int divisibleSumPairs(int n, int k, vector<int> arr) {
  int cnt = 0;
  for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = i + 1 ; j < arr.size(); j++) {
      if ((arr[i] + arr[j])% k ==0){
        cnt++;
      }
    } 
  } 
  return cnt;
}

int main (int argc, char *argv[])
{
  return 0;
}
