#include <bits/stdc++.h>
int main(int argc, char *argv[])
{
  int hours, minutes;
  std::cin >> hours >> minutes;
  minutes -= 45;
  if(minutes < 0){
    hours--;
    minutes+=60;
  }
  if(hours<0){
    hours+=24;
  }
  std::cout << hours << " " << minutes << std::endl;
  return 0;
}
