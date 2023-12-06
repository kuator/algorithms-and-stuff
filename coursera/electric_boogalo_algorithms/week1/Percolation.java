import edu.princeton.cs.algs4.WeightedQuickUnionUF;

/**
 * @author: evakuator
 * @date: Dec 3, 2023
 * @description: Percolation
 */
public class Percolation {
  private WeightedQuickUnionUF uf;

  private WeightedQuickUnionUF ufTopOnly;
  private int num;
  private boolean[] opened;
  private int openedCount;

  /**
   * creates n-by-n grid, with all sites initially blocked
   *
   * @param num dimension
   * @throws throw new IllegalArgumentException(); must be in range
   */
  public Percolation(int num) {
    if (num <= 0) {
      throw new IllegalArgumentException();
    }

    this.uf = new WeightedQuickUnionUF(num * num + 2);
    this.ufTopOnly = new WeightedQuickUnionUF(num * num + 1);
    this.num = num;
    this.opened = new boolean[num * num + 2];
    this.opened[num * num] = true;
    this.opened[num * num + 1] = true;
    this.openedCount = 0;
  }


  private int xyTo1D(int row, int col) {
    return row * num + col;
  }

  private boolean isValidCell(int row, int col) {
    return (row >= 0 && row < num && col >= 0 && col < num);
  }

  private void connect(int first, int second) {
    this.uf.union(first, second);
  }

  private boolean isOpenedCell(int row, int col) {
    if (!this.isValidCell(row, col)) {
      throw new IllegalArgumentException();
    }
    return this.opened[xyTo1D(row, col)];
  }

  private void connectWithNeighbours(int row, int col) {
    if (row == 0) {
      this.connect(xyTo1D(row, col), this.num * this.num);
      this.ufTopOnly.union(xyTo1D(row, col), this.num * this.num);
    }
    if (row == num - 1) {
      this.connect(xyTo1D(row, col), this.num * this.num + 1);
    }

    int[][] neighbours = { { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 } };
    for (int i = 0; i < neighbours.length; i++) {
      var neighbour = neighbours[i];
      int neighRow = row + neighbour[0];
      int neighCol = col + neighbour[1];
      if (this.isValidCell(neighRow, neighCol)) {
        if (this.isOpenedCell(neighRow, neighCol)) {
          this.connect(xyTo1D(neighRow, neighCol), xyTo1D(row, col));
          this.ufTopOnly.union(xyTo1D(neighRow, neighCol), xyTo1D(row, col));
        }
      }
    }
  }

  private boolean areCellsConnected(int first, int second) {
    return this.uf.find(first) == this.uf.find(second);
  }

  /**
   * opens the site (row, col) if it is not open already
   *
   * @param row
   * @param col
   */
  public void open(int row, int col) {
    if (!this.isValidCell(row - 1, col - 1)) {
      throw new IllegalArgumentException();
    }

    if (this.isOpenedCell(row - 1, col - 1)) {
      return;
    }

    this.opened[xyTo1D(row - 1, col - 1)] = true;
    this.connectWithNeighbours(row - 1, col - 1);
    this.openedCount++;
  }

  // is the site (row, col) open?
  public boolean isOpen(int row, int col) {
    return isOpenedCell(row - 1, col - 1);
  }

  // is the site (row, col) full?
  public boolean isFull(int row, int col) {
    if (!this.isValidCell(row - 1, col - 1)) {
      throw new IllegalArgumentException();
    }
    return this.ufTopOnly.find(num * num) == this.ufTopOnly.find(xyTo1D(row - 1, col - 1));
  }

  // returns the number of open sites
  public int numberOfOpenSites() {
    return openedCount;
  }

  // does the system percolate?
  public boolean percolates() {
    return areCellsConnected(num * num + 1, num * num);
  }

  // test client (optional)
  public static void main(String[] args) {
    Percolation percolation = new Percolation(10);
    // System.out.println(x + " "+ y);
    // System.out.println();
    percolation.open(1, 1);
    percolation.open(2, 1);
    percolation.open(3, 1);
    percolation.open(4, 1);
    percolation.open(5, 1);
    percolation.open(6, 1);
    percolation.open(7, 1);
    percolation.open(8, 1);
    percolation.open(9, 1);
    // percolation.open(10, 1);
    System.out.println(percolation.percolates());
    System.out.println(percolation.isFull(9, 1));
  }
}
