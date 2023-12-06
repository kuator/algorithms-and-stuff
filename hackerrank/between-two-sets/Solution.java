import static java.util.stream.Collectors.toList;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;

class Result {

  /*
   * Complete the 'getTotalX' function below.
   *
   * The function is expected to return an INTEGER.
   * The function accepts following parameters:
   * 1. INTEGER_ARRAY a
   * 2. INTEGER_ARRAY b
   */

  public static int getTotalX(List<Integer> a, List<Integer> b) {

    Integer max = a.stream().mapToInt(v -> v).max();
    Integer min = b.stream().mapToInt(v -> v).min().orElseThrow();
    IntStream result = IntStream.range(max, min + 1)
        .filter(e -> a.stream().allMatch(i -> e % i == 0) && b.stream().allMatch(i -> i % e == 0));
    return (int) result.count();
  }
}

/** hackerrrank */
public class Solution {
  /**
   * [TODO:description]
   *
   * @param args [TODO:parameter]
   * @throws IOException [TODO:throw]
   */
  public static void main(String[] args) throws IOException {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

    String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

    int n = Integer.parseInt(firstMultipleInput[0]);

    int m = Integer.parseInt(firstMultipleInput[1]);

    List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
        .map(Integer::parseInt)
        .collect(toList());

    List<Integer> brr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
        .map(Integer::parseInt)
        .collect(toList());

    int total = Result.getTotalX(arr, brr);

    bufferedWriter.write(String.valueOf(total));
    bufferedWriter.newLine();

    bufferedReader.close();
    bufferedWriter.close();
  }
}
