#include <iostream>

using namespace std;

void insertion_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;

    cout << a[0];
    for (int k = 1; k < n; k++)
      cout << ' ' << a[k];
    cout << endl;
  }
}

int main() {
  int n;
  int a[1000];

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  insertion_sort(a, n);
}
