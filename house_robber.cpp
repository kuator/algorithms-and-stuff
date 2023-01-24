#include <algorithm>
#include <bits/stdc++.h>
#include <map>
using namespace std;

int count_better_rob(map<int, int>memo, vector<int>& nums, int end) {
  if (end < 0) 
    return 0;

  if (!memo.count(end-2))
    memo[end-2] = count_better_rob(memo, nums, end - 2);
  int first = nums[end] + memo[end-2];

  if (end - 1 < 0) 
    return first;

  if (!memo.count(end-3))
    memo[end-3] = count_better_rob(memo, nums, end - 3);
  int second = nums[end-1] + memo[end-3];

  return max(first, second);
}

int rob(vector<int>& nums) {
  map<int, int>memo;
  return count_better_rob(memo, nums, nums.size()-1);
}

int main (int argc, char *argv[])
{
  vector<int> vect = {2,7,9,3,1};
  int result = rob(vect);
  std::cout << result << std::endl;
  return 0;
}
