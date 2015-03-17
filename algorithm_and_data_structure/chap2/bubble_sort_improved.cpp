#include <iostream>

using namespace std;

void bubble_sort(int a[], int n) {
  bool changed = true;
  int cnt = 0;
  for (int i = 0; changed; i++) {
    changed = false;
    for (int j = n - 1; j > i; j--) {
      if (a[j] < a[j-1]) {
        swap(a[j], a[j-1]);
        cnt++;
        changed = true;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    if (k) cout << ' ';
    cout << a[k];  
  }
  cout << endl;
  cout << cnt << endl;
}

int main() {
  int n;
  int a[1000];

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  bubble_sort(a, n);
}
