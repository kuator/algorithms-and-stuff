/* *****************************************************************************
 *  Name:              Johanna Mesa Ramos
 *  Coursera User ID:  c02b4bb527298de170192d644483baeb
 *  Last modified:     06/07/2020
 *  Course: Algorithms, Part I https://www.coursera.org/learn/algorithms-part1
 **************************************************************************** */

import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

    private Percolation perc;
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
                per.open(StdRandom.uniform(1, size + 1), StdRandom.uniform(1, size + 1));
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
        PercolationStats ps = new PercolationStats(Integer.parseInt(args[0]),
                                                   Integer.parseInt(args[1]));

        System.out.format("mean                    = %.16f %n", ps.mean());
        System.out.format("sttdev                  = %.16f %n", ps.stddev());
        System.out.format("95%% confidence interval = [%.16f, %.16f] %n", ps.confidenceLo(),
                          ps.confidenceHi());
    }
}
