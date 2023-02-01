#include <bits/stdc++.h>
#include <map>
#include <stack>
#include <vector>
using namespace std;

int countingValleys(int steps, string path) {
  int uphills = 0;
  int downhills = 0;
  int sea_level = 0; 
  int valleys_cnt= 0; 
  for (int i = 0; i<path.size(); i++) {
    if (path[i] == 'U') {
      sea_level+=1;
      uphills++;
      if (sea_level == 0 && (uphills == downhills)) {
        valleys_cnt++;
        uphills = 0;
        downhills = 0;
      }
    }
    else if(path[i] == 'D') {
      sea_level-=1;
      downhills++;
      if (sea_level == 0 && (uphills == downhills)) {
        uphills = 0;
        downhills = 0;
      }
    }
  }
  return valleys_cnt;
}

int main (int argc, char *argv[])
{
  cout << countingValleys(8, "UDDDUDUU");
  return 0;
}
