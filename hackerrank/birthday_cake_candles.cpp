#include <algorithm>
#include <bits/stdc++.h>
#include <map>
using namespace std;

int birthdayCakeCandles(vector<int> candles) {
  map<int, int>num_of_candels;
  for (int candle : candles) 
    num_of_candels[candle]++;
  sort(candles.begin(), candles.end(), std::greater<>());
  int tallest = candles[0];
  return num_of_candels[tallest];
}

int main (int argc, char *argv[])
{
  return 0;
}
