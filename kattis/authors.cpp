#include <iostream>

int main(int argc, char *argv[])
{
  std::string str;
  getline(std::cin, str);
  std::string result;
  bool is_hyphen_previous_character = true;
  for (char i : str) {
    if(i == '-'){
      is_hyphen_previous_character = true;
      continue;
    }
    if(is_hyphen_previous_character){
      result += toupper(i);
      is_hyphen_previous_character = false;
    }
  }
  std::cout << result << std::endl;
  return 0;
}
