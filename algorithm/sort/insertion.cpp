/*
     The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
    Algorithm 
    To sort an array of size n in ascending order: 
        1: Iterate from arr[1] to arr[n] over the array. 
        2: Compare the current element (key) to its predecessor. 
        3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
*/

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        if (arr[i] >= arr[i - 1]) continue;  // already sorted
        int j = i - 1;
        int temp = arr[i];
        while (temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
            if (j == -1) break;
        }
        arr[j + 1] = temp;
    }
}


int main() {
    int arr[] = {9, 56, 2, 53, 1, 8, 3, 1};
    insertion_sort(arr, 8);
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    return 0;
}