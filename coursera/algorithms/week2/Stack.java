import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

public class Stack {
  private Node tail;
  private int count;

  class Node {
    public int value;
    public Node previous;

    public Node(int value) {
      this.value = value;
    }
  }

  public Stack() {
    this.count = 0;
  }

  public void push(int value) {
    System.out.println("ok");
    count++;
    if (tail == null) {
      Node node = new Node(value);
      tail = node;
      return;
    }
    Node node = new Node(value);
    node.previous = this.tail;
    this.tail = node;
  }

  public void pop() {
    if (tail == null) 
      return;
    System.out.println(tail.value);
    tail = tail.previous;
    count--;
  }

  public void back() {
    System.out.println(tail.value);
  }

  public void clear() {
    this.tail = null;
    count = 0;
    System.out.println("ok");
  }

  public int size() {
    System.out.println(count);
    return count;
  }

  public void exit() {
    System.out.println("bye");
  }

  public static void main(String[] args) throws IOException{
    Stack stack = new Stack();
    StreamTokenizer tf = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    tf.nextToken();

    while (true) {
      if (tf.sval.equals("push")) {
        tf.nextToken();
        int value =  (int)tf.nval;
        stack.push(value);
      }
      else if (tf.sval.equals("pop")) {
        stack.pop();
      }
      else if (tf.sval.equals("clear")) {
        stack.clear();
      }
      else if (tf.sval.equals("size")) {
        stack.size();
      }
      else if (tf.sval.equals("back")) {
        stack.back();
      }
      else if (tf.sval.equals("exit")) {
        System.out.println("bye");
        break;
      }
    tf.nextToken();
    }
  }
}
