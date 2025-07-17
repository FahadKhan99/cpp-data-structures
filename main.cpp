#include "priority_queue_list.h"
#include <string>

int main()
{
  PriorityQueue<std::string> pq;

  pq.enqueue("eat", 2);
  pq.enqueue("code", 5);
  pq.enqueue("sleep", 3);

  pq.print(); // Print raw contents

  std::cout << "Peek: " << pq.peek() << "\n";

  std::cout << "Dequeued: " << pq.dequeue() << "\n";
  std::cout << "Dequeued: " << pq.dequeue() << "\n";
  std::cout << "Dequeued: " << pq.dequeue() << "\n";

  return 0;
}
