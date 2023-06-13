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
    System.out.println(value);
    System.out.println(current == null);
    if (value < current.value) {
      if (current.left == null)
        current.left = new Node(value);
      findAndSetParent(current.left, value);
    }
    if (current.right == null)
      current.right = new Node(value);
    findAndSetParent(current.right, value);
  }

  public void recur(Node current) {
    if (current == null)
      return;
    System.out.println(current.value);
    recur(current.left);
    recur(current.right);
  }

  public void print() {
    recur(head);
  }

  public static void main(String[] args) {
    BinarySearchTree binarySearchTree = new BinarySearchTree();
    binarySearchTree.insert(1);
    binarySearchTree.insert(2);
    binarySearchTree.insert(3);
    binarySearchTree.insert(4);
    binarySearchTree.insert(5);
    binarySearchTree.insert(6);
    binarySearchTree.insert(7);
    binarySearchTree.insert(8);
    binarySearchTree.insert(9);
    binarySearchTree.insert(10);
    // binarySearchTree.print();
  }
}
