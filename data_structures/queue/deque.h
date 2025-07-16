#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
class Deque
{
private:
  struct Node
  {
    T data;
    std::unique_ptr<Node> next;
    Node *prev;

    Node(const T &data) : data(data), next(nullptr), prev(nullptr) {};
  };
  std::unique_ptr<Node> front;
  Node *rear;

  // copy helper
  std::unique_ptr<Node> copyNodes(const std::unique_ptr<Node> &otherFront, Node **newRear)
  {
    // Node** newRear <- is pointer to pointer (rear)
    if (!otherFront)
    {
      *newRear = nullptr;
      return nullptr;
    }

    auto newFront = std::make_unique<Node>(otherFront->data);
    Node *currOld = otherFront.get(); // pointing to old queue
    Node *currNew = newFront.get();   // pointing to new queue

    while (currOld->next)
    {
      currNew->next = std::make_unique<Node>(currOld->next->data);
      currNew->next->prev = currNew;

      currOld = currOld->next.get();
      currNew = currNew->next.get();
    }
    *newRear = currNew;
    return newFront;
  }

public:
  Deque() : front(nullptr), rear(nullptr) {};

  ~Deque() = default;

  // copy constructor
  Deque(const Deque &other)
  {
    front = copyNodes(other.front, &rear);
  }

  // copy assignment
  Deque &operator=(const Deque &other)
  {
    if (this != &other)
    {
      front = copyNodes(other.front, &rear);
    }
    return *this;
  }

  // move constructor
  Deque(Deque &&other) noexcept
      : front(std::move(other.front)), rear(other.rear)
  {
    other.rear = nullptr;
  }

  // Move Assignment
  Deque &operator=(Deque &&other) noexcept
  {
    if (this != &other)
    {
      front = std::move(other.front);
      rear = other.rear;
      other.rear = nullptr;
    }
    return *this;
  }

  void insertFront(const T &data)
  {
    auto newNode = std::make_unique<Node>(data);
    if (!front)
    {
      rear = newNode.get();
    }
    else
    {
      front->prev = newNode.get();
      newNode->next = std::move(front);
    }
    front = std::move(newNode);
  }

  void insertRear(const T &data)
  {
    auto newNode = std::make_unique<Node>(data);
    if (!front)
    {
      front = std::move(newNode);
      rear = front.get();
    }
    else
    {
      rear->next = std::move(newNode);
      rear->next->prev = rear;
      rear = rear->next.get();
    }
  }

  void deleteFront()
  {
    if (!front)
      throw std::runtime_error("List is empty");

    if (front.get() == rear)
    {
      front.reset();
      rear = nullptr;
    }
    else
    {
      front = std::move(front->next);
      front->prev = nullptr;
    }
  }

  void deleteRear()
  {
    if (!front)
      throw std::runtime_error("List is empty");

    if (front.get() == rear)
    {
      front.reset();
      rear = nullptr;
    }
    else
    {
      rear = rear->prev;
      rear->next.reset();
    }
  }

  T getFront() const
  {
    if (isEmpty())
      throw std::runtime_error("Deque is empty");
    return front->data;
  }

  T getRear() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Deque is empty");
    }
    return rear->data;
  }

  bool isEmpty() const
  {
    return !front;
  }

  void displayForward() const
  {
    Node *curr = front.get();
    while (curr)
    {
      std::cout << curr->data << " ";
      curr = curr->next.get();
    }
    std::cout << std::endl;
  }

  void displayBackward() const
  {
    Node *curr = rear;
    while (curr)
    {
      std::cout << curr->data << " ";
      curr = curr->prev;
    }
    std::cout << std::endl;
  }
};

#endif