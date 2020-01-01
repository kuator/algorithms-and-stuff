#include <iostream>

int main(int argc, char *argv[])
{
  int tmp = 0;
  int number = 0;
  while(std::cin>>number){
    if(number < 0){
      tmp++;
    }
    else if(std::cin.eof()){
      break;
    }
  }
  std::cout << tmp << std::endl;
  return 0;
}
