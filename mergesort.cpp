#include<stdlib.h> 
#include<stdio.h> 

void merge(int arr[], int left, int middle, int right){
  int i,j,k; 
  int n1=middle-left+1;
  int n2=right-middle;
  int first[n1], second[n2];
  for (i = 0; i < n1; ++i) {
    first[i] = arr[i+left];
  }
  for (j = 0; j < n2; ++j) {
    second[j] = arr[j+middle+1];
  }
  j = 0;
  i = 0;
  k = left;

  while(i < n1 && j < n2){
    if(first[i] >= second[j]){
      arr[k] = second[j];
      j++;
    } else if(first[i] < second[j]){
      arr[k] = first[i];
      i++;
    }
    k++;
  }

  while(i<n1){
    arr[k] = first[i];
    k++;
    i++;
  }

  while(j<n2){
    arr[k] = second[j];
    k++;
    j++;
  }
}

void mergeSort(int arr[], int left, int right){
  if(left<right){
    int middle = left+(right-left)/2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
  }
}


/* UTILITY FUNCTIONS */
/* Function to print an array */
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
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
