import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

/*from  ja  v a  2  s . co m*/
public class Main {

  public static void main(String[] av) throws IOException {
    StreamTokenizer tf = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    int i;

    while ((i = tf.nextToken()) != StreamTokenizer.TT_EOF) {
      System.out.println("adfadfasdf");
      switch (i) {
        case StreamTokenizer.TT_EOF:
          System.out.println("End of file");
          break;
        case StreamTokenizer.TT_EOL:
          System.out.println("End of line");
          break;
        case StreamTokenizer.TT_NUMBER:
          System.out.println("Number " + tf.nval);
          break;
        case StreamTokenizer.TT_WORD:
          System.out.println("Word, length " + tf.sval.length() + "->" + tf.sval);
          break;
        default:
          System.out.println("What is it? i = " + i);
      }
    }
  }
}
