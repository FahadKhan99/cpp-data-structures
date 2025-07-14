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
      cout << "Stack Underdflow!" << endl;
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