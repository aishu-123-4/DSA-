#include <iostream>

using namespace std;


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int a = gcd(1785, 546);
    cout << a << "\n";
    return 0;
}