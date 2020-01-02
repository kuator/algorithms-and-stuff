#include <bits/stdc++.h>

void insertionSort(int arr[],int n)
{
    int j=0;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            arr[j]=key;
            j--;
        }
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

// This is code is contributed by rathbhupendra
