#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
  sort(arr.begin(), arr.end());
  int lowest = arr[0];
  vector<int>result;
  while (arr.size()>0) {
    result.push_back(arr.size());
    transform(arr.begin(), arr.end(), arr.begin(), [lowest](int el) {return el - lowest;}); 
    std::vector<int>::iterator position = arr.begin();
    while (position != arr.end()) {
        arr.erase(position);
        position = std::find(arr.begin(), arr.end(), 0);
    }
    lowest = arr[0];
  }
  return result;
}

int main (int argc, char *argv[])
{
  return 0;
}
