#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 200000; // max elements

int main() {
  long n;
  long max_v = -20000000000; // decrease more
  long ns[MAX]; // use array, not vector

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> ns[i];

  long min_v = ns[0];

  for (int i = 1; i < n; i ++) {
    // use max(), min() provided by algorithm library
    max_v = max(ns[i] - min_v, max_v); 
    min_v = min(min_v, ns[i]);
  }

  cout << max_v << endl;
  return 0;
}
