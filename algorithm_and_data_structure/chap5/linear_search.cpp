#include <iostream>

using namespace std;

const int MAX_N = 10000;
const int MAX_T = 500;

long s[MAX_N + 1];
long t[MAX_T + 1];

int n, q;

void linear_search() {
  int cnt = 0;
  int i = 0, j = 0;
  while (t[i] != -1) {
    while (s[j] != -1) {
      if (t[i] == s[j]) {
        cnt++;
        break;
      }
      j++;
    }
    i++;
    j = 0;
  }
  cout << cnt << endl;
}

int main() {
  int i;
  cin >> n;
  for (i = 0; i < n; i++)
    cin >> s[i];
  s[i] = -1;

  cin >> q;
  for (i = 0; i < q; i++)
    cin >> t[i];
  t[i] = -1;

  linear_search();
}
