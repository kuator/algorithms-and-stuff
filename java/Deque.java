import java.util.Iterator;
public class Deque<Item> implements Iterable<Item> {
  private int length;
  private Node front, rear;
  public Deque() {
    front = rear = null;
    length = 0;
  }

  private class Node {
    Item value;
    Node next;
    Node prev;
    public Node(Item value) {
      next = prev = null;
      this.value = value;
    }
  }

  public boolean isEmpty() {
    return front == null;
  }

  public int size() {
    return length;
  }

  public void addFirst(Item item) {
    if (item == null) {
      throw new IllegalArgumentException();
    }
    if (front == null) {
      front = rear = new Node(item);
      length++;
      return;
    }
    Node node = new Node(item);
    node.next = front;
    node.next.prev = node;
    front = node;
    length++;
  } 

  public void addLast(Item item) {
    if (item == null) {
      throw new IllegalArgumentException();
    }

    if (front == null) {
      front = rear = new Node(item);
      length++;
      return;
    }

    Node node = new Node(item);
    rear.next = node;
    node.prev = rear;
    rear = node;
    length++;
  } 

  public Item removeFirst() {
    if (front == null) {
      throw new java.util.NoSuchElementException();
    }

    Item value = front.value;
    front = front.next;
    if (front == null) {
      front = rear = null;
    }
    length--;
    return value;
  } 

  public Item removeLast() {
    if (rear == null) {
      throw new java.util.NoSuchElementException();
    }

    Item value = rear.value;
    rear = rear.prev;

    if (rear == null) {
      front = rear = null;
    }
    length--;
    return value;
  } 
  public Iterator<Item> iterator(){
    Iterator<Item> it = new Iterator<Item>() {
      private Node current = front;

      @Override
      public boolean hasNext() {
        return current != null;
      }

      @Override
      public Item next() {
        if (!hasNext()) {
          throw new java.util.NoSuchElementException();
        }
        Item value = current.value;
        current = current.next;
        return value;
      }

      @Override
      public void remove() {
        throw new UnsupportedOperationException();
      }
    };
    return it;
  }
}
