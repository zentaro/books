#include <iostream>

using namespace std;

int head, tail, elapsed;
const int LEN = 100;
typedef pair<string, int> task;
task a[LEN];

void enqueue(task t) {
  a[tail] = t;
  tail = (tail + 1) % LEN;
}

task dequeue() {
  task t = a[head];
  head = (head + 1) % LEN;
  return t;
}

bool is_zero() {
  return head == tail;
}

void dump() {
  cout << "--- [head: " << head <<
    ", tail: " << tail <<
    ", elapsed: " << elapsed << "] " << endl << "--- ";
  for (int i = 0; i < LEN; i++)
    cout << '<' << a[i].first << ", " << a[i].second << "> ";
  cout << endl;
}

int main() {
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    int time;
    string name;

    cin >> name >> time;
    enqueue(make_pair(name, time));
  }

  while (!is_zero()) {
    //    dump();
    task t = dequeue();
    if (t.second > q) {
      t.second -= q;
      enqueue(t);
      elapsed += q;
    } else {
      elapsed += t.second;
      cout << t.first << ' ' << elapsed << endl;
    }
  }
}
