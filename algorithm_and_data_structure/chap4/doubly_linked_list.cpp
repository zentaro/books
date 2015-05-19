#include <iostream>

using namespace std;

struct Node { Node *prev; Node *next; long key; };
Node *nil;

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->prev = nil;
  nil->next = nil;
}

void insert(long key) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->key = key;

  new_node->next = nil->next;
  new_node->prev = nil;
  nil->next->prev = new_node;
  nil->next = new_node;
}

void delete_node(long key) {
  Node *n = nil->next;
  while (n != nil) {
    if (n->key == key) {
      n->next->prev = n->prev;
      n->prev->next = n->next;
      return;
    }
    n = n->next;
  }
}

void delete_first() {
  if (nil->next == nil) return;
  nil->next->next->prev = nil;
  nil->next = nil->next->next;
  free(nil->next);
}

void delete_last() {
  nil->prev = nil->prev->prev;
  nil->prev->next = nil;
}

void print() {
  Node *n = nil->next;
  long cnt = 0;
  while (1) {
    if (n == nil) break;
    if (cnt++) cout << ' ';
    cout << n->key;
    n = n->next;
  }
  cout << endl;
}

int main() {
  long n;
  init();
  cin >> n;

  for (int i = 0; i < n; i++) {
    string o;
    long k;
    cin >> o;
    if (o == "insert") {
      cin >> k;
      insert(k);
    } else if (o == "delete") {
      cin >> k;
      delete_node(k);
    } else if (o == "deleteFirst") {
      delete_first();
    } else {
      delete_last();
    }
  }
  print();
}
