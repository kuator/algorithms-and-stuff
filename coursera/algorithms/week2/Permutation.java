import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {

    public static void main(String[] args) {
        if (args.length == 0)
            return;

        int numToPrint;

        try {
            numToPrint = Integer.parseInt(args[0]);
        }
        catch (NumberFormatException nfe) {
            return;
        }

        final RandomizedQueue<String> rndQueue = new RandomizedQueue<String>();

        while (!StdIn.isEmpty()) {
            rndQueue.enqueue(StdIn.readString());
        }

        while (numToPrint > 0) {
            numToPrint -= 1;
            StdOut.println(rndQueue.dequeue());
        }
    }

}
