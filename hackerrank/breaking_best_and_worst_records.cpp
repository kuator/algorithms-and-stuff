#include <bits/stdc++.h>
using namespace std;

vector<int> breakingRecords(vector<int> scores) {
  int min_count{0}, max_count{0};
  int min = scores[0];
  int max = scores[0];
  for(int score : scores)
  {
     if (score < min) {
       min_count++;
       min = score;
     }
     if (score > max) {
       max_count++;
       max = score;
     }
  }
  return {max_count, min_count};
}

int main (int argc, char *argv[])
{
  return 0;
}
