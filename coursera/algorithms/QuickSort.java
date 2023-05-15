public class QuickSort {
  public QuickSort(int[] arr) {
    this.sort(arr, 0, arr.length-1);
  } 

  public void swap(int arr[], int first, int second){
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
  }

  public int partition(int[] arr, int left, int right) {
    int i = left, j = left, pivot = arr[right];
    while (j < right) {
      if (arr[j] < pivot) {
        swap(arr, j, i);
        i++;
      }
      j++;
    }
    swap(arr, i, right);
    return i;
  }


  public void sort(int[] arr, int left, int right) {
    if (left < right) {
      int partition = partition(arr, left, right);
      this.sort(arr, left, partition-1);
      this.sort(arr, partition+1, right);
    }
  }

  public static void main(String[] args) {
    int[] arr = {10,9,8};
    QuickSort quickSort = new QuickSort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
