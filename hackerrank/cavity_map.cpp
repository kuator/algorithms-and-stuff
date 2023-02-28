#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

vector<string> cavityMap(vector<string> grid) {
  vector<tuple<int, int>> cache;
  for (int j = 1; j < grid.size() - 1; j++) 
    for (int i = 1; i < grid[j].size() - 1; i++) 
      if (grid[j][i] > grid[j - 1][i] && grid[j][i] > grid[j][i - 1] &&
          grid[j][i] > grid[j][i + 1] && grid[j][i] > grid[j + 1][i]) 
        cache.push_back(make_tuple(j, i));
  for (auto el : cache) 
    grid[get<0>(el)][get<1>(el)] = 'X';
  return grid;
}

int main(int argc, char *argv[]) {
  vector<string> result = cavityMap({"9999", "9999", "9999", "9999"});
  cout << endl;
  for (string el : result) {
    cout << el << endl;
  }
  return 0;
}
