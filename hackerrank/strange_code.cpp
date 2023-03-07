#include <bits/stdc++.h>
using namespace std;

long strangeCounter(long t) {
  int value = 3;
  int time = 1;
  int value_cnt = value;
  for (int i = 1; i<=t; i++) {
    if (i==value+time) {
      value = value * 2;
      time = i;
      value_cnt = value;
      /* cout << i << " " << value_cnt << endl; */
    }
    /* cout << i << " " << value_cnt << endl; */
    if (i == t) {
      return value_cnt;
    }
    value_cnt--;
  }
  return value_cnt;
}

int main (int argc, char *argv[])
{
  cout << strangeCounter(1000000000000L);
  return 0;
}
