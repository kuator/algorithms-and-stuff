#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

int number_reversed(int num){
  int reversed = 0;
  while (num > 0) {
    reversed = 10*reversed + num % 10;
    num = num/10;
  }
  return reversed;
}

int beautifulDays(int i, int j, int k) {
 vector<int>days(j-i+1, 0);
 vector<int>result;
 std::iota(days.begin(), days.end(), i);
 copy_if(days.begin(), days.end(), back_inserter(result), [k](int day) { 
  return abs(number_reversed(day) -day) % k == 0; 
 });
 return result.size();
}

int main (int argc, char *argv[])
{
  return 0;
}
