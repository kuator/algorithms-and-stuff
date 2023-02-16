/* TODO: not solved */
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int multiply(vector<int>a, int b){
  int carry = 0;
  vector<vector<int>> current;
  while (b>0) {
    int mul = b%10;
    int carry = 0;
    int i = 0;
    for (int i = a.size()-1; i>=0; i--) {
        current[i].insert(current[i].begin(), a[i] * mul + carry);
        carry = a[i]*mul/10;
    }
    if (carry) 
      current[i].insert(current[i].begin(), carry);

    i++;
    b = b/10;
  }
  vector<int> result;
  for (vector<int> el: current ) {
    int i = min(result.size()-1, el.size()-1);
    int carry = 0;
    while (i >=0) {
      result.insert(result.begin(), el[i] + result[i] + carry);
      i--;
    }
    if (result.size() - el.size() > 0) {
    }
  } 
}

void extraLongFactorials(int n) {
  vector<int>result;

  while (n>0) {
    result.insert(result.begin(), n%10);
    n = n/10;
  }

  int i = n-1;
  while (i>=1) {
    i--;
  }
}

int main (int argc, char *argv[])
{
  return 0;
}
