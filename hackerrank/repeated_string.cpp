#include <bits/stdc++.h>
using namespace std;

long repeatedString(string s, long n) {
  long single_a_count = std::count(s.begin(), s.end(), 'a');
  long multiplier = n/s.size();
  long tail_size = n%s.size();
  string tail = s.substr(0, tail_size);
  long tail_a_count  = std::count(tail.begin(), tail.end(), 'a');
  return single_a_count*multiplier + tail_a_count;
}

int main (int argc, char *argv[])
{
  return 0;
}
