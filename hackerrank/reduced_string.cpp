#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

string superReducedString(string s) {
  stack<char>cache;
  cache.push(s[0]);
  for (int i = 1; i<s.size(); i++) {
    if (!cache.empty() && cache.top() == s[i]) {
      cache.pop();
      continue;
    }
    cache.push(s[i]);
  }
  string res = "";
  while(!cache.empty()) {
    char el = cache.top();
    cache.pop();
    res = el + res;
  }
  return res.empty() ? "Empty String" : res;
}

int main (int argc, char *argv[])
{
  cout << superReducedString("aaabbb");
  return 0;
}
