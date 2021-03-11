/*
    -divide the array into 2 subarrays
    -sort them
    -merge them
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merger(int arr[], int l, int r) { //l = left, r = right
    if (l == r - 1) return;

    int m = (l + r) / 2;
    int l1, l2; 
    l1 = m - l + 1; 
    l2 = r - m;
    int arr1[l1], arr2[l2];
    for (int i = 0; i < l1; i++) arr1[i] = arr[l + i];
    for (int j = 0; j < l2; j++) arr2[j] = arr[m + j + 1];
    int i = 0,j = 0, k = 0;
    while (i < l1 && j < l2) {
        if (arr1[i] <= arr2[j]) {
            arr[l + k] = arr1[i];
            i++;
        } else { 
            arr[l + k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < l1) {
        arr[l + k] = arr1[i];
        i++;
        k++;
    }
    while(j < l2) {
        arr[l + k] = arr2[j];
        j++;
        k++;
    }
    return;
}

void merge_sort(int arr[], int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merger(arr, l, r);
    return;
}

int main() {
    int arr[] = {1, 9, 2, 6, 2, 5, 8};
    merge_sort(arr,0, 6);
    cout << "h\n";
    for (int i = 0; i < 7; i++) cout << arr[i] << " ";

    return 0;
}