#include <iostream>
#include <vector>

using namespace std;

int binary_search_int(int a[], int n, int target) {
    int L = 0;
    int R = n - 1;
    while (L <= R) {
        int mid = L + (R - L)/2;
        if (a[mid] == target) {
            return mid;
        }
        else if (a[mid] < target) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return -1;
}

int binary_search_vector(vector<int> a, int target) {
    int L = 0;
    int R = a.size() - 1;

    while (L <= R) {
        int mid = L + (R - L)/2;
        if (a[mid] == target) {
            return mid;
        }
        else if (a[mid] < target) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return -1;
}

int main() {
    int a[6] = {1, 4, 5, 6, 8, 10};
    vector<int> vec = {1, 4, 5, 6, 8, 10};
    int idx_a = binary_search_int(a, 6, 8);
    int idx_vec = binary_search_vector(vec, 8);
    cout << "Integer Array: idx - " << idx_a << endl;
    cout << "Vector Array: idx - " << idx_vec << endl;
    return 0;
}