#include <bits/stdc++.h>
#include <string>
using namespace std;

string pad_number(string number, int length_with_zeroes){
  auto new_str = std::string(length_with_zeroes - std::min(length_with_zeroes, (int)number.length()), '0') + number;
  return new_str;
}

bool is_gregorian_leap_year(int year){
  if (year % 4 != 0) 
    return false;
  if (year % 100 == 0)
    if (year % 400 != 0) 
      return false;
  return true;
}

string dayOfProgrammer(int year) {
  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool is_julian = year <= 1917;
  bool is_gregorian = year >= 1919;
  int programmer_day = 256;
  int month = 0;
  days[2] = year == 1918 ? days[2] - 13 : days[2];
  days[2] = is_julian && (year % 4 == 0) ? days[2] + 1: days[2];
  days[2] = is_gregorian && is_gregorian_leap_year(year) ? days[2] + 1: days[2];
  for (int i = 0; i < days.size(); i++) {
    if (programmer_day > days[i]) 
      programmer_day-=days[i];
    else {
      month = i + 1;
      break;
    }
  }
  string result = pad_number(to_string(programmer_day), 2) + "." + pad_number(to_string(month), 2) +"."+ to_string(year);
  return result;
}

int main (int argc, char *argv[])
{
  return 0;
}
