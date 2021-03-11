/*
    The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

        1) The subarray which is already sorted.
        2) Remaining subarray which is unsorted.

    In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray
                    - from geeksforgeeks
*/

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = i; j < size; j++)  // loop that searchs the smallest element in the unsorted array
            if (arr[min_index] > arr[j]) min_index = j;
        swap(arr[min_index], arr[i]);
    }
}

int main() {
    int arr[] = {2, 5, 1, 6 ,9, 3, 5, 3, 1};
    selection_sort(arr, 9);
    for (int i = 0; i < 9; i++) cout << arr[i] << " ";
    return 0;
}
