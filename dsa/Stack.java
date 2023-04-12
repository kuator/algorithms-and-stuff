// package dsa;

import java.util.Scanner;
import java.io.*;

/**
 * Node
 */
/**
 * Stack
 */
public class Stack {
  class Node {
    int data;
    Node next;
    public Node(int data) {
      this.data = data;
    }
  }

  public Node head;

  public void push(int value) {
    Node newNode = new Node(value);
    newNode.next = this.head;
    this.head = newNode;
    System.out.println("ok");
  }

  public void pop() {
    System.out.println(head.data);
    this.head = this.head.next;
  }

  public int back() {
    System.out.println(head.data);
    return head.data;
  }

  public int size() {
    int cnt = 0;
    Node tmp = this.head;
    while (tmp != null) {
      tmp = tmp.next;
      cnt = cnt + 1;
    }
    System.out.println(cnt);
    return cnt;
  }

  public void clear() {
    this.head = null;
    System.out.println("ok");
  }

  public static void main(String[] args) throws IOException{
    Stack stack = new Stack();
    StreamTokenizer tf = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    while (true) {
      tf.nextToken();
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
    }
  }
    // scanner.close();
}
