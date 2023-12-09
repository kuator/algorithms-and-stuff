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
   * Complete the 'bonAppetit' function below.
   *
   * The function accepts following parameters:
   * 1. INTEGER_ARRAY bill
   * 2. INTEGER k
   * 3. INTEGER b
   */

  public static void bonAppetit(List<Integer> bill, int k, int b) {
    // int result = bill.stream().mapToInt(Integer::intValue).sum() / 2;
    int correctBill =
        IntStream.range(0, bill.size()).filter(e -> e != k).map(e -> bill.get(e)).sum() / 2;
    String response = correctBill == b ? "Bon Appetit" : "" + (b - correctBill);
    System.out.println(response);
  }
}

public class Solution {
  public static void main(String[] args) throws IOException {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

    int n = Integer.parseInt(firstMultipleInput[0]);

    int k = Integer.parseInt(firstMultipleInput[1]);

    List<Integer> bill =
        Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

    int b = Integer.parseInt(bufferedReader.readLine().trim());

    Result.bonAppetit(bill, k, b);

    bufferedReader.close();
  }
}
