#include <bits/stdc++.h> 
using namespace std; 
struct Point 
{ 
    int x, y; 
}; 
int crossProduct(Point a, Point b, Point c) {    
   int y1 = b.y - a.y;
   int y2 = c.y - a.y;
   int x1 = b.x - a.x;
   int x2 = c.x - a.x;
   return x2*y1 - y2*x1; 
}
void convexHull(Point points[], int n) 
{ 
    if (n < 3) return; 
    vector<Point> hull; 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
    int p = l, q; 
    do
    { 
        hull.push_back(points[p]); 
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           if (crossProduct(points[p], points[q], points[i]) < 0) 
               q = i; 
        } 
        p = q; 
    } while (p != l);  
    for (int i = 0; i < hull.size(); i++) 
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n"; 
} 
int main() 
{ 
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 
    int n = sizeof(points)/sizeof(points[0]); 
    convexHull(points, n); 
    return 0; 
}
