public class MaxHeap {
  // To store array of elements in heap
  private int[] heapArray;

  // max size of the heap
  private int capacity;

  public static void swap(int[]arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  public static bool less(int i, int j){
     return arr[i] < arr[j];
  }

  public static bool greater(int i, int j){
     return arr[i] > arr[j];
  }

  // Current number of elements in the heap
  private int N;

  public MaxHeap(int capacity) {
    this.capacity = capacity;
    heapArray = new int[capacity+1];
    N = 0;
  }

  private void swim(int i) {
    int parent = i/2;
    while (i > 1 && greater(i, parent)) {
      swap(arr, i, i/2);
      i = parent;
    }
  }

  public void insert(int value) {
    arr[++N] = value;
    swim(N);
  }

  private void sink(int k){
    while (2*k <= N) {
      int j = 2*k;
      j = (j < N && greater(j+1, j)) ? j+1 : j;
      if (greater(k, j)) break;
      swap(arr, k, j);
      k = j;
    }
  }

  public int delMax() {
    int max = arr[1];
    swap(arr, 1, N--);
    sink(1);
    arr[N+1] = null;
    return max;
  }

  private int parent(int i){
    return i/2;
  }

  private int left(int i){
    return i*2;
  }
  private int right(int i){
    return i*2 +1;
  }
}
