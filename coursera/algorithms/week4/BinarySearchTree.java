public class BinarySearchTree {

  private Node head;

  private class Node {
    public int value;
    public Node left;
    public Node right;

    public Node(int value) {
      this.value = value;
    }
  }

  public BinarySearchTree() {
  }

  public void insert(int value) {
    if (head == null) {
      Node node = new Node(value);
      head = node;
      return;
    }
    findAndSetParent(head, value);
  }

  public void findAndSetParent(Node current, int value) {
    // System.out.println(value);
    // System.out.println(current == null);
    if (value < current.value) {
      if (current.left == null){
        current.left = new Node(value);
        return;
      }
      findAndSetParent(current.left, value);
    }
    else {
      if (current.right == null){
        current.right = new Node(value);
        return;
      }
      findAndSetParent(current.right, value);
    }
  }

  public void recur(Node current) {
    if (current == null)
      return;
    recur(current.left);
    System.out.println(current.value);
    recur(current.right);
  }

  public void print() {
    recur(head);
  }

  public static void main(String[] args) {
    BinarySearchTree binarySearchTree = new BinarySearchTree();
    for (int i = 0; i < 10000; i++) {
      int value = (int)(Math.random() * 10000) + 1;
      binarySearchTree.insert(value);
    }
    binarySearchTree.print();
  }
}
