public class Board {

  // create a board from an n-by-n array of tiles,
  // where tiles[row][col] = tile at (row, col)
  private int[][] tiles;
  public Board(int[][] tiles){
    for (int i = 0; i < tiles.length; i++) {
      for (int j = 0; j < tiles.length; j++) {
        this.tiles[j][i] = tiles[j][i];
      }
    }
  }

  // string representation of this board
  public String toString(){
    return "";
  }

  // board dimension n
  public int dimension() {
    return 1;
  }

  // number of tiles out of place
  public int hamming() {
    return 2;
  }

  // sum of Manhattan distances between tiles and goal
  public int manhattan(){
    return 3;
  }

  // is this board the goal board?
  public boolean isGoal(){
    return false;
  }

  // does this board equal y?
  public boolean equals(Object y){
    return true;
  }

  // all neighboring boards
  public Iterable<Board> neighbors(){
    return new Iterable<Board>();
  }

  // a board that is obtained by exchanging any pair of tiles
  public Board twin(){
    return new Board();
  }

  // unit testing (not graded)
  public static void main(String[] args){
  }
}
