#include <bits/stdc++.h>
using namespace std;

int viralAdvertising(int n) {
  int shared = 5, liked = 0, cumulative = 0, day = 1;
  while (day <=n) {
    liked = floor(shared/2);
    cumulative+=liked;
    shared = liked * 3;
    day++;
  }
  return cumulative;
}

int main (int argc, char *argv[])
{
  return 0;
}
