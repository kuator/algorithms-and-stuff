#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <iostream>
using namespace std;

int designerPdfViewer(vector<int> h, string word) {
  int max_height = 0;
  for (char i : word)
    max_height = max(max_height, h[i-97]);
  return max_height * word.length();
}

int main (int argc, char *argv[])
{
  string word = "aelloworld";
  for (char i : word) {
    std::cout << i - 97 << std::endl;
  }
  /* cout << (int)'a'; */
  return 0;
}
