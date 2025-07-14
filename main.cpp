// #include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "array_stack.h"

int main()
{
  ArrayStack s1(5); // Create first stack
  s1.push(10);
  s1.push(20);

  ArrayStack s2(5); // Create second stack
  s2.push(1);
  s2.push(2);
  s2.push(3);

  s2 = s1; // 👈 This calls your operator= !

  s1.push(30); // Modify s1 only

  // Test: s2 is unchanged — deep copy!
  cout << s1 << endl; // Should show: 10 20 30
  cout << s2 << endl; // Should show: 10 20
  return 0;
}
