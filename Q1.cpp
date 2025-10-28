#include <iostream>
#include <cstring>
using namespace std;

void ChangeLocationRecursive(char *a, int l, int r) {
    if (l >= r) return;
    char t = a[l];
    a[l] = a[r];
    a[r] = t;
    ChangeLocationRecursive(a, l + 1, r - 1);
}

void ChangeLocation(char *arr, int b1, int b2) {
    if (!arr) return;
    int len = strlen(arr);
    if (b1 < 1 || b2 < 1 || b1 > len || b2 > len) return;
    ChangeLocationRecursive(arr, b1 - 1, b2 - 1);
}

void printPattern(int n, int level) {
    if (n <= 0) return;
    for (int i = 0; i < level; i++) cout << " ";
    for (int i = 0; i < n; i++) cout << n << " ";
    cout << endl;
    if (n == 1) return;
    printPattern(n - 1, level + 1);
}

void PrintPattern(int &n) {
    printPattern(n, 0);
}

int main() {
    cout << "Part (a)\n";
    char arr[] = "COMPUTER";
    cout << "Original: " << arr << endl;
    ChangeLocation(arr, 3, 7);
    cout << "After ChangeLocation(arr,3,7): " << arr << endl << endl;

    cout << "Part (b)\n";
    int n = 4;
    cout << "Input n = " << n << endl;
    PrintPattern(n);
    return 0;
}

