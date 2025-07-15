#include "linked_list_queue.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  try {
    LinkedListQueue<string> q;

    // Test enqueue
    q.enqueue("Alice");
    q.enqueue("Bob");
    q.enqueue("Charlie");

    cout << "Initial queue: " << q << endl;

    // Test copy constructor
    LinkedListQueue<string> copyQ = q;
    cout << "Copy constructed queue: " << copyQ << endl;

    // Test dequeue
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Queue after dequeue: " << q << endl;

    // Test peek
    cout << "Peek: " << q.peek() << endl;

    // Test copy assignment
    LinkedListQueue<string> assignQ;
    assignQ.enqueue("OldData");
    cout << "Before copy assignment, assignQ: " << assignQ << endl;
    assignQ = q;
    cout << "After copy assignment, assignQ: " << assignQ << endl;

    // Test move constructor
    LinkedListQueue<string> movedQ = std::move(assignQ);
    cout << "Moved queue: " << movedQ << endl;
    cout << "assignQ after move: " << assignQ << endl;

    // Test clear & exception
    q.clear();
    cout << "q after clear: " << q << endl;
    cout << "Trying to peek empty queue:" << endl;
    cout << q.peek() << endl; // This should throw

  } catch (const std::underflow_error &e) {
    cerr << "Caught exception: " << e.what() << endl;
  } catch (const exception &e) {
    cerr << "Caught unexpected exception: " << e.what() << endl;
  }

  return 0;
}
