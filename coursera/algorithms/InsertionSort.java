public class InsertionSort {

  public static void swap(int[]arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  public static int[] sort(int[] arr){
    for (int i = 1; i < arr.length; i++) {
        int cur = arr[i];
        for (int j = i-1; j >= 0 && arr[j] > cur ; j--)
          swap(arr,j+1, j);
    }
    return arr;
  }
  public static void main(String[] args) {
    int[] arr = {10, 9, 8, 7, 7, 6,5, 4,3 ,2};
    sort(arr);
    for (int i : arr) {
      System.out.println(i);
    }
  }
}
