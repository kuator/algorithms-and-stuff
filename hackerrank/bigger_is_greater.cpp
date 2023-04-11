#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string biggerIsGreater(string w) {
  int i = w.size()-1;
  int j = -1;
  bool running = true;
  int r = -1;
  int l = -1;
  for (; i>=1 && running; i--) {
    for (j = i-1; j>=0; j--) {
      if (w[j] < w[i]) {
        std::cout << w[l] << " " << w[r] << std::endl;
        r = i;
        l = j;
        running = false;
        break;
      }
    }
  }
  if (j < 0) 
    return "no answer";

  std::swap(w[l], w[r]);
  sort(w.begin() + l + 1, w.end());
  return w;
}

int main (int argc, char *argv[])
{
  cout << biggerIsGreater("dmsym");
  /* fstream input; */
  /* fstream output; */
  /* input.open("input.txt",ios::in); //open a file to perform read operation using file object */
  /* output.open("output.txt",ios::in); //open a file to perform read operation using file object */
  /* if (input.is_open()){ //checking whether the file is open */
  /*    string in; */
  /*    string out; */
  /*    while(getline(input, in) && getline(output, out)){ //read data from file object and put it into string. */
  /*      if (biggerIsGreater(in) != out) { */
  /*        cout << in << " " << biggerIsGreater(in) << " " << out << "\n"; //print the data of the string */
  /*        break; */
  /*      } */
  /*    } */
  /*    input.close(); //close the file object. */
  /*    output.close(); //close the file object. */
  /* } */
  return 0;
}
