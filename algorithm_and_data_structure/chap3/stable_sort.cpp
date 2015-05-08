#include <iostream>
#include <array>

using namespace std;

struct card { char suit; int num; };

int n;
card cards[36];

void solve() {
  card org[36];
  for (int i = 0; i < n; i++)
    org[i] = cards[i];

  // bubble sort
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (cards[j].num < cards[j-1].num)
        swap(cards[j], cards[j-1]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << cards[i].suit << cards[i].num;
  }
  cout << endl << "Stable" << endl;

  // selection  sort
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (org[j].num < org[minj].num)
        minj = j;
    }
    swap(org[i], org[minj]);
  }

  bool is_stable = true;
  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << org[i].suit << org[i].num;
    if (cards[i].suit != org[i].suit)
      is_stable = false;
  }
  cout << endl << (is_stable ? "Stable" : "Not stable") << endl;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> cards[i].suit >> cards[i].num;
  solve();
}
