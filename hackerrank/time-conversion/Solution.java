import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String timeConversion(String s) {
       int[] time = Arrays.stream(s.substring(0, s.length()-2).split(":")).mapToInt(Integer::parseInt).toArray();
       String ampm = s.substring(s.length()-2);
       time[0] = ampm.equals("AM") ? time[0]%12 : time[0]%12 + 12;
       var answer = Arrays.stream(time).mapToObj(String::valueOf).map(e -> String.format("%2s", e).replace(' ', '0'));
       return answer.collect(Collectors.joining(":"));
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.timeConversion(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
