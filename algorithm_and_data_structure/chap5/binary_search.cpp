#include <iostream>

using namespace std;

const int MAX_N = 100000;

int s[MAX_N + 1];
int n;

bool binary_search(int l, int h, int v) {
  while (l < h) {
    int m = (l + h) / 2;
    if (s[m] == v) return true;
    else if (v < s[m]) h = m;
    else l = m + 1;
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  int cnt, q, v;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> v;
    if (binary_search(0, n-1, v))
      cnt++;
  }
  cout << cnt << endl;
}
