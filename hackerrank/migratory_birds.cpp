#include <bits/stdc++.h>
#include <vector>
using namespace std;

int migratoryBirds(vector<int> arr) {
  sort(arr.begin(), arr.end());
  int max{0}, tmp{0};
  int sighting{-1}, max_sighting{-1};

  for (int el : arr) {
    if (el != sighting) {
      if (tmp > max) {
         max = tmp;
         max_sighting = sighting;
      }
      tmp = 0;
      sighting = el;
    }
    tmp++;
  }
  if (tmp > max) {
     max = tmp;
     max_sighting = sighting;
  }
  cout << endl;
  return max_sighting;
}

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main (int argc, char *argv[])
{
  // Create a text string, which is used to output the text file
  string myText;
  // Read from the text file
  ifstream MyReadFile("/home/evakuator/Downloads/input02.txt");

  string arr_count_temp;
  getline(MyReadFile, arr_count_temp);

  int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

  string arr_temp_temp;
  getline(MyReadFile, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(arr_count);

  for (int i = 0; i < arr_count; i++) {
      int arr_item = stoi(arr_temp[i]);

      arr[i] = arr_item;
  }

  std::cout << migratoryBirds(arr) << std::endl;
  return 0;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
