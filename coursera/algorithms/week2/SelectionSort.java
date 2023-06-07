public class SelectionSort {
  public void swap(int[] arr, int idx1, int idx2) {
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
  }

  public void sort(int [] arr) {
    for (int i = 0; i < arr.length-1; i++) {
      int min = i;
      for (int j = i+1; j < arr.length; j++) {
        if (arr[j] < arr[min]) 
          min = j;
      }
      swap(arr, i, min);
    }
  }

  public static void main(String[] args) {
    SelectionSort selectionSort = new SelectionSort();
    int [] arr = {10, 9, 8, 7};
    selectionSort.sort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
