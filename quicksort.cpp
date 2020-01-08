#include <bits/stdc++.h>

void swap(int* first, int* second){
  int temp = *first;
  *first = *second;
  *second = temp;
}

int partition(int arr[], int left, int right, int pivot){
  while(left<=right){
    while(arr[left]<pivot)
      left++;
    while(arr[right]>pivot)
      right--;

    if(left<=right){
      swap(&arr[left], &arr[right]);
      left++;
      right--;
    }
  }
  return left;
}

/* Driver program to test above functions */
void quickSort(int arr[], int left, int right){
  if(left>=right) return;
  int pivot = arr[left + (right - left)/2];
  int index = partition(arr, left, right, pivot);
  quickSort(arr, left, index-1);
  quickSort(arr, index, right);
}

void printArray(int A[], int size) 
{ 
  int i; 
  for (i=0; i < size; i++) 
    printf("%d ", A[i]); 
  printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
  int arr_size; 
  std::cin >> arr_size;
  int arr[arr_size]; 
  for (int i = 0; i < arr_size; ++i) {
    std::cin >> arr[i];
  }

  quickSort(arr, 0, arr_size - 1); 

  printArray(arr, arr_size); 
  return 0; 
} 
