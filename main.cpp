#include "array_queue.h"

int main() {
  ArrayQueue q(5);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);

  q.dequeue();
  q.dequeue();

  q.enqueue(6);
  q.enqueue(7);
  q.enqueue(8);
  cout << "Size: " << q.length() << endl;
  cout << q << endl;

  return 0;
}
