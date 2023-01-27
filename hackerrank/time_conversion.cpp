#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string timeConversion(string s) {
  string period = s.substr(s.size()-2, 2);
  string time = s.substr(0, s.size()-2);

  std::string delimiter = ":";
  std::string tmp_hour = time.substr(0, time.find(delimiter)); // token is "12"
  std::string minutes_seconds = time.substr(tmp_hour.length(), time.length() - tmp_hour.length());
  int hour = stoi(tmp_hour);
  
  string result;
  if (period == "AM"){
    string tmp_hour = to_string(hour % 12);
    int hour_length = tmp_hour.length();
    string hour = std::string(2 - std::min(2, hour_length), '0') + tmp_hour;
    result = hour + minutes_seconds;
  }
  if (period == "PM")
    result = to_string(hour % 12 + 12) + minutes_seconds;
  return result;
}

int main (int argc, char *argv[])
{
  cout << timeConversion("12:40:22AM");
  return 0;
}
