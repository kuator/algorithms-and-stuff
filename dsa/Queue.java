import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

/**
 * Queue
 */
public class Queue {
  /**
   * Node
   */
  class Node {
    Node next;
    int data;
    public Node(int data) {
      this.data = data;
    }
  }

  public Node head;
  public Node tail;
  public int count;

  public Queue() {
    this.count = 0;
  }

  public void push(int value) {
    count++;
    System.out.println("ok");
    Node tmp = new Node(value);
    if (this.head == null) {
      tmp.next = tmp;
      this.head = this.tail = tmp;
      return;
    } 
    tail.next = tmp;
    tail = tmp;
  }

  public void front() {
    System.out.println(this.head.data);
  }

  public void size() {
    System.out.println(this.count);
  }

  public void clear() {
    System.out.println("ok");
    this.head = null;
    count = 0;
  }

  public void pop() {
    System.out.println(this.head.data);
    head = head.next;
    count--;
  }

  public static void main(String[] args) throws IOException {
    Queue queue = new Queue();
    StreamTokenizer tf = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    tf.nextToken();


    while (true) {
      if (tf.sval.equals("push")) {
        tf.nextToken();
        int value = (int)tf.nval;
        queue.push(value);
      }
      else if (tf.sval.equals("pop")) {
        queue.pop();
      }
      else if (tf.sval.equals("front")) {
        queue.front();
      }
      else if (tf.sval.equals("size")) {
        queue.size();
      }
      else if (tf.sval.equals("exit")) {
        System.out.println("bye");
        break;
      }
      tf.nextToken();
    }
  }
}
