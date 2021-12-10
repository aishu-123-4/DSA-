#include <iostream>

using namespace std;

void merge(int* arr, int l, int mid, int r) {

    int l_size = mid - l + 1;
    int r_size = r - mid;
 
    // int* leftarr = new int[l_size];
    // int* rightarr = new int[r_size];
    int leftarr[l_size], rightarr[r_size];

    for (int i = 0; i < l_size; i++)
        leftarr[i] = arr[l + i];
    for (int i = 0; i < r_size; i++)
        rightarr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < l_size && j < r_size) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    while (i < l_size) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    while (j < r_size) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l)/2; 
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }  
}

int main() {
    int arr[8] = {2, 5, 3, 6, 9, 4, 12, 10};
    merge_sort(arr, 0, 7);
    for (int x: arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0; 
}