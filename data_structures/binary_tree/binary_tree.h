#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <stdexcept>
#include <memory>
#include <stack>
#include <queue>

template <typename T>
class BinaryTree
{
private:
  struct Node
  {
    T data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(const T &data) : data(data), left(nullptr), right(nullptr) {};
  };

  std::unique_ptr<Node> root;

  void insertHelper(std::unique_ptr<Node> &node, const T &data)
  {
    if (!node)
    {
      node = std::make_unique<Node>(data);
    }
    else if (data < node->data)
    {
      insertHelper(node->left, data);
    }
    else if (data > node->data)
    {
      insertHelper(node->right, data);
    }
  }

  size_t countNodes(const std::unique_ptr<Node> &node) const
  {
    if (!node)
      return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
  }

  void preorderHelper(const std::unique_ptr<Node> &node) const
  {
    if (node)
    {
      std::cout << node->data << " ";
      preorderHelper(node->left);
      preorderHelper(node->right);
    }
  }

  void postorderHelper(const std::unique_ptr<Node> &node) const
  {
    if (node)
    {
      postorderHelper(node->left);
      postorderHelper(node->right);
      std::cout << node->data << " ";
    }
  }

  void inorderHelper(const std::unique_ptr<Node> &node) const
  {
    if (node)
    {
      inorderHelper(node->left);
      std::cout << node->data << " ";
      inorderHelper(node->right);
    }
  }

  // Helper: copy tree
  std::unique_ptr<Node> copyTree(const std::unique_ptr<Node> &node)
  {
    if (!node)
      return nullptr;

    auto newNode = std::make_unique<Node>(node->data);
    newNode->left = copyTree(newNode->left);
    newNode->right = copyTree(newNode->right);
    return newNode;
  }

public:
  BinaryTree() = default;
  ~BinaryTree() = default;

  // copy constructor
  BinaryTree(const BinaryTree &other)
  {
    root = copyTree(other.root);
  }

  // Copy assignment
  BinaryTree operator=(const BinaryTree &other)
  {
    if (this == &other)
    {
      root = copyTree(other.root);
    }
    return *this;
  }

  // Move constructor
  BinaryTree(BinaryTree &&other) noexcept = default;

  // Move assignment
  BinaryTree &operator=(BinaryTree &&other) noexcept = default;

  void insert(const T &data)
  {
    insertHelper(root, data);
  }

  const std::unique_ptr<Node> &getRoot() const
  {
    return root;
  }

  void printInOrder() const
  {
    inorderHelper(root);
    std::cout << std::endl;
  }

  void printPreOrder() const
  {
    preorderHelper(root);
    std::cout << std::endl;
  }

  void printPostOrder() const
  {
    postorderHelper(root);
    std::cout << std::endl;
  }

  void printLevelOrder() const
  {
    if (!root)
      return;
    std::queue<const Node *> q;
    q.push(root.get());
    while (!q.empty())
    {
      const Node *current = q.front();
      q.pop();
      std::cout << current->data << " ";
      if (current->left)
        q.push(current->left.get());
      if (current->right)
        q.push(current->right.get());
    }
    std::cout << std::endl;
  }

  void printReverseLevelOrder() const
  {
    if (!root)
      return;

    std::stack<const Node *> st;
    st.push(root.get());
    while (!st.empty())
    {
      const Node *current = st.pop();
      std::cout << current->data << " ";
      if (current->left)
        st.push(current->left.get());
      if (current->right)
        st.push(current->right.get());
    }
    std::cout << std::endl;
  }

  // Utility

  bool contains(const T &value) const
  {
    const Node *curr = root.get();
    while (curr)
    {
      if (curr->data == value)
        return true;
      curr = value < curr->data ? curr->left.get() : curr->right.get();
    }
    return false;
  }

  int heightHelper(const std::unique_ptr<Node> &node) const
  {
    if (!node)
      return -1;
    return 1 + std::max(heightHelper(node->left), heightHelper(node->right));
  }

  int height() const
  {
    return heightHelper(root);
  }

