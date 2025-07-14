#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int data) : data(data), next(nullptr) {};
};

class LinkedListStack
{
private:
  Node *top;
  int size;

public:
  LinkedListStack() : top(nullptr), size(0) {};
  LinkedListStack(int data)
  {
    top = new Node(data);
    size = 1;
  }

  // copy constructor
  LinkedListStack(const LinkedListStack &other)
  {
    top = nullptr;
    Node *curr = other.top;
    size = other.size;
    Node *tail = nullptr; // need to copy it properly, without you will copy in reverse order.

    while (curr)
    {
      Node *newNode = new Node(curr->data);

      if (!top)
      {
        top = newNode;
        tail = newNode;
      }
      else
      {
        tail->next = newNode;
        tail = newNode;
      }

      curr = curr->next;
    }
  }

  // copy assignment operator
  LinkedListStack &operator=(const LinkedListStack &other)
  {
    if (this == &other)
      return *this;

    clear(); // delete current nodes

    Node *curr = other.top;
    size = other.size;
    Node *tail = nullptr;

    while (curr)
    {
      Node *newNode = new Node(curr->data);
      if (!top)
      {
        top = newNode;
        tail = top;
      }
      else
      {
        tail->next = newNode;
        tail = newNode;
      }
      curr = curr->next;
    }
    return *this;
  }

  // Move constructor
  LinkedListStack(LinkedListStack &&other)
  {
    top = other.top;     // steal other's chain
    size = other.size; 
    other.size = 0;
    other.top = nullptr; // empty out other
  }

  void push(int data)
  {
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
    size++;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack overflow!" << endl;
      return -1;
    }

    int popped = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    size--;
    return popped;
  }

  int peek() const
  {
    if (isEmpty())
    {
      cout << "Stack Underflow!" << endl;
      return -1;
    }

    return top->data;
  }

  bool isEmpty() const
  {
    return top == nullptr;
  }

  void clear()
  {
    while (!isEmpty())
    {
      pop();
    }
    size = 0;
  }

  int length() const { return size; }

  ~LinkedListStack()
  {
    clear();
  }

  // operator <<  overloaded to print the stack
  friend ostream &operator<<(ostream &os, const LinkedListStack &stack)
  {
    if (stack.isEmpty())
    {
      os << "Stack is empty!";
      return os;
    }

    Node *curr = stack.top;
    while (curr)
    {
      os << curr->data << " ";
      curr = curr->next;
    }

    return os;
  }
};

#endif