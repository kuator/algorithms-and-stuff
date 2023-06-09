public class QuickSort {
  public QuickSort() {
  }

  public void swap(int[] arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  public void sort(int[] arr) {
    quickSort(arr, 0, arr.length-1);
  }

  public void quickSort(int[] arr, int left, int right) {
    if (left >= right) 
      return;
    int pivotValue = arr[right];
    int tempPivotIndex = left;

    for (int j = left; j < right; j++) {
      if (arr[j] > pivotValue) 
        continue;
      swap(arr, tempPivotIndex, j);
      tempPivotIndex++;
    }
    swap(arr, tempPivotIndex, right);
    quickSort(arr, left, tempPivotIndex-1);
    quickSort(arr, tempPivotIndex+1, right);
  }

  public static void main(String[] args) {
    QuickSort quickSort = new QuickSort();
    int[] arr = new int[]{10,9,9,9,9,9,9,8,7};
    quickSort.sort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
