#include <bits/stdc++.h>
using namespace std;

string appendAndDelete(string s, string t, int k) {
  if (s.size() + t.size() <= k) 
    return "Yes";

  int common = 0;
  for (int i = 0; i<min(s.size(),t.size()); i++) {
    if (s[i] != t[i])
      break;
    common++;
  }
  int diff = k - (s.size()-common + t.size()-common);
  if (diff<0) {return "No";}
  if (diff%2==0) {return "Yes";}
  return "No";
}

int main (int argc, char *argv[])
{
  cout << appendAndDelete("qwerasdf", "qwerbsdf", 6) << endl;
  return 0;
}
