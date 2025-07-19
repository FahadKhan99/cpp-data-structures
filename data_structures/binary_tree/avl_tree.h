#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>

// height is 1 based

template <typename T>
class AVLTree
{
private:
  struct Node
  {
    T data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    int height;

    Node(const T &value) : data(value), left(nullptr), right(nullptr) {};
  };

  std::unique_ptr<Node> root;

  int getHeight(const std::unique_ptr<Node> &node) const
  {
    return node ? node->height : 0;
  }

  int getBalance(const std::unique_ptr<Node> &node) const
  {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
  }

  void updateHeight(std::unique_ptr<Node> &node)
  {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
  }

  std::unique_ptr<Node> rotateRight(std::unique_ptr<Node> y)
  {
    auto x = std::move(y->left);
    auto rightSubtreeOfLeftChild = std::move(x->right); // child of the x
    x->right = std::move(y);
    x->right->left = std::move(rightSubtreeOfLeftChild);

    updateHeight(x->right);
    updateHeight(x);

    return x;
  }

  std::unique_ptr<Node> rotateLeft(std::unique_ptr<Node> x)
  {
    auto y = std::move(x->right);
    auto leftSubtreeOfRightChild = std::move(y->left);
    y->left = std::move(x);
    y->left->right = std::move(leftSubtreeOfRightChild);

    updateHeight(y->left);
    updateHeight(y);

    return y;
  }

  std::unique_ptr<Node> balance(std::unique_ptr<Node> node)
  {
    updateHeight(node);
    int balanceFactor = getBalance(node);

    // Left heavy
    if (balanceFactor > 1)
    {
      if (getBalance(node->left) < 0)
      {
        node->left = rotateLeft(std::move(node->left)); // LR rotation
      }
      return rotateRight(std::move(node)); // LL rotation
    }

    // Right heavy
    else if (balanceFactor < -1)
    {
      if (getBalance(node->right) > 0)
      {
        node->right = rotateRight(std::move(node->right)); // RL rotation
      }
      return rotateLeft(std::move(node)); // RR rotation
    }

    return node; // if exactly 1 or 0
  }

  std::unique_ptr<Node> insertHelper(std::unique_ptr<Node> node, const T &value)
  {
    if (!node)
    {
      return std::make_unique<Node>(value);
    }

    if (value < node->data)
    {
      node->left = insertHelper(std::move(node->left), value);
    }
    else if (value > node->data)
    {
      node->right = insertHelper(std::move(node->right), value);
    }
    else
    {
      throw std::invalid_argument("Duplicate value not allowed in AVL Tree.");
    }

    return balance(std::move(node));
  }

  // In-order print
  void inorderHelper(const std::unique_ptr<Node> &node) const
  {
    if (!node)
      return;
    inorderHelper(node->left);
    std::cout << node->data << " ";
    inorderHelper(node->right);
  }

public:
  AVLTree() = default;
  ~AVLTree() = default;

  // no copy constructor as we are using smart pointers
  AVLTree(const AVLTree &other) = delete;
  AVLTree &operator=(const AVLTree &other) = delete;

  // move
  AVLTree(AVLTree &&) noexcept = default;
  AVLTree &operator=(AVLTree &&) noexcept = default;

  void insert(const T &value)
  {
    root = insertHelper(std::move(root), value);
  }

  void inorder()
  {
    inorderHelper(root);
    std::cout << '\n';
  }
};

#endif