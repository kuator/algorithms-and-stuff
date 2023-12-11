import edu.princeton.cs.algs4.StdIn;

public class Permutation {
  public static void main(String[] args) {
    RandomizedQueue<String> randomizedQueue = new RandomizedQueue<>();
    int n = Integer.parseInt(args[0]);
    System.out.println(args[0]);
    for (int i = 0; i < n; i++) {
      var s = StdIn.readString();
      // System.out.println(s);
      randomizedQueue.enqueue(s);
    }
    for (String string : randomizedQueue) {
      System.out.println(string);
    }
  }
}
