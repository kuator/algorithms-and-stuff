#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

string organizingContainers(vector<vector<int>> container) {
  vector<int> containerBallsCount(container.size());
  vector<int> eachTypeBallsCount(container.size());
  for (size_t j =0; j<container.size(); j++) {
    for (size_t i =0; i<container[j].size(); i++) {
      containerBallsCount[j] += container[j][i];
      eachTypeBallsCount[i] += container[j][i];
      cout << container[j][i] << " ";
    }
  }
  sort(containerBallsCount.begin(), containerBallsCount.end());
  sort(eachTypeBallsCount.begin(), eachTypeBallsCount.end());
  return containerBallsCount == eachTypeBallsCount ? "Possible" : "Impossible";
}

int main (int argc, char *argv[])
{
  vector<vector<int>>arr = {{0,2}, {1,1}};
  cout << organizingContainers(arr);
  return 0;
}
