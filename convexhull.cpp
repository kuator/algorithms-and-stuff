// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;

  bool operator==(const Point& rhs)
  {
      return this->x == rhs.x && this->y == rhs.y;
  }
};

int crossProduct(Point current, Point next, Point checking)
{
  int x1 = checking.x - current.x;
  int y1 = checking.y - current.y;
  int y2 = next.y - current.y;
  int x2 = next.x - current.x;
  return x1 * y2 - x2 * y1;
}

bool comparePoint(Point i1, Point i2)
{
  if(i1.x == i2.x){
    return i1.y < i2.y;
  }
  return (i1.x < i2.x);
}


void convexHull(Point points[], int size)
{
  if(size == 3){
    for (int i = 0; i < 3; i++) {
      if(points[i].x == points[(i+1)%3].x && points[i].y == points[(i+1)%3].y){
        std::cout << -1 << std::endl;
        return;
      }
    }
  }
  if (size<3) {
    std::cout << -1 << std::endl;
    return;
  }
  vector<Point> hull;

  int leftMost = 0, current, next, checking;
  for (int i = 1; i < size; i++)
    if (points[i].x < points[leftMost].x)
      leftMost = i;

  current = leftMost;
  bool looped = true;
  while (looped) {
    hull.push_back(points[current]);
    next = (current + 1) % size;
    for (int i = 0; i < size; i++)
      if (crossProduct(points[current], points[next], points[i]) < 0)
        next = i;
    current = next;
    looped = current != leftMost;
  }

  sort(hull.begin(), hull.end(), comparePoint);
  hull.erase( unique( hull.begin(), hull.end() ), hull.end() );
  for (int i = 0; i < hull.size(); i++)
    cout << hull[i].x << " "
      << hull[i].y << (i != (hull.size() - 1) ? ", " : "\n");
}

// Driver program to test above functions
int main()
{
  /* int tests, pointsNumber; */
  /* std::cin >> tests ; */
  /* for (int i = 0; i < tests; i++) { */
  /*   std::cin >> pointsNumber; */
  /*   Point points[pointsNumber]; */
  /*   for (int j = 0; j < pointsNumber; j++) { */
  /*     int x, y; */
  /*     std::cin >> x >> y; */
  /*     points[j] = {x,y}; */
  /*   } */
  /*   convexHull(points, pointsNumber); */
  /* } */
  Point points[] = { { 778, 887 }, { 794, 916 }, { 387, 336 }, { 650, 493 }, { 363, 422 }, { 691, 28 }, { 764, 60 }, { 541, 927 }, { 173, 427 }, { 212, 737 }, { 568, 369 }, { 783, 430 }, { 863, 531 }, { 68, 124 } };
  int n = sizeof(points) / sizeof(points[0]);
convexHull(points, n);
return 0;
}
