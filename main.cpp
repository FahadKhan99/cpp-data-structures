#include "priority_queue_heap.h"
#include <string>

int main()
{
  PriorityQueue<std::string> pq;
  pq.enqueue("Low", 1);
  pq.enqueue("Medium", 5);
  pq.enqueue("High", 10);
  pq.enqueue("Top", 15);

  pq.print();

  std::cout << "Peek: " << pq.peek() << "\n";

  while (!pq.isEmpty())
  {
    std::cout << "Dequeued: " << pq.dequeue() << "\n";
  }
}