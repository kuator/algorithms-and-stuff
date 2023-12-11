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
    Node tmp = new Node(value);
    if (this.head == null) {
      this.head = this.tail = tmp;
      return;
    } 
    tail.next = tmp;
    tail = tmp;
  }
  
  public int pop() {
    if (this.head == this.tail) {
      int data = this.head.data;
      this.clear();
      return data;
    }
    int data = this.head.data;
    head = head.next;
    count--;
    return data;
  }

  public int front() {
    return this.head.data; 
  }

  public void clear() {
    this.head = null;
    this.tail = null;
    this.count = 0;
  }

  public static void main(String[] args) throws IOException {
    Queue queue = new Queue();
    StreamTokenizer tf = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    while (true) {
      tf.nextToken();
      if (tf.sval.equals("push")) {
        tf.nextToken();
        int value = (int)tf.nval;
        queue.push(value);
        System.out.println("ok");
      }
      else if (tf.sval.equals("pop")) {
        System.out.println(queue.pop());
      }
      else if (tf.sval.equals("front")) {
        System.out.println(queue.front());
      }
      else if (tf.sval.equals("size")) {
        System.out.println(queue.count);
      }
      else if (tf.sval.equals("clear")) {
        queue.clear();
        System.out.println("ok");
      }
      else if (tf.sval.equals("exit")) {
        System.out.println("bye");
        break;
      }
    }
  }
}
