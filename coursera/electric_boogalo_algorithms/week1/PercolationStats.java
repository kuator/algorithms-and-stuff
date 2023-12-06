import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

/**
 * 
 * @author: evakuator
 * @date: Dec 3, 2023
 * @description: PercolationStats
 */
public class PercolationStats {

  private int trials;
  private double confidence = 1.96;
  private double[] results;

  
  /**
   * perform independent trials on an n-by-n grid
   *
   * @param n grid dimension
   * @param trials number of trials
   * @throws throw new IllegalArgumentException(); 
   */
  public PercolationStats(int n, int trials) {

    if (n <= 0 || trials <= 0) {
      throw new IllegalArgumentException();
    }

    this.trials = trials;
    this.results = new double[trials];

    for (int i = 0; i < trials; i++) {
      Percolation percolation = new Percolation(n);
      while (!percolation.percolates()) {
        int x = 1 + StdRandom.uniformInt(n);
        int y = 1 + StdRandom.uniformInt(n);
        percolation.open(x, y);
      }
      double opened = (double) percolation.numberOfOpenSites() / Math.pow(n, 2);
      this.results[i] = opened;
    }
  }

  // sample mean of percolation threshold
  public double mean() {
    return StdStats.mean(this.results);
  }

  // sample standard deviation of percolation threshold
  public double stddev() {
    return StdStats.stddev(this.results);
  }

  // low endpoint of 95% confidence interval
  public double confidenceLo() {
    return this.mean() - confidence * stddev() / Math.sqrt(this.trials);
  }

  // high endpoint of 95% confidence interval
  public double confidenceHi() {
    return this.mean() + confidence * stddev() / Math.sqrt(this.trials);
  }

  
  /**
   * test client (see below)
   *
   * @param args dimension and trials 
   */
  public static void main(String[] args) {
    int n = Integer.parseInt(args[0]);
    int trials = Integer.parseInt(args[1]);
    int total = n * n;
    PercolationStats percolationStats = new PercolationStats(n, trials);
    System.out.println("mean                    = " + percolationStats.mean() / total);
    System.out.println("stddev                  = " + percolationStats.stddev() / total);
    System.out.println("95% confidence interval =  [" + percolationStats.confidenceLo() / total + ", "
        + percolationStats.confidenceHi() / total + "]");
  }

}
