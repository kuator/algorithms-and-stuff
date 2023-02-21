/* TODO: not solved */
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
  vector<int>freqs(k,0);
  for(int i = 0; i < s.size(); i++)
    freqs[s[i]%k]++;

  int result = min(freqs[0], 1);

  if (k%2==0)
    freqs[k/2]=min(freqs[k/2], 1);

  for(int i = 1; i <= k/2; i++){
    result+=max(freqs[i], freqs[k-i]);
    if (freqs[i] > freqs[k-i])
      std::cout << i << ":" << freqs[i] << std::endl;
    else
      std::cout << k-i << ":" << freqs[k-i] << std::endl;
  }
  return result;
}

int main (int argc, char *argv[])
{
  cout << nonDivisibleSubset(6, {3,4,5});
  return 0;
}
