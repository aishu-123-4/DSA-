#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return (i+1);
}

void quick_sort(int* arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

int main() {
    int arr[8] = {2, 5, 3, 6, 9, 4, 12, 10};
    quick_sort(arr, 0, 7);
    for (int x: arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0; 
}