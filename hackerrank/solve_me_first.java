import java.io.*;
import java.util.*;

public class solve_me_first  {

  public static void main(String[] args) throws IOException {
    /*
     * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
     * class should be named Solution.
     */
    StreamTokenizer tf = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    tf.nextToken();
    int a = (int) tf.nval;
    tf.nextToken();
    int b = (int) tf.nval;
    System.out.println(a + b);
  }
}
