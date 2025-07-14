#include "singly_linked_list.h"
#include "doubly_linked_list.h"

int main()
{
  SinglyLinkedList list;

  list.add(5);
  list.add(1);
  list.add(2);
  list.add(3);
  list.add(5);

  cout << "Original: ";
  list.printList();

  cout << "Find 3: " << list.find(3) << endl;

  list.insertAt(2, 42);
  cout << "After inserting 42 at index 2: ";
  list.printList();

  cout << "Reversed: ";
  list.reverse();
  list.printList();

  cout << "Clearing list..." << endl;
  list.clear();
  cout << "Size after clear: " << list.length() << endl;

  return 0;
}
