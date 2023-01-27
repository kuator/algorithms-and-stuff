#include <bits/stdc++.h>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
  std::vector<int> apples_in_range, oranges_in_range;
  std::transform(apples.begin(), apples.end(), apples.begin(), [a](int i) {
      return i + a;
  });
  std::transform(oranges.begin(), oranges.end(), oranges.begin(), [b](int i) {
      return i + b;
  });
  std::copy_if(apples.begin(), apples.end(), std::back_inserter(apples_in_range), [s, t](int i) {
      return i >= s && i <=t;
  });
  std::copy_if(oranges.begin(), oranges.end(), std::back_inserter(oranges_in_range), [s, t](int i) {
      return i >= s && i <=t;
  });
  std::cout << apples_in_range.size() << std::endl;
  std::cout << oranges_in_range.size() << std::endl;
}

int main(int argc, char *argv[]) { return 0; }