  const T &minValue() const
  {
    if (!root)
      throw std::runtime_error("Tree is empty");
    const Node *current = root.get();
    while (current->left)
      current = current->left.get();
    return current->data;
  }

  const T &maxValue() const
  {
    if (!root)
      throw std::runtime_error("Tree is empty");
    const Node *current = root.get();
    while (current->right)
      current = current->right.get();
    return current->data;
  }

  bool isEmpty() const
  {
    return !root;
  }

  void clear()
  {
    root.reset();
  }

  bool isBalancedHelper(const std::unique_ptr<Node> &node, int &height) const
  {
    if (!node)
    {
      height = -1;
      return true;
    }
    int lh, rh;
    if (!isBalancedHelper(node->left, lh) || !isBalancedHelper(node->right, rh))
      return false;
    height = 1 + std::max(lh, rh);
    return std::abs(lh - rh) <= 1;
  }

  bool isBalanced() const
  {
    int h;
    return isBalancedHelper(root, h);
  }

  void toSortedArrayHelper(const std::unique_ptr<Node> &node, std::vector<T> vec) const
  {
    if (!node)
      return;
    toSortedArrayHelper(node->left, vec);
    vec.push_back(node->data);
    toSortedArrayHelper(node->right, vec);
  }

  std::vector<T> toSortedArray() const
  {
    std::vector<T> result;
    toSortedArrayHelper(root, result);
    return result;
  }

  // Modification Operations

  std::unique_ptr<Node> &findMin(std::unique_ptr<Node> &node)
  {
    return node->left ? findMin(node->left) : node;
  }

  void removeHelper(std::unique_ptr<Node> &node, const T &value)
  {
    if (!node)
      return;
    if (value < node->data)
      removeHelper(node->left, value);
    else if (value > node->data)
      removeHelper(node->right, value);
    else
    {
      if (!node->left)
        node = std::move(node->right);
      else if (!node->right)
        node = std::move(node->left);
      else
      {
        // both of them exists.
        std::unique_ptr<Node> &minNode = findMin(node->right); // to follow the in-order property
        node->data = minNode->data;
        // the minNode is now getting duplicate delete
        removeHelper(node->right, minNode->data);
      }
    }
  }

  void remove(const T &value)
  {
    removeHelper(root, value);
  }

  void invertHelper(std::unique_ptr<Node> &node)
  {
    if (!node)
      return;
    std::swap(node->left, node->right);
    invertHelper(node->left);
    invertHelper(node->right);
  }

  void invert()
  {
    invertHelper(root);
  }

  BinaryTree clone() const
  {
    BinaryTree copy;
    copy.root = copyTree(root);
    return copy;
  }

  // leaf, Internal, Diameter

  size_t leafCountHelper(const std::unique_ptr<Node> &node) const
  {
    if (!node)
      return 0;
    if (!node->left && !node->right)
      return 1;
    return (leafCountHelper(node->right) + leafCountHelper(node->left));
  }

  size_t leafCount() const
  {
    return leafCountHelper(root);
  }

  size_t internalCountHelper(const std::unique_ptr<Node> &node) const
  {
    if (!node || (!node->left && !node->right))
      return 0;
    return 1 + internalCountHelper(node->left) + internalCountHelper(node->right);
  }

  size_t internalCount() const
  {
    return internalCountHelper(root);
  }

  // Diameter is the longest path between the two nodes (may or may not include root)
  // NOTE -> measure in edges not node
  int diameterHelper(const std::unique_ptr<Node> &node, int &diameter) const
  {
    if (!node)
      return -1;
    int lh = diameterHelper(node->left, diameter);
    int rh = diameterHelper(node->right, diameter);
    diameter = std::max(diameter, lh + rh + 2); // + 2 to represent the edge connecting the two nodes (one left, one right)
    return 1 + std::max(lh, rh);
  }

  int diameter() const
  {
    int dia = 0;
    diameterHelper(root, dia);
    return dia;
  }

  size_t length() const
  {
    return countNodes(root);
  }
};

#endif
