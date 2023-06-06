import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

public class Queue {
  private Node head;
  // private Node head;
  private int count;

  class Node {
    public int value;
    public Node next;

    public Node(int value) {
      this.value = value;
    }
  }

  public Queue() {
    this.count = 0;
  }

  public void push(int value) {
    System.out.println("ok");
    count++;
    if (head == null) {
      Node node = new Node(value);
      head = node;
      return;
    }
    Node node = new Node(value);
    node.next = this.head;
    this.head = node;
  }

  public void pop() {
    if (head == null) 
      return;
    System.out.println(head.value);
    head = head.next;
    count--;
  }

  public void front() {
    System.out.println(head.value);
  }

  public void clear() {
    this.head = null;
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
    Queue queue = new Queue();
    StreamTokenizer tf = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    tf.nextToken();

    while (true) {
      if (tf.sval.equals("push")) {
        tf.nextToken();
        int value =  (int)tf.nval;
        queue.push(value);
      }
      else if (tf.sval.equals("pop")) {
        queue.pop();
      }
      else if (tf.sval.equals("clear")) {
        queue.clear();
      }
      else if (tf.sval.equals("size")) {
        queue.size();
      }
      else if (tf.sval.equals("front")) {
        queue.front();
      }
      else if (tf.sval.equals("exit")) {
        System.out.println("bye");
        break;
      }
    tf.nextToken();
    }
  }
}
