#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

int chocolateFeast(int n, int c, int m) {
  int bars = n/c;
  int total = bars;
  int wrappers = 0;
  while (bars>0) {
    cout << bars << " " << wrappers << endl;
    int new_bars = (wrappers+bars)/m;
    total += new_bars;
    wrappers=(wrappers+bars)%m;
    bars = new_bars;
  }
  return total;
}

int main (int argc, char *argv[])
{
  cout << chocolateFeast(7, 3, 2);
  /* 7 3 2 */

  /* bars = 2 */
  /* bars = 1, wrappers=0*/

  /* 6 2 2; */
  /* 6/2=3; */
  /* bars=3/2=1 wrappers=3%2=1 */
  return 0;
}
