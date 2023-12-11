import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
  private Node first;
  private Node last;
  private int size;

  /** Node */
  private class Node {
    Node next;
    Node previous;
    Item value;

    public Node(Item value) {
      this.value = value;
    }
  }

  // construct an empty deque
  public Deque() {
    size = 0;
  }

  // is the deque empty?
  public boolean isEmpty() {
    return size == 0;
  }

  // return the number of items on the deque
  public int size() {
    return size;
  }

  /**
   * @param item add the item to the front
   */
  public void addFirst(Item item) {
    if (item == null) {
      throw new IllegalArgumentException();
    }
    Node newnode = new Node(item);
    if (size == 0) {
      first = last = newnode;
      size = 1;
      return;
    }
    size++;
    newnode.next = first;
    first.previous = newnode;
    first = newnode;
  }

  // add the item to the back
  public void addLast(Item item) {
    if (item == null) {
      throw new IllegalArgumentException();
    }
    Node newnode = new Node(item);
    if (size == 0) {
      first = last = newnode;
      size = 1;
      return;
    }
    size++;
    last.next = newnode;
    newnode.previous = last;
    last = newnode;
  }

  // remove and return the item from the front
  public Item removeFirst() {
    if (size == 0) {
      throw new NoSuchElementException();
    }
    Item item = first.value;
    if (size == 1) {
      last = first = null;
      size = 0;
      return item;
    }
    first = first.next;
    first.previous = null;
    size--;
    return item;
  }

  // remove and return the item from the back
  public Item removeLast() {
    if (size == 0) {
      throw new NoSuchElementException();
    }
    Item item = last.value;
    if (size == 1) {
      last = first = null;
      size = 0;
      return item;
    }
    last = last.previous;
    last.next = null;
    size--;
    return item;
  }

  // return an iterator over items in order from front to back
  public Iterator<Item> iterator() {
    return new DequeIterator();
  }

  /**
   * @author: evakuator
   * @date: Dec 10, 2023
   * @description: DequeIterator.java
   */
  private class DequeIterator implements Iterator<Item> {
    private Node current = first;

    public boolean hasNext() {
      return current != null;
    }

    @Override
    public void remove() {
      throw new UnsupportedOperationException();
    }

    @Override
    public Item next() {
      if (size == 0) {
        throw new NoSuchElementException();
      }
      Item item = current.value;
      current = current.next;
      return item;
    }
  }

  // unit testing (required)
  public static void main(String[] args) {
    Deque<Integer> deque = new Deque<>();
    deque.addFirst(1);
    deque.addFirst(2);
    deque.addFirst(3);
    deque.addFirst(4);
    deque.addFirst(5);
    deque.addFirst(6);
    deque.addFirst(7);
    for (Integer integer : deque) {
      System.out.println(integer);
    }
    // System.out.println(deque.size());
    // while (!deque.isEmpty()) {
    // System.out.println(deque.removeLast());
    // }
  }
}
