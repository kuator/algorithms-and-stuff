import edu.princeton.cs.algs4.UF;

public class Percolation {
  UF uf;
  int n;
  boolean[] opened;

  // creates n-by-n grid, with all sites initially blocked
  public Percolation(int n){
    this.uf = new UF(n*n + 2);
    this.n = n;
    this.opened = new boolean[n*n+2];
    this.opened[n*n] = true;
    this.opened[n*n+1] = true;
  }

  private int xyTo1D(int row, int col){
    return row * n + col;
  }

  private boolean isValidCell(int row, int col) {
    if (row < 0 || row >= n || col< 0 || col>=n) 
      return false;
    return true;
  }

  private void connect(int first, int second) {
    this.uf.union(first, second);
  }

  private boolean isOpenedCell(int row, int col){
    if (!this.isValidCell(row, col)) 
      throw new IllegalArgumentException();
    return this.opened[xyTo1D(row, col)];
  }

  private void connectWithNeighbours(int row, int col) {
    if (row == 0) {
      System.out.print(row);
      System.out.print(":");
      System.out.print(col);
      this.connect(xyTo1D(row, col), this.n*this.n);
    }
    if (row == n - 1) {
      System.out.print(row);
      System.out.print(":");
      System.out.print(col);
      this.connect(xyTo1D(row, col), this.n*this.n+1);
    }

    int[][] neighbours = {{-1,0 }, {0,1}, {0, -1}, {1,0}};
    for (int i = 0; i < neighbours.length; i++) {
      var neighbour  = neighbours[i];
      int nRow = row + neighbour[0];
      int nCol = col + neighbour[1];
      if (this.isValidCell(nRow, nCol)) 
        if (this.isOpen(nRow+1, nCol+1)) 
          this.connect(xyTo1D(nRow, nCol), xyTo1D(row, col));
    }
  }

  private boolean connected(int first, int second){
    return this.uf.find(first) == this.uf.find(second);
  }

  // opens the site (row, col) if it is not open already
  public void open(int row, int col) throws IllegalArgumentException{
    if (!this.isValidCell(row-1,col-1)) 
      throw new IllegalArgumentException();

    this.opened[xyTo1D(row-1,col-1)] = true;
    this.connectWithNeighbours(row-1, col-1);

  }

  // is the site (row, col) open?
  public boolean isOpen(int row, int col){
    return isOpenedCell(row-1, col-1);
  }

  // is the site (row, col) full?
  public boolean isFull(int row, int col){
    if (!this.isValidCell(row-1,col-1)) 
      throw new IllegalArgumentException();
    return this.connected(this.n*this.n, xyTo1D(row-1, col-1));
  }

  // returns the number of open sites
  public int numberOfOpenSites(){
    int result = 0;
    for (int i = 0; i < n*n; i++)
      if (opened[i]) {
        System.out.println(i);
        result++;
      }
    return result;
  }

  public void print() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(this.opened[i*n+j] ? "1" : 0);
        System.out.print(" ");
      }
      System.out.println();
    }
  }

  // does the system percolate?
  public boolean percolates(){
    return connected(n*n+1, n*n);
  }

  // test client (optional)
  public static void main(String[] args) {
    Percolation percolation = new Percolation(10);
    percolation.open(1, 1);
    percolation.open(2, 1);
    percolation.open(3, 1);
    percolation.open(4, 1);
    percolation.open(5, 1);
    percolation.open(6, 1);
    percolation.open(7, 1);
    percolation.open(8, 1);
    percolation.open(9, 1);
    percolation.open(9, 2);
    percolation.open(10, 2);
    // percolation.open(10, 1);
    int numberOfOpenSites = percolation.numberOfOpenSites();
    percolation.print();
    System.out.println(numberOfOpenSites);
    System.out.println(percolation.percolates());
  }
}
