#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long strangeCounter(long t) {
  long n = 1L;
  while (true) {
    long cur_sum = 3*(pow(2,n)-1);
    long prev_sum = 3*(pow(2,n-1)-1);
    long time_at_chunk = 3 * pow(2, n-1);
    cout << n << " " << cur_sum << " " << prev_sum << " " << time_at_chunk << endl;
    if (t <= cur_sum) {
      long result = 1 + time_at_chunk - (t - prev_sum);
      return result;
    }
    n++;
  }
}

int main (int argc, char *argv[])
{
  cout << strangeCounter(1000000000000L);
  return 0;
}
