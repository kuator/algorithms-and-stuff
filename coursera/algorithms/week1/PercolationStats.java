import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

    private int size;
    private int trials;
    private double[] stats;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        if (n < 1 || trials < 1)
            throw new java.lang.IllegalArgumentException(
                    "Halt, n and trials must be greater than 0");

        this.trials = trials;
        size = n;
        stats = new double[trials];
        generateStats();
    }

    private void generateStats() {
        Percolation per;
        for (int i = 0; i < trials; ++i) {
            per = new Percolation(size);
            while (!per.percolates()) {
                per.open(StdRandom.uniformInt(1, size + 1), StdRandom.uniformInt(1, size + 1));
            }
            stats[i] = (double) per.numberOfOpenSites() / (size * size);
        }
    }

    public double mean() {
        return StdStats.mean(stats);
    }

    public double stddev() {
        return StdStats.stddev(stats);
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        return mean() - (1.96 * stddev()) / Math.sqrt(trials);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return mean() + (1.96 * stddev()) / Math.sqrt(trials);
    }

    public static void main(String[] args) {
    }
}
