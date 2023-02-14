#include <bits/stdc++.h>
using namespace std;

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c, int k) {
  int cumulative = 0;
  int i = 0;
  do {
    cumulative=cumulative + c[i]*2 +1;
    i = (i + k) % c.size();
  } while (i != 0);
  return 100 - cumulative;
}

int main (int argc, char *argv[])
{
  return 0;
}
