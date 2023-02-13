#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> permutationEquation(vector<int> p) {
  vector<int>cache(p.size()+1); 
  vector<int>result; 
  for (int i = 0; i<p.size(); i++) 
    cache[p[i]] = i +1;
  sort(p.begin(), p.end());
  for (int el: p)
    result.push_back(cache[cache[el]]);
  return result;
}

int main (int argc, char *argv[])
{
  auto res = permutationEquation({5,2,1,3,4});
  for (int el : res) {
    std::cout << el << std::endl;
  }
  return 0;
}
