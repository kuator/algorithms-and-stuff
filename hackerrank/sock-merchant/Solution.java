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
   * Complete the 'sockMerchant' function below.
   *
   * The function is expected to return an INTEGER.
   * The function accepts following parameters:
   * 1. INTEGER n
   * 2. INTEGER_ARRAY ar
   */

  public static int sockMerchant(int n, List<Integer> ar) {
    TreeMap<Integer, Integer> sock = new TreeMap<>();
    for (Integer integer : ar) {
      sock.put(integer, sock.getOrDefault(integer, 0) + 1);
    }
    int value = sock.values().stream().mapToInt(Integer::intValue).map(e -> e / 2).sum();
    return value;
  }
}

public class Solution {
  public static void main(String[] args) throws IOException {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bufferedWriter =
        new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

    int n = Integer.parseInt(bufferedReader.readLine().trim());

    List<Integer> ar =
        Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

    int result = Result.sockMerchant(n, ar);

    bufferedWriter.write(String.valueOf(result));
    bufferedWriter.newLine();

    bufferedReader.close();
    bufferedWriter.close();
  }
}
