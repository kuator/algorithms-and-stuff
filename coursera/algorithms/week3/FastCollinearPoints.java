import java.util.ArrayList;
import java.util.Arrays;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

/**
 * Class to find all segments containing 4 or more points in the given list of poitns
 */
public class FastCollinearPoints
{

  private LineSegment[] segments;

  /**
   * Finds all segments containing 4 or more points in the given list of points
   *
   * @param points - list of points to be analyzed
   */
  public FastCollinearPoints(Point[] points)
  {
    checkForNullPoints(points);
    Point[] pointsCopySO = Arrays.copyOf(points, points.length);
    Point[] pointsCopyNO = Arrays.copyOf(points, points.length);
    ArrayList<LineSegment> segmentsList = new ArrayList<LineSegment>();
    Arrays.sort(pointsCopyNO);
    checkForDuplicatedPoints(pointsCopyNO);
    for (int i = 0; i < pointsCopyNO.length; ++i)
    {
      Point origin = pointsCopyNO[i];
      Arrays.sort(pointsCopySO);
      Arrays.sort(pointsCopySO, origin.slopeOrder());
      int count = 1;
      Point lineBeginning = null;
      for (int j = 0; j < pointsCopySO.length - 1; ++j)
      {

        System.out.println("---------------------");
        System.out.println(origin);
        System.out.println(pointsCopySO[j]);
        System.out.println(pointsCopySO[j + 1]);
        System.out.println(pointsCopySO[j].slopeTo(origin));
        System.out.println(pointsCopySO[j + 1].slopeTo(origin));
        System.out.println(count);
        System.out.println("---------------------");
        if (pointsCopySO[j].slopeTo(origin) == pointsCopySO[j + 1].slopeTo(origin))
        {
          count++;
          System.out.println("===============");
          System.out.println(origin);
          System.out.println(lineBeginning);
          System.out.println(pointsCopySO[j]);
          System.out.println(pointsCopySO[j + 1]);
          System.out.println(pointsCopySO[j].slopeTo(origin));
          System.out.println(pointsCopySO[j + 1].slopeTo(origin));
          System.out.println(count);
          System.out.println("===============");
          if (count == 2)
          {
            lineBeginning = pointsCopySO[j];
            count++;
          }
          else if (count >= 4 && j + 1 == pointsCopySO.length - 1)
          {
            if (lineBeginning.compareTo(origin) > 0)
            {
              segmentsList.add(new LineSegment(origin, pointsCopySO[j + 1]));
            }
            count = 1;
          }
        }
        else if (count >= 4)
        {
          if (lineBeginning.compareTo(origin) > 0)
          {
            segmentsList.add(new LineSegment(origin, pointsCopySO[j]));
          }
          count = 1;
        }
        else
        {
          count = 1;
        }


      }

    }
    segments = segmentsList.toArray(new LineSegment[segmentsList.size()]);


  }

  /**
   * Returns the number of segments
   *
   * @return number of segments containing 4 or more points
   */
  public int numberOfSegments()
  {
    return segments.length;
  }

  /**
   * Returns array of segments that were discovered in the given points array
   *
   * @return array of discovered segments
   */
  public LineSegment[] segments()
  {
    return Arrays.copyOf(segments, numberOfSegments());
  }

  private void checkForDuplicatedPoints(Point[] points)
  {
    for (int i = 0; i < points.length - 1; ++i)
    {
      if (points[i].compareTo(points[i+1]) == 0)
      {
        throw new java.lang.IllegalArgumentException("Duplicated points");
      }
    }
  }

  private void checkForNullPoints(Point[] points)
  {
    for (int i = 0; i < points.length; ++i)
    {
      if (points[i] == null)
      {
        throw new java.lang.NullPointerException("At least one point in array is null");
      }
    }
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

      // draw the points
      StdDraw.enableDoubleBuffering();
      StdDraw.setXscale(0, 32768);
      StdDraw.setYscale(0, 32768);
      for (Point p : points) {
          p.draw();
      }
      StdDraw.show();

      // print and draw the line segments
      FastCollinearPoints collinear = new FastCollinearPoints(points);
      // StdOut.println(collinear.segments().length);
      for (LineSegment segment : collinear.segments()) {
          StdOut.println(segment);
          segment.draw();
      }
      StdDraw.show();
  }
}
