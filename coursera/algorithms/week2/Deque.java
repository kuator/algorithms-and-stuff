import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
  private Node head;
  private Node tail;

  private class Node {
    public Item value;
    public Node next;
    public Node previous;

    public Node(Item value) {
      this.value = value;
    }
  }

  private int count = 0;
  // construct an empty deque
  public Deque() {
    this.count = 0; 
  }

  // is the deque empty?
  public boolean isEmpty(){
    return count == 0;
  }

  private Node getCurrent(){
    return head;
  }

  public int size(){
    return count;
  }

  // add the item to the front
  public void addFirst(Item item){
    if (item == null) 
      throw new IllegalArgumentException();
    if (count == 0) {
      Node node = new Node(item);
      head = tail = node;
      count++;
      return;
    }
    var node = new Node(item);
    node.next = head;
    head.previous = node;
    head = node;
    count++;
  }

  //
  // // add the item to the back
  public void addLast(Item item){
    if (item == null) 
      throw new IllegalArgumentException();
    if (count == 0) {
      var node = new Node(item);
      head = tail = node;
      count++;
      return;
    }
    var node = new Node(item);
    node.previous = tail;
    tail.next = node;
    tail = node;
    count++;
  }
  //
  // // remove and return the item from the front
  public Item removeFirst(){
    if (count == 0)
        throw new NoSuchElementException("Deque is empty");
    Item item = head.value;
    head = head.next; 
    if (count == 1) 
      head = tail = null;
    count--;
    return item;
  }
  //
  // // remove and return the item from the back
  public Item removeLast(){
    if (count == 0) 
      throw new NoSuchElementException();
    Item item = tail.value;
    tail = tail.previous; 
    if (count == 1) 
      head = tail = null;
    count--;
    return item;
  }

  @Override
  public Iterator<Item> iterator() {
    return new DequeIterator();

  }

  private class DequeIterator implements Iterator<Item> {
    Node current;  // the current element we are looking at

    public DequeIterator() {
      this.current = head;
    }

    @Override
    public void remove() {
      throw new UnsupportedOperationException();
    }

    public boolean hasNext(){
      return current != null;
    }

    public Item next() {
      if (!hasNext()) 
        throw new NoSuchElementException();
      Item item = current.value;
      current = current.next;
      return item;
    }

  }

  public static void main(String[] args) {
      Deque<Integer> quetack = new Deque<Integer>();

      System.out.format("Size    :        %s%n", quetack.size());
      System.out.format("Is empty:        %s%n%n", quetack.isEmpty());

      System.out.println("Adding 10 elements, using addFirst");
      for (int i = 0; i < 10; ++i)
          quetack.addFirst(i);

      System.out.format("Size    :        %s%n", quetack.size());
      System.out.format("Is empty:        %s%n%n", quetack.isEmpty());

      System.out.println("Printing Dequeue with iterator, numbers should appear from 9 to 0");
      Deque.printIterator(quetack);

      System.out.println("Printing Dequeue with removeFirst, numbers should appear from 9 to 0");
      while (!quetack.isEmpty())
          System.out.format("%s ", quetack.removeFirst());
      System.out.format("%n%n");

      System.out.format("Size    :        %s%n", quetack.size());
      System.out.format("Is empty:        %s%n%n", quetack.isEmpty());

      System.out.println("Adding 10 elements, using addLast");
      for (int i = 0; i < 10; ++i)
          quetack.addLast(i);

      System.out.format("Size    :        %s%n", quetack.size());
      System.out.format("Is empty:        %s%n%n", quetack.isEmpty());

      System.out.println("Printing Dequeue with iterator, numbers should appear from 0 to 9");
      Deque.printIterator(quetack);

      System.out.println("Printing Dequeue with removeLast, numbers should appear from 9 to 0");
      while (!quetack.isEmpty())
          System.out.format("%s ", quetack.removeLast());
      System.out.format("%n%n");

      System.out.format("Size    :        %s%n", quetack.size());
      System.out.format("Is empty:        %s%n%n", quetack.isEmpty());

      System.out.println("Adding 1 element, using addLast");
      quetack.addLast(0);

      System.out.format("Size    :        %s%n", quetack.size());
      System.out.format("Is empty:        %s%n%n", quetack.isEmpty());

      System.out.println("Printing Dequeue with removeLast, numbers should appear to be 0");
      System.out.format("%s ", quetack.removeLast());

      System.out.format("Size    :        %s%n", quetack.size());
      System.out.format("Is empty:        %s%n%n", quetack.isEmpty());

      System.out.println("Random operations");
      quetack.addFirst(1);
      quetack.addFirst(2);
      System.out.format("Should be 1 ---> %s %n", quetack.removeLast());
      System.out.format("Is empty:        %s%n", quetack.isEmpty());
      System.out.format("Should be 2 ---> %s %n", quetack.removeLast());
      System.out.format("Is empty:        %s%n", quetack.isEmpty());
  }

  private static void printIterator(Deque<Integer> q) {
      for (Integer i : q)
          System.out.format("%s ", i);
      System.out.format("%n%n");
  }
}
