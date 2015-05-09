#include <iostream>

using namespace std;

int idx = 0;
long a[100];

void push(long v) {
  a[idx++] = v;
}

long pop() {
  return a[--idx];
}

void dump() {
  cout << "[idx: " << idx << "] ";
  for (int i = 0; i < idx+1; i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << endl;
}

int main() {
  string s;

  while (cin >> s) {
    switch (s[0]) {
    case '+' :
      push(pop() + pop());
      break;
    case '-' : {
      long a = pop();
      long b = pop();
      push(b - a);
      break;
    }
    case '*' :
      push(pop() * pop());
      break;
    default :
      push(atoi(s.c_str()));
    }
    // dump();
  }
  cout << pop() << endl;
}
