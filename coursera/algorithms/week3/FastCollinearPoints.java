import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

import java.util.Collections;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

public class FastCollinearPoints {
  Point[] points;
  List<LineSegment> segments;

  public FastCollinearPoints(Point[] points) {
    this.segments = new ArrayList<LineSegment>();
    this.points = new Point[points.length];
    Point[] tmp = new Point[4];
    for (int i = 0; i < points.length - 3; i++) {
      // Point point = new Point(points[, 0);
      Point point = points[i];
      Comparator<Point> pComparator = point.slopeOrder();
      Arrays.sort(points, 0, points.length, pComparator);
      for (int j = i + 1; j < points.length - 2; j++) {
        tmp = new Point[] {point, points[j], points[j+1], points[j+2]};
        Point min = Collections.min(Arrays.asList(tmp));
        Point max = Collections.max(Arrays.asList(tmp));
        double slope1 = point.slopeTo(points[j]);
        double slope2 = point.slopeTo(points[j+1]);
        double slope3 = point.slopeTo(points[j+2]);
        if (slope1 == slope2 && slope2 == slope3) 
          segments.add(segments.size(), new LineSegment(min, max));
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
