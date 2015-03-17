#include <iostream>

using namespace std;

void bubble_sort(int a[], int n) {
  bool changed = true;
  int cnt = 0;
  while (changed) {
    changed = false;
    for (int j = n - 1; j > 0; j--) {
      if (a[j] < a[j-1]) {
        swap(a[j], a[j-1]);
        cnt++;
        changed = true;
      }
    }
  }
  cout << a[0];
  for (int k = 1; k < n; k++)
    cout << ' ' << a[k];
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
