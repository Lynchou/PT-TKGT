#include <iostream>
using namespace std;

void nhap(float a[], int& n) {
    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang a:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Phanchia(float a[], int L, int R) {
    if (L >= R) return;
    int x = a[(L + R) / 2];
    int i = L, j = R;
    while (i < j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (L < j) Phanchia(a, L, j);
    if (i < R) Phanchia(a, i, R);
}

void QuickSort(float a[], int n) {
    Phanchia(a, 0, n - 1);
}

void Ghi(float a[], int n) {
    cout << "Cac phan tu sau khi sap xep QuickSort la:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    float a[100];
    int n;
    nhap(a, n);
    QuickSort(a, n);
    Ghi(a, n);
    return 0;
}