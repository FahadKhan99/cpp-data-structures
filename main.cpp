#include <iostream>
#include "binary_tree.h"

int main() {
  BinaryTree<int> bst;

  // Insert elements
  bst.insert(10);
  bst.insert(5);
  bst.insert(15);
  bst.insert(3);
  bst.insert(7);
  bst.insert(12);
  bst.insert(17);

  std::cout << "Level Order: ";
  bst.printLevelOrder();

  std::cout << "Contains 7? " << (bst.contains(7) ? "Yes" : "No") << "\n";
  std::cout << "Height: " << bst.height() << "\n";
  std::cout << "Min: " << bst.minValue() << "\n";
  std::cout << "Max: " << bst.maxValue() << "\n";
  std::cout << "Is Balanced? " << (bst.isBalanced() ? "Yes" : "No") << "\n";

  std::cout << "Leaf Count: " << bst.leafCount() << "\n";
  std::cout << "Internal Count: " << bst.internalCount() << "\n";
  std::cout << "Diameter (edges): " << bst.diameter() << "\n";

  std::vector<int> sorted = bst.toSortedArray();
  std::cout << "Sorted: ";
  for (int val : sorted) std::cout << val << " ";
  std::cout << "\n";

  bst.remove(15);
  std::cout << "After removing 15:\n";
  bst.printLevelOrder();

  bst.invert();
  std::cout << "Inverted tree (Level Order): ";
  bst.printLevelOrder();

  bst.clear();
  std::cout << "After clear, is empty? " << (bst.isEmpty() ? "Yes" : "No") << "\n";

  return 0;
}
