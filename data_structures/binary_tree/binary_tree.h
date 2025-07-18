#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <stdexcept>
#include <memory>

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

  size_t length() const
  {
    return countNodes(root);
  }
};

#endif
