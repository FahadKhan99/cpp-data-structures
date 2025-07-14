#include "linked_list_stack.h"

LinkedListStack makeStack() {
  LinkedListStack temp;
  temp.push(1);
  temp.push(2);
  return temp; // compiler will prefer move constructor
}

int main() {
  cout << "Original stack s1:\n";
  LinkedListStack s1;
  s1.push(10);
  s1.push(20);
  cout << s1 << endl;

  // 1️⃣ Copy constructor
  LinkedListStack s2 = s1;
  cout << "Copied stack s2 (copy constructor):\n";
  cout << s2 << endl;

  // 2️⃣ Copy assignment operator
  LinkedListStack s3;
  s3.push(100);
  s3.push(200);
  cout << "Before copy assignment, s3:\n";
  cout << s3 << endl;

  s3 = s1; // should deep copy from s1
  cout << "After copy assignment, s3:\n";
  cout << s3 << endl;

  // 3️⃣ Move constructor using makeStack()
  LinkedListStack s4 = makeStack(); // returns a temporary → move constructor
  cout << "s4 (move constructed from makeStack()):\n";
  cout << s4 << endl;

  // 4️⃣ Move constructor using std::move()
  LinkedListStack s5 = std::move(s1); // s1 should be empty after this
  cout << "s5 (move constructed with std::move(s1)):\n";
  cout << s5 << endl;

  cout << "s1 after move:\n";
  cout << s1 << endl;

  return 0;
}
