import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class PercolationStats {

  public static String padLeft(String s, int n) {
      return String.format("%" + n + "s", s);  
  }
  // perform independent trials on an n-by-n grid
  int trials;
  int size;
  int[] results;
  public PercolationStats(int n, int trials) {
    this.trials = trials;
    this.size = n;
    this.results = new int[trials];
    for (int i = 0; i < trials; i++) {
      Percolation percolation = new Percolation(n);
      while (!percolation.percolates()) {
        // for (int j = 0; j < this.size; j++) {
        //   for (int j2 = 0; j2 < this.size; j2++) {
        //     String character = percolation.uf.nodes[j][j2] != -1 ? ""+percolation.uf.findParent(j*size+j2) : " ";
        //     System.out.print(padLeft(character, 3) + " ");
        //     // System.out.print(percolation.uf.nodes[0][0]);
        //     // if (percolation.uf.nodes[j][j2] != -1){
        //     // }
        //   }
        //   System.out.println();
        // }
        // System.out.println();
        int y = 1+StdRandom.uniformInt(n);
        int x = 1+StdRandom.uniformInt(n);
        // while (true) {
        System.out.println(i);
        System.out.println(y + " : " + x);
        //   if (!percolation.isOpen(y, x))
        //     break;
        //   y = 1+StdRandom.uniformInt(n);
        //   x = 1+StdRandom.uniformInt(n);
        // }

        percolation.open(y, x);
      }
      results[i] = percolation.numberOfOpenSites();
    }
  }

  // sample mean of percolation threshold
  public double mean() {
        return StdStats.mean(this.results)/ Math.pow(this.size,2);
  }

  public double stddev() {
        return StdStats.stddev(this.results);
  }

  // low endpoint of 95% confidence interval
  public double confidenceLo() {
        return mean() - (1.96 * stddev()) / Math.sqrt(size);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return mean() + (1.96 * stddev()) / Math.sqrt(size);
    }

  // test client (see below)
  public static void main(String[] args){
    int n = Integer.parseInt(args[0]);
    int trials = Integer.parseInt(args[1]);
    PercolationStats percolationStats = new PercolationStats(n, trials);
    System.out.println(percolationStats.mean());
    System.out.println(percolationStats.stddev());
    System.out.println(percolationStats.confidenceLo());
    System.out.println(percolationStats.confidenceHi());
  }
}
