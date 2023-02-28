#include <bits/stdc++.h>
#include <string>
using namespace std;

string fairRations(vector<int> B) {
  int loaves = 0;
  int odds = 0;
  for (int i =0; i<B.size(); i++) 
    if (B[i]%2 == 1) 
      odds++;
  if (odds%2 == 1) 
    return "NO";
  for (int i =0; i<B.size()-1; i++) {
    if (B[i]%2 == 1) {
      loaves+=2;
      B[i]++;
      B[i+1]++;
    }
  }
  return to_string(loaves);
}

int main (int argc, char *argv[])
{
  return 0;
}
