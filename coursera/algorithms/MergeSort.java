public class MergeSort {
  public MergeSort(int[] arr) {
    this.sort(arr, 0, arr.length-1);
  }

  public void sort(int[] arr, int left, int right){
    if (left < right) {
      int middle = left + (right-left)/2;
      sort(arr, left, middle);
      sort(arr, middle+1, right);
      merge(arr, left, middle, right);
    }
  }

  public void merge(int[] arr, int left, int middle, int right){
    int n1 = middle - left + 1, n2 = right-middle;

    int[] arr1 = new int[n1], arr2 = new int[n2];
    for (int i = 0; i < n1; i++)
      arr1[i] = arr[left+i];
    for (int i = 0; i < n2; i++) 
      arr2[i] = arr[middle+1+i];

    int i = 0, j = 0, k = 0;
    while (i<n1 && j < n2) {
      if (arr1[i] < arr2[j]) {
        arr[left+k] = arr1[i];
        i++;
      }
      else if (arr2[j] <= arr1[i]) {
        arr[left+k] = arr2[j];
        j++;
      }
      k++;
    }
    while (i<n1) {
      arr[left+k] = arr1[i];
      k++;
      i++;
    }
    while (j<n2) {
      arr[left+k] = arr2[j];
      k++;
      j++;
    }
  }
   
  public static void main(String[] args) {
    int[] arr = {10,9, 9, 8 , 7};
    MergeSort mergeSort = new MergeSort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
