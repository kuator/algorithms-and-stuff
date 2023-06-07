import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
  private Node<Item> head;
  private Node<Item> tail;

  class Node<T> {
    public T value;
    public Node<T> next;
    public Node<T> previous;

    public Node(T value) {
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

  public Node<Item> getCurrent(){
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
      Node<Item> node = new Node<Item>(item);
      head = tail = node;
      count++;
      return;
    }
    var node = new Node<Item>(item);
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
      var node = new Node<Item>(item);
      head = tail = node;
      count++;
      return;
    }
    var node = new Node<Item>(item);
    node.previous = tail;
    tail.next = node;
    tail = node;
    count++;
  }
  //
  // // remove and return the item from the front
  public Item removeFirst(){
    if (count == 1) {
      Item item = this.head.value;
      head = tail = null;
      return item;
    }
    Item item = this.head.value;
    head = head.next; 
    count--;
    return item;
  }
  //
  // // remove and return the item from the back
  public Item removeLast(){
    if (count == 0) 
      throw new NoSuchElementException();
    if (count == 1) {
      Item item = this.head.value;
      head = tail = null;
      return item;
    }
    Item item = tail.value;
    tail = tail.previous; 
    count--;
    return item;
  }

  public static void main(String[] args){
    Deque<Integer> deque = new Deque<>();
    deque.addLast(1);
    System.out.println(deque.size());
    deque.addLast(2);
    System.out.println(deque.size());
    deque.addFirst(3);
    System.out.println(deque.size());
  }

  @Override
  public Iterator<Item> iterator() {
    return new DequeIterator();

  }

  private class DequeIterator implements Iterator<Item> {
    Node<Item> current;  // the current element we are looking at

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
      Item item = (Item)current.value;
      current = current.next;
      return item;
    }

  }
}
