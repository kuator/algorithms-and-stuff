import java.util.ArrayList;
import java.util.List;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

public class BruteCollinearPoints {

  Point[] points;
  List<LineSegment> segments;

  public BruteCollinearPoints(Point[] points) {
    this.segments = new ArrayList<LineSegment>();
    this.points = new Point[points.length];
    for (int i = 0; i < points.length; i++) {
      for (int j = i; j < points.length; j++) {
        if (i == j) 
          continue;
        for (int k = 0; k < points.length; k++) {
          if (k == i || k == j) 
            continue;
          for (int l = 0; l < points.length; l++) { 
            if (l == j || l == k || i == l) 
              continue;
            if (
                points[i].compareTo(points[j]) == -1 &&
                points[j].compareTo(points[k]) == -1 &&
                points[k].compareTo(points[l]) == -1
              ) {
              double ikSlope = points[i].slopeTo(points[k]);
              double ijSlope = points[i].slopeTo(points[j]);
              double ilSlope = points[i].slopeTo(points[l]);
              if (ijSlope == ikSlope && ilSlope == ijSlope){
                Point min = points[i], max = points[l];
                segments.add(new LineSegment(min, max));
              }
            }
          }
        }
      }
    }
  }

  public int numberOfSegments() {
    return segments.toArray().length;
  }

  public LineSegment[] segments() {
    LineSegment[] arr = new LineSegment[segments.size()];
    arr = segments.toArray(arr);
    return arr;
  }

  public static void main(String[] args) {

      // read the n points from a file
      In in = new In(args[0]);
      int n = in.readInt();
      Point[] points = new Point[n];
      for (int i = 0; i < n; i++) {
          int x = in.readInt();
          int y = in.readInt();
          points[i] = new Point(x, y);
      }

      StdDraw.enableDoubleBuffering();
      StdDraw.setXscale(0, 32768);
      StdDraw.setYscale(0, 32768);
      for (Point p : points) {
          p.draw();
      }
      StdDraw.show();

      // print and draw the line segments
      BruteCollinearPoints collinear = new BruteCollinearPoints(points);
      for (LineSegment segment : collinear.segments()) {
          StdOut.println(segment);
          segment.draw();
      }
      StdDraw.show();
  }
}
