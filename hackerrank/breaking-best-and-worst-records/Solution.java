import static java.util.stream.Collectors.joining;
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
   * Complete the 'breakingRecords' function below.
   *
   * The function is expected to return an INTEGER_ARRAY.
   * The function accepts INTEGER_ARRAY scores as parameter.
   */

  public static List<Integer> breakingRecords(List<Integer> scores) {
    Integer first = scores.get(0);
    int[] bigger = scores.stream().filter(e -> e > first).mapToInt(i->i).toArray();
    int[] smaller = scores.stream().filter(e -> e < first).mapToInt(i->i).toArray();
    Integer biggerAcc = first;
    int biggerCount = 0;
    Integer smallerAcc = first;
    int smallerCount = 0;
    for (int i = 0; i < bigger.length; i++) {
      biggerCount = biggerAcc > bigger[i] ? biggerCount + 1 : biggerCount;
      biggerAcc = Math.max(biggerAcc, bigger[i]);
    }
    for (int i = 0; i < smaller.length; i++) {
      smallerCount = smallerAcc > smaller[i] ? smallerCount + 1 : smallerCount;
      smallerAcc = Math.max(smallerAcc, smaller[i]);
    }
    return Arrays.asList(biggerCount, smallerCount);
  }
}

public class Solution {
  public static void main(String[] args) throws IOException {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bufferedWriter =
        new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

    int n = Integer.parseInt(bufferedReader.readLine().trim());

    List<Integer> scores =
        Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

    List<Integer> result = Result.breakingRecords(scores);

    bufferedWriter.write(result.stream().map(Object::toString).collect(joining(" ")) + "\n");

    bufferedReader.close();
    bufferedWriter.close();
  }
}
