public class MergeSort {
  public MergeSort() {
  }

  public void swap(int[] arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  public void sort(int[] arr) {
    mergeSort(arr, 0, arr.length-1);
  }

  public void mergeSort(int[] arr, int left, int right) {
    if (left >= right) 
      return;
    int middle = left + (right - left)/2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle+1, right);
    merge(arr, left, middle, right);
  }

  public void merge(int[] arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int[]arr1 = new int[n1], arr2 = new int[n2];
    for (int i = 0; i < n1; i++) 
      arr1[i] = arr[left+i];
    for (int i = 0; i < n2; i++) 
      arr2[i] = arr[middle+1+i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
      if (arr1[i]< arr2[j]) {
        arr[k] = arr1[i];
        i++;
      }
      else {
        arr[k] = arr2[j];
        j++;
      }
      k++;
    }

    while (i < n1) {
      arr[k] = arr1[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = arr2[j];
      j++;
      k++;
    }
  }

  public static void main(String[] args) {
    MergeSort mergeSort = new MergeSort();
    int[] arr = new int[]{10,9,9,9,9,9,9,8,7};
    mergeSort.sort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
