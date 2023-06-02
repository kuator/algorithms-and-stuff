import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
  private WeightedQuickUnionUF wuf;
  private int [] cells;
  private int openSites;
  private int top, bottom, n;
  public Percolation(int n) {
    this.n = n;
    this.cells = new int[n*n];
    top = n*n+1;
    bottom = n*n + 2;
    openSites = 0;

    this.wuf = new WeightedQuickUnionUF(n*n + 2);
  }

  private int getCellNumber(int row, int col) {
    row = row-1; 
    col = col-1; 
    return n*row + col;
  }

  private boolean isValidCell(int row, int col) {
    if (row < 1 || row > this.n || col < 1 || col > this.n) 
      return false;
    return true;
  }

  private void union(int row, int col, int neighbour) {
    int first = getCellNumber(row, col);
    wuf.union(first, neighbour);
    return;
  }

  private void connectWithOpenNeighbours(int row, int col){

    int [][] neighbours = new int[][]{
      {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    for (int k = 0; k < neighbours.length; k++) {
      int nRow = row+neighbours[k][0];
      int nCol = col+neighbours[k][1];
      if (!isValidCell(nRow, nCol) || !isOpen(nRow, nCol))
        continue;
      this.union(row, col, getCellNumber(nRow, nCol));
    }
  }

  public void open(int row, int col) {
    if (!isValidCell(row, col))
      throw new IllegalArgumentException("Values are out of range");
    if (isOpen(row, col))
      return;

    int cellNumber = getCellNumber(row, col);

    this.cells[cellNumber] = 1;
    openSites++;

    if (row == 1) 
      this.union(row, col, top-1);

    if (row == n) 
      this.union(row, col, bottom-1);

    this.connectWithOpenNeighbours(row, col);
  }

  public boolean isOpen(int row, int col){
    if (!isValidCell(row, col))
      throw new IllegalArgumentException("Values are out of range");
    int cellNumber = getCellNumber(row, col);
    return cells[cellNumber] == 1;
  }

  public boolean isFull(int row, int col){
    int cellNumber = getCellNumber(row, col);
    if (!isValidCell(row, col))
      throw new IllegalArgumentException("Values are out of range");
    if (!isOpen(row, col))
      return false;
    return wuf.find(cellNumber) == wuf.find(top-1);
  }

  public int numberOfOpenSites(){
    return openSites;
  }

  public boolean percolates() {
    return wuf.find(bottom-1) == wuf.find(top-1);
  }

  public static void main(String[] args) {
  }
}
