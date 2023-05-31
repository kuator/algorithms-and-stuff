import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;


public class Percolation {
    WeightedQuickUnionUF wuf;
    int [][] cells;
    int n;
    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
      this.n = n;
      this.cells = new int[n][n];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
          this.cells[i][j] = 0;
      }
      this.wuf = new WeightedQuickUnionUF(n*n);
    }

    private boolean isValidCell(int row, int col) {
      // System.out.println(row +" "+col);
      if (row < 0 || row >= this.n || col < 0 || col >= this.n) 
        return false;
      return true;
    }

    private void connectWithOpenNeighbours(int row, int col){
      // System.out.println(row*this.n+col);
      // System.out.println(row +" "+col);
      // System.out.println(neighbours.length);

      int [][] neighbours = new int[][]{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
      };

      for (int k = 0; k < neighbours.length; k++) {
        int nRow = row+neighbours[k][0];
        int nCol = col+neighbours[k][1];
        if (!isValidCell(nRow, nCol))
          continue;
        if (!isCellOpen(nRow, nCol))
          continue;
        this.wuf.union(row*n+col, nRow*n+nCol);
      }


    }

    // // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
      int row_1 = row - 1, col_1 = col - 1;
      if (!isValidCell(row_1, col_1))
        throw new IllegalArgumentException();

      this.cells[row_1][col_1] = 1;
      this.connectWithOpenNeighbours(row_1, col_1);
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col){
      int row_1 = row - 1, col_1 = col - 1;
      return this.isCellOpen(row_1, col_1);
    }

    private boolean isCellOpen(int row, int col){
      return this.cells[row][col] == 1;
    }

    // // is the site (row, col) full?
    public boolean isFull(int row, int col){
      int row_1 = row - 1, col_1 = col - 1;
      for (int i = 0; i < this.n; i++) {
        if (this.wuf.find(i) == this.wuf.find(row_1*this.n+col_1))
          return true;
      }
      return false;
    }

    // // returns the number of open sites
    public int numberOfOpenSites(){
      int count = 0;
      for (int j = 0; j < cells.length; j++) {
        for (int i = 0; i < cells.length; i++)
          if (this.cells[j][i] == 1)
            count++;
      }
      return count;
    }

    // // does the system percolate?
    public boolean percolates() {
      for (int i = 0; i < this.n; i++) {
        if (isFull(n-1, i)) 
          return true;
      }
      return false;
    }

    public void print() {
      for (int j = 0; j < this.n; j++) {
        for (int i = 0; i < this.n; i++) {
          // System.out.print(this.wuf.find(j*this.n + i));
          System.out.print(this.cells[j][i]);
          System.out.print(" ");
        }
        System.out.println();
      }
    }

    public static void main(String[] args) {
      Percolation percolation = new Percolation(10);
      percolation.open(1, 1);
      percolation.open(2, 1);
      percolation.open(3, 1);
      percolation.open(3, 1);
      percolation.open(4, 1);
      percolation.open(5, 1);
      percolation.open(6, 1);
      percolation.open(7, 1);
      percolation.open(8, 1);
      percolation.open(9, 1);
      percolation.open(10, 1);
      percolation.print();
      System.out.println(percolation.percolates());
    }
}
