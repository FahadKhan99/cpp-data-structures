#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

/*

unique_ptr = unique ownership.

.get() = access without taking ownership.

std::move = transfer the ownership.

*/

#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

template <typename T>
class LinkedListQueue
{
private:
  struct Node
  {
    T data;
    unique_ptr<Node> next;

    Node(const T data) : data(data), next(nullptr) {}
  };
  unique_ptr<Node> front;
  Node *rear; // Rear is raw because unique_ptr can't have multiple owners
  int count;

public:
  // default constructor
  LinkedListQueue() : front(nullptr), rear(nullptr), count(0) {}

  // custom constructor
  LinkedListQueue(T data)
  {
    Node *newNode = new Node(data);
    front = newNode;
    rear = newNode;
  }
  // copy constructor
  LinkedListQueue(const LinkedListQueue &other) : front(nullptr), rear(nullptr), count(0)
  {
    Node *curr = other.front.get();
    while (curr)
    {
      enqueue(curr->data);
      curr = curr->next.get();
    }
  }

  // copy assignment constructor
  LinkedListQueue &operator=(LinkedListQueue &other)
  {
    if (this == &other)
      return *this;

    clear();

    Node *curr = other.front.get();
    while (curr)
    {
      enqueue(curr->data);
      curr = curr->next.get();
    }
    return *this;
  }

  // move constructor
  LinkedListQueue(LinkedListQueue &&other) noexcept : front(std::move(other.front)), rear(other.rear), count(other.count)
  {
    other.rear = nullptr;
    other.count = 0;
    // question => why not other.front = nullptr
    // answer => we are moving the entire same memory of the other.front to the current one so no need to expicitly null them
  }

  // move assignment operator
  LinkedListQueue &operator=(LinkedListQueue &&other) noexcept
  {
    if (this == &other)
      return *this;

    clear();
    front = std::move(other.front);
    rear = other.rear;
    count = other.count;

    other.rear = nullptr;
    other.count = 0;

    return *this;
  }

  // destructor
  ~LinkedListQueue()
  {
    clear();
  }

  void enqueue(const T &data)
  {
    auto newNode = make_unique<Node>(data);

    if (isEmpty())
    {
      front = std::move(newNode);
      rear = front.get();
    }
    else
    {
      rear->next = std::move(newNode);
      rear = rear->next.get();
    }
    ++count;
  }

  T dequeue()
  {
    if (isEmpty())
    {
      throw underflow_error("Queue Underflow!");
    }

    T value = front->data;
    front = std::move(front->next);

    if (!front)
      rear = nullptr;

    --count;
    return value;
  }

  const T &peek() const
  {
    if (isEmpty())
    {
      throw underflow_error("Queue is empty!");
    }

    return front->data;
  }

  bool isEmpty() const { return count == 0; }
  void clear()
  {
    while (front)
    {
      front = std::move(front->next);
    }
    rear = nullptr;
    count = 0;
  }

  friend ostream &operator<<(ostream &os, const LinkedListQueue &q)
  {
    if (q.isEmpty())
    {
      os << "Queue is empty!";
      return os;
    }
    os << "Queue (front to rear): ";
    Node *curr = q.front.get();
    while (curr)
    {
      os << curr->data << " ";
      curr = curr->next.get();
    }
    return os;
  }
};
#endif