#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

long taumBday(long b, long w, long bc, long wc, long z) {
  cout <<  b << ","<< w <<"," << bc <<","<< wc <<","<< z << endl;
  if (bc > wc) {
    bc = min(wc+z, bc);
  }
  if (bc < wc)
    wc = min(bc+z, wc);
  cout <<  w << "*"<< wc <<"+" << b <<"*"<< bc <<""<< "" << endl;
  return w*wc+b*bc;
}

int main (int argc, char *argv[])
{
  cout << taumBday(27984, 1402, 619246, 615589, 247954);
  return 0;
}
