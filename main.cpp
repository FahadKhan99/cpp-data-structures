#include "avl_tree.h"

int main()
{
  try
  {
    AVLTree<int> tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10); // Should trigger LL
    tree.insert(25); // LR
    tree.insert(40);
    tree.insert(50); // RR
    tree.insert(45); // RL

    std::cout << "In-order traversal (should be sorted): ";
    tree.inorder();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << '\n';
  }

  return 0;
}
