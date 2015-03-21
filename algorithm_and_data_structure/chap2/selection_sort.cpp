#include <iostream>

using namespace std;

void selection_sort(int a[], int n) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int min_idx = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[min_idx])
        min_idx = j;
    }
    swap(a[i], a[min_idx]);
    if (i != min_idx) cnt++;
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << endl;
  cout << cnt << endl;
}

int main() {
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  selection_sort(a, n);
}
