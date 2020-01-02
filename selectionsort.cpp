#include <bits/stdc++.h>

void swap(int* first, int* second)
{
  int tmp = *first;
  *first = *second;
  *second = tmp;
}

void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n-1; ++i) {
    int min_index = i;
    for (int j = i+1; j < n; ++j) {
      if(arr[j]<arr[min_index]){
        min_index = j;
      }
      swap(&arr[i], &arr[min_index]);
    }
  }
}

/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        std::cout << arr[i] << " ";  
    std::cout << std::endl;  
}  
  
// Driver program to test above functions  
int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    std::cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
