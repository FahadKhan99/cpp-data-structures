#include<vector>
#include "avl_tree.h"

int main()
{
  try
  {
    AVLTree<int> tree;

    std::vector<int> values = {30, 20, 40, 10, 25, 35, 50, 5, 15, 45};
    for (int v : values)
      tree.insert(v);

    std::cout << "In-order before deletion: ";
    tree.inorder(); // Should be sorted

    std::cout << "\nContains 25? " << (tree.contains(25) ? "Yes" : "No") << "\n";
    std::cout << "Min: " << *tree.min() << ", Max: " << *tree.max() << "\n";

    tree.remove(20);
    tree.remove(40);

    std::cout << "In-order after deleting 20 and 40: ";
    tree.inorder(); // Still sorted and balanced
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << '\n';
  }

  return 0;
}
