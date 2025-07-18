#include "binary_tree.h"

int main()
{
  BinaryTree<int> tree;

  tree.insert(10);
  tree.insert(5);
  tree.insert(20);
  tree.insert(15);
  tree.insert(25);

  tree.printInOrder(); // Output: 5 10 15 20 25
  std::cout << "Total Nodes: " << tree.length() << "\n";

  return 0;
}
