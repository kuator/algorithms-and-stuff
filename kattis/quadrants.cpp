#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
  int a,b, result;
  std::cin >> a >> b;
  if(a > 0 && b > 0){
    result = 1;
  } 
  else if(a < 0 && b > 0){
    result = 2;
  } 
  else if(a < 0 && b < 0){
    result = 3;
  } 
  else if(a > 0 && b < 0){
    result = 4;
  } 
  std::cout << result << std::endl;
  return 0;
}
