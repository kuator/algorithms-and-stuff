import java.util.Vector;

public class Percolation {

  class UnionFind {
    int[][] sizes;
    int[][] nodes;
    int size;

    public UnionFind(int n) {
      this.sizes = new int[n][n];
      this.nodes = new int[n][n];
      for (int j = 0; j < this.nodes.length; j++) 
        for (int i = 0; i < this.nodes.length; i++) 
          nodes[j][i] = -1;
      this.size = n;
    }

    public boolean isValidNode(int y, int x){
      if (x < 0 || x >= size) 
        return false;
      if (y < 0 || y >= size) 
        return false;
      System.out.println("valid j, i: " + y + "," + x);
      return true;
    }


    public void union(int firstNodePosition, int secondNodePosition){
      if (firstNodePosition == secondNodePosition) 
        return;
      int y1 = firstNodePosition/this.size;
      int x1 = firstNodePosition%this.size;
      int y2 = secondNodePosition/this.size;
      int x2 = secondNodePosition%this.size;
      int firstSize = sizes[y1][x1];
      int secondSize = sizes[y2][x2];
      int firstParent = findParent(firstNodePosition);
      int secondParent = findParent(secondNodePosition);
      if (firstSize <= secondSize) {
        nodes[y1][x1] = secondParent;
        sizes[y1][x1] +=secondSize;
        sizes[y2][x2] = 0;
      }
      if (firstSize > secondSize) {
        nodes[y2][x2] = firstParent;
        sizes[y1][x1] +=secondSize;
        sizes[y2][x2] = 0;
      }
    }

    public boolean isOpen(int position){
      int y = position/this.size;
      int x = position%this.size;
      return this.nodes[y][x] != -1;
    }

    public void open(int position){
      int y = position/this.size;
      int x = position%this.size;
      this.nodes[y][x] = position;
      
      Vector<Integer> openNodes = this.findOpenNeighbours(position);
      // for (int openNode : openNodes) 
      //   System.out.println(openNode/size + " : " +openNode%size );

      for (int openNode : openNodes) 
        union(openNode, position);
    }

    public Vector<Integer> findOpenNeighbours(int position){
      int y = position/this.size;
      int x = position%this.size;
      System.out.println("Position: " + position/size + "," + position%size);
      Vector<Integer> openNodes = new Vector<Integer>();

      System.out.println("y,x: " + y + "," + x);
      for (int j = y-1; j <= y+1; j++) {
        for (int i = x-1; i <= x+1; i++) {
          // System.out.println("j,i: " + j + "," + i);
        }
      }

      for (int j = y-1; j <= y+1; j++) {
        for (int i = x-1; i <= x+1; i++) {
          // System.out.println("j,i: " + j + "," + i);
          if (isValidNode(j, i) ){
            if (nodes[j][i]!=-1) {
              openNodes.add(j*this.size + i);
              System.out.println("Open: " + y + " " + x);
            }
          }
        }
      }
      return openNodes;
    }

    public int findParent(int firstNodePosition){
      int nodePosition = firstNodePosition;
      int y1 = nodePosition/this.size;
      int x1 = nodePosition%this.size;
      System.out.println(y1 + " : " + x1);

      while (nodes[y1][x1] != nodePosition) {
        nodePosition = nodes[y1][x1];
        y1 = nodePosition/this.size;
        x1 = nodePosition%this.size;
      }
      return nodePosition;
    }

    public boolean connected(int firstNodePosition, int secondNodePosition){
      int firstParent = findParent(firstNodePosition);
      int secondParent = findParent(secondNodePosition);
      return firstParent == secondParent;
    }

    public boolean isFull(int position) {
      for (int i = 0; i < this.size; i++) 
        if (this.nodes[0][i] != -1) 
          if (connected(i, position)) return true;

      return false;
    }

    public int openSitesCount() {
      int size = 0;
      for (int[] js : sizes) 
        for (int is : js) 
          size+=is;
      return size;
    }

    public boolean percolates() {
      for (int j = 0; j < this.size; j++) 
        for (int i = 0; i < this.size; i++) 
          if (this.connected(j, (this.size-1)*this.size+i))
            return true; 
      return false;
    }
  }

  public UnionFind uf;
  int size;
  // creates n-by-n grid, with all sites initially blocked
  public Percolation(int n) {
    this.size = n;
    this.uf = new UnionFind(n);
  }

  // opens the site (row, col) if it is not open already
  public void open(int row, int col){
    this.uf.open((row-1)*size+col-1);
  }

  // is the site (row, col) open?
  public boolean isOpen(int row, int col){
    return this.uf.isOpen((row-1)*size+col-1);
  }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
      return this.uf.isFull((row-1)*size+col-1);
    }

    // returns the number of open sites
    public int numberOfOpenSites(){
      return this.uf.openSitesCount();
    }

    // does the system percolate?
    public boolean percolates() {
      return this.uf.percolates();
    }

    // test client (optional)
    public static void main(String[] args) {
      Percolation p = new Percolation(3);
      p.open(1, 1);
      p.open(2, 1);
      // p.open(3, 1);
      System.out.println(p.percolates());
    }
}
