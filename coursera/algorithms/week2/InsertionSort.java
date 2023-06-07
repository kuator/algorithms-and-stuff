public class InsertionSort {
  public void swap(int[] arr, int first, int second) {
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
  }

  public void sort(int [] arr) {
    for (int i = 1; i < arr.length; i++) {
      int cur = arr[i];
      for (int j = i-1; j >=0 && arr[j] > cur; j--) {
        swap(arr, j+1, j);
      }
    }
  }

  public static void main(String[] args) {
    InsertionSort insertionSort = new InsertionSort();
    int [] arr = {10, 9, 8, 7};
    insertionSort.sort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
