/* NOT SOLVED!!! */
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <map>
#include <vector>
using namespace std;

int get_from_map(map<int, int> cache, int key){
  return cache[key];
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
  map<int, int>cache;
  size_t i = 0, j = 0;
  int k = 1;
  reverse(player.begin(), player.end());
  while(i < ranked.size() && j <player.size()) {
    if (ranked[i] > player[j]) {
      std::cout << "ranked[i] > player[j]:"<< ranked[i] << " " << player[j] <<" " << k  << std::endl;
      cache[ranked[i]] = k;
      i++;
    }
    else if (ranked[i] < player[j]){
      std::cout << "ranked[i] < player[j]:"<< ranked[i] << " " << player[j]  <<" " << k << std::endl;
      cache[player[j]] = k;
      j++;
    }
    else if (ranked[i] == player[j]) {
      while (ranked[i] == player[j]) {
        std::cout << "ranked[i] == player[j]:"<< ranked[i] << " " << player[j] <<" " << k  << std::endl;
        cache[ranked[i]] = k;
        i++;
        j++;
      }
    }
    if (ranked[i] > player[j] && (i < ranked.size() -1) && ranked[i] == ranked[i+1]){
      std::cout << "i: " << i << " " <<"ranked[i] == player[i+1]:"<< ranked[i] << " " << ranked[i+1]  <<" " << k << std::endl;
      i++;
    }
    if (ranked[i] < player[j] && (j < player.size() -1) && player[j] == player[j+1]) {
      std::cout << "ranked[j] == player[j+1]:"<< ranked[j] << " " << player[j+1]  <<" " << k << std::endl;
      j++;
    }
    k++;
  }

  while(i < ranked.size()) {
    cache[ranked[i]] = k;
    i++;
    if ((i < ranked.size() -1) && ranked[i] == ranked[i+1])
      i++;
    k++;
  }


  while(j < player.size()) {
    cache[player[j]] = k;
    std::cout << "j:" << j  << " " << "ranked[j]: "<< ranked[j] << " " << k << std::endl;
    j++;
    if ((j < player.size() -1) && player[j] == player[j+1])
      j++;
    k++;
  }

  reverse(player.begin(), player.end());

  for (auto el : cache)
    std::cout << el.first << " " << el.second  << std::endl;
  transform(player.begin(), player.end(), player.begin(), [&cache](int score) -> int { return cache[score]; });
  return player;
}

int main (int argc, char *argv[])
{
  vector<int> ranked = {100, 90, 90, 80};
  vector<int> player = {70, 80, 105};
  vector<int>result = climbingLeaderboard(ranked, player);
  for (int el : result)
    std::cout << el << std::endl;
  return 0;
}
