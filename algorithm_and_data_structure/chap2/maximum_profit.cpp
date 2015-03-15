#include <iostream>
#include <vector>

using namespace std;

int main() {
  long n;
  double p = -1000000000;
  cin >> n;
  vector<long> ns(n);
  for (int i = 0; i < n; i++)
    cin >> ns[i];
  for (int i = 0; i < n-1; i ++) {
    for (int j = i + 1; j < n; j++) {
      if (ns[j] - ns[i] > p)
        p = ns[j] - ns[i];
    }
  }
  cout << p << endl;
  return 0;
}
