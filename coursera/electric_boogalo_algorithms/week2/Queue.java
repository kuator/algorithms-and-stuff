/**
 * @author: evakuator
 * @date: Dec 10, 2023
 * @description: Queue
 */
public class Queue {
  Node first;
  Node last;
  int size = 0;

  /**
   * @author: evakuator
   * @date: Dec 10, 2023
   * @description: Node
   */
  private class Node {
    Node next;
    int value;

    public Node(int value) {
      this.value = value;
    }
  }

  /**
   * @return first element
   */
  public int pop() {
    if (size == 0) {
      throw new IndexOutOfBoundsException();
    }
    if (size == 1) {
      int value = this.first.value;
      first = last = null;
      size = 0;
      return value;
    }
    int value = this.first.value;
    first = first.next;
    size--;
    return value;
  }

  /**
   * @param value
   * @description insert new element
   */
  public void push(int value) {
    Node newnode = new Node(value);
    if (size == 0) {
      first = last = newnode;
      size = 1;
      return;
    }
    last.next = newnode;
    last = newnode;
    size++;
  }

  public boolean isEmpty() {
    return size == 0;
  }

  /**
   * @param args
   */
  public static void main(String[] args) {
    Queue queue = new Queue();
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    while (!queue.isEmpty()) {
      System.out.println(queue.pop());
    }
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    while (!queue.isEmpty()) {
      System.out.println(queue.pop());
    }
  }
}
