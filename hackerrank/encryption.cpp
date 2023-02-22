#include <bits/stdc++.h>
#include <cmath>
using namespace std;

string encryption(string s) {
  int ceiling = ceil(sqrt(s.size()));
  int bottom = floor(sqrt(s.size()));
  int col = bottom, row = bottom;
  if (col * row < s.size())
    col = ceiling;
  if (col * row < s.size())
    row = ceiling;
  string result = "";
  for (int j = 0; j < col; j++) {
    string tmp = "";
    for (int i = j; i < s.size(); i+=col) {
      tmp+=s[i];
    }
    result += j == 0 ? "" : " ";
    result += tmp;
  }
  return result;
}

int main(int argc, char *argv[]) {
  cout << encryption("feedthedog");
  return 0; 
}
