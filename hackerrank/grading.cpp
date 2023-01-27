#include <bits/stdc++.h>
using namespace std;

int grade(int x) { 
  if (x < 38) return x;
  int closest_five = (x/5 + 1)*5;
  return closest_five - x < 3 ? closest_five : x;
}

vector<int> gradingStudents(vector<int> grades) {
  transform(grades.begin(), grades.end(), grades.begin(), grade);
  return grades;
}

int main(int argc, char *argv[]) { return 0; }
