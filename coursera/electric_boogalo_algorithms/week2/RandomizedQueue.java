import edu.princeton.cs.algs4.StdRandom;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {

  private int index = 0;
  private Item[] items;

  /** Node */

  // construct an empty randomized queue
  public RandomizedQueue() {
    this.items = (Item[]) new Object[10];
  }

  // is the randomized queue empty?
  public boolean isEmpty() {
    return index == 0;
  }

  // return the number of items on the randomized queue
  public int size() {
    return index;
  }

  // add the item
  public void enqueue(Item item) {
    if (index == items.length) {
      var tmp = (Item[]) new Object[items.length];
      for (int i = 0; i < items.length; i++) tmp[i] = items[i];

      items = (Item[]) new Object[items.length * 2];
      for (int i = 0; i < tmp.length; i++) items[i] = tmp[i];
    }

    items[index] = item;
    index++;
  }

  // remove and return a random item
  public Item dequeue() {

    if (index == 0) {
      throw new NoSuchElementException();
    }
    int rand = StdRandom.uniformInt(0, index);
    Item value = items[rand];
    for (int i = rand; i < index - 1; i++) {
      items[i] = items[i + 1];
    }
    index--;
    return value;
  }

  // return a random item (but do not remove it)
  public Item sample() {
    if (index == 0) {
      throw new NoSuchElementException();
    }
    int rand = StdRandom.uniformInt(0, index);
    return items[rand];
  }

  // return an independent iterator over items in random order
  public Iterator<Item> iterator() {
    return new RandomizedQueueIterator();
  }

  private class RandomizedQueueIterator implements Iterator<Item> {

    Item[] queueCopy;

    public RandomizedQueueIterator() {
      queueCopy = (Item[]) new Object[index];
      for (int i = 0; i < index; i++) {
        queueCopy[i] = items[i];
      }
      StdRandom.shuffle(queueCopy, 0, index);
      current = 0;
    }

    private int current;

    @Override
    public boolean hasNext() {
      return current < index;
    }

    @Override
    public Item next() {
      if (index == 0) {
        throw new NoSuchElementException();
      }
      return queueCopy[current++];
    }

    @Override
    public void remove() {
      throw new UnsupportedOperationException();
    }
  }

  // unit testing (required)
  public static void main(String[] args) {}
}
