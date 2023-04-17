public class InsertionSort {

  public static void swap(int[]arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  public static int[] sort(int[] arr){
    for (int i = 1; i < arr.length; i++) {
      if (arr[i] < arr[i-1]) {
        int j = i-1;
        while (j >= 0) {
          if (arr[i] < arr[j]){
            swap(arr, i, j);
            break;
          }
          arr[j+1] = arr[j];
          j--;
        }
      }
    }
    return arr;
  }
  public static void main(String[] args) {
    int[] arr = {10, 9, 8, 7, 6,5, 4,3 ,2};
    sort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
