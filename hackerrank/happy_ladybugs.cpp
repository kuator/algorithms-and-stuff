#include <bits/stdc++.h>
#include <map>
using namespace std;

string happyLadybugs(string b) {
  map<char, int>cache; 
  int no_neighbours = 0;
  for (int i = 0; i<b.size();i++) {
    if (i == 0 && b[i] != b[i+1]) 
      no_neighbours++; 
    else if (i == (b.size()-1) && b[i] != b[i-1]) 
      no_neighbours++; 
    else if (b[i-1] != b[i] && b[i+1] != b[i]) 
      no_neighbours++; 
    cache[b[i]]++;
  }
  for (auto el : cache) {
    if (el.first == '_') 
      continue;
    if (el.second <= 1) 
      return "NO";
  }
  if (cache['_'] == 0) 
    if (no_neighbours > 0) 
      return "NO";
  return "YES";
}

int main (int argc, char *argv[])
{
  cout << happyLadybugs("RBY_YBR") << " " << endl;
  cout << happyLadybugs("X_Y__X")<< " " << endl;
  cout << happyLadybugs("__")<< " " << endl;
  cout << happyLadybugs("B_RRBR")<< " " << endl;
  return 0;
}
