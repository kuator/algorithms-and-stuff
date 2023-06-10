import java.util.Iterator;
import java.util.NoSuchElementException;

import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueue<Item> implements Iterable<Item> {
  // construct an empty randomized queue
  private Item[] queue;
  private int index;
  private int size;
  public RandomizedQueue(){
    queue = (Item[]) new Object[10];
    index = 0;
    size = 0;
  }

  // is the randomized queue empty?
  public boolean isEmpty(){
    return index == 0;
  }

  // return the number of items on the randomized queue
  public int size(){
    return index;
  }

  private void resizeQueue(){
    if (index < queue.length) {
      return; 
    }
    Item [] tmp = (Item[]) new Object[queue.length];
    for (int i = 0; i < queue.length; i++) 
      tmp[i] = queue[i];
    queue = (Item[]) new Object[queue.length*2];
    for (int i = 0; i < tmp.length; i++) 
      queue[i] = tmp[i];
  }

  // add the item
  public void enqueue(Item item){
    if (item == null) 
      throw new IllegalArgumentException();
    resizeQueue();
    queue[index] = item;
    System.out.print("index: ");
    System.out.println(index);
    index++;
  }

  // remove and return a random item
  public Item dequeue(){
    if (isEmpty()) 
      throw new NoSuchElementException();
    int randomIndex = StdRandom.uniformInt(0, index);
    Item randomItem = queue[randomIndex];
    for (int i = randomIndex; i < index -1; i++) 
      queue[i] = queue[i+1];
    index--;
    return randomItem;
  }

  // return a random item (but do not remove it)
  public Item sample(){
    if (isEmpty()) 
      throw new NoSuchElementException();
    int i = StdRandom.uniformInt(0, index);
    return queue[i];
  }

  // return an independent iterator over items in random order
  public Iterator<Item> iterator(){
    return new RandomizedQueueIterator();
  }

  private class RandomizedQueueIterator implements Iterator<Item> {
    int current; 
    Item[] queue_;

    public RandomizedQueueIterator(){
      queue_ = (Item[]) new Object[index];
      for (int i = 0; i < index; i++) 
        queue_[i] = queue[i];
      StdRandom.shuffle(queue_, 0, index);
      current = 0;
    }

    @Override
    public void remove() {
      throw new UnsupportedOperationException();
    }

    public boolean hasNext(){
      return current < index;
    }

    public Item next() {
      if (!hasNext()) 
        throw new NoSuchElementException();
      Item item = queue_[current];
      current++;
      return item;
    }
     
  }

  private static void printIterator(RandomizedQueue<Integer> q) {
      for (Integer i : q)
          System.out.format("%s ", i);
      System.out.format("%n%n");
  }

  // unit testing (required)
  public static void main(String[] args) {
      RandomizedQueue<Integer> rndQueue = new RandomizedQueue<Integer>();

      System.out.format("Size    :        %s%n", rndQueue.size());
      System.out.format("Is empty:        %s%n%n", rndQueue.isEmpty());

      System.out.println("Adding 10 elements, using enqueue");
      for (int i = 0; i < 10; ++i)
          rndQueue.enqueue(i);

      System.out.format("Size    :        %s%n", rndQueue.size());
      System.out.format("Is empty:        %s%n%n", rndQueue.isEmpty());

      System.out.println(
              "Printing RandomizeQueue with iterator, 10 numbers should appear in random");
      RandomizedQueue.printIterator(rndQueue);

      System.out.println(
              "Printing RandomizedQueue with dequeue, 10 numbers should appear in random order");
      while (!rndQueue.isEmpty())
          System.out.format("%s ", rndQueue.dequeue());

      System.out.format("%nSize    :        %s%n", rndQueue.size());
      System.out.format("Is empty:        %s%n%n", rndQueue.isEmpty());

      System.out.println("Adding 1 element, using enqueue");
      rndQueue.enqueue(1);
      System.out.println("Getting element, through sample");
      System.out.format("%s %n", rndQueue.sample());
      System.out.format("%nSize    :        %s%n", rndQueue.size());
      System.out.format("Is empty:        %s%n%n", rndQueue.isEmpty());
      System.out.println("Getting element, through dequeue");
      System.out.format("%s %n", rndQueue.dequeue());
      System.out.format("%nSize    :        %s%n", rndQueue.size());
      System.out.format("Is empty:        %s%n%n", rndQueue.isEmpty());

      System.out.println("Adding 10 elements, using enqueue");
      for (int i = 0; i < 10; ++i)
          rndQueue.enqueue(i);

      System.out.println(
              "Printing RandomizedQueue with sample, 10 numbers should appear in random order");
      for (int i = 0; i < 10; ++i)
          System.out.format("%s ", rndQueue.sample());

      System.out.format("%nSize    :        %s%n", rndQueue.size());
      System.out.format("Is empty:        %s%n%n", rndQueue.isEmpty());
  }

}
