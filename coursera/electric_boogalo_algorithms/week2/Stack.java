/**
 * @author: evakuator
 * @date: Dec 10, 2023
 * @description: Stack
 */
public class Stack {
  Node last;
  int size = 0;

  /**
   * @author: evakuator
   * @date: Dec 10, 2023
   * @description: Node
   */
  private class Node {
    int value;
    Node next;

    public Node(int value) {
      this.value = value;
    }
  }

  /**
   * @param value
   */
  public void push(int value) {
    size++;
    Node newLast = new Node(value);
    newLast.next = last;
    last = newLast;
  }

  public boolean isEmpty() {
    return size == 0;
  }

  /**
   * @return
   */
  public int pop() {
    if (size == 0) {
      throw new IndexOutOfBoundsException();
    }
    size--;
    int value = last.value;
    last = last.next;
    return value;
  }

  /**
   * @param args
   */
  public static void main(String[] args) {
    Stack stack = new Stack();
    stack.push(1);
    stack.push(2);
    stack.push(4);
    stack.push(3);
    stack.push(5);

    while (!stack.isEmpty()) {
      System.out.println(stack.pop());
    }
  }
}
