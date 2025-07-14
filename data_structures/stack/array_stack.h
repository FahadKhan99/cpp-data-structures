#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
using namespace std;

class ArrayStack
{
private:
  int *stack;
  int capacity;
  int top;

public:
  ArrayStack(int size)
  {
    capacity = size;
    stack = new int[capacity];
    top = -1;
  }

  ~ArrayStack()
  {
    delete[] stack;
  }

  void push(int data)
  {
    if (isFull())
    {
      cout << "Stack Overflow!" << endl;
      return;
    }

    stack[++top] = data;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack Underflow!" << endl;
      return -1;
    }
    return stack[top--];
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "Stack Underflow!" << endl;
      return -1;
    }
    return stack[top];
  }

  void print()
  {
    if (isEmpty())
    {
      cout << "Stack is empty!" << endl;
      return;
    }

    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
    {
      cout << stack[i] << " ";
    }
    cout << endl;
  }

  void reverse()
  {
    for (int i = 0; i < size() / 2; i++)
    {
      int temp = stack[i];
      stack[i] = stack[top - i];
      stack[top - i] = temp;
    }
  }

  bool isFull() const
  {
    return top == capacity - 1;
  }

  bool isEmpty() const
  {
    return top == -1;
  }

  int size() const { return top + 1; }

  void clear()
  {
    top = -1;
  }

  bool contains(int data) const
  {
    for (int i = 0; i <= top; i++)
    {
      if (stack[i] == data)
      {
        return true;
      }
    }
    return false;
  }

  int remainingSpace() const
  {
    return capacity - (top + 1);
  }

  // some advance stuff ->
  // s2 = s1;     basically deep copy just using "="
  ArrayStack &operator=(const ArrayStack &other)
  {
    if (this == &other) // comparing the address
    {
      return *this;
    }

    delete[] stack;

    this->capacity = other.capacity;
    this->top = other.top;

    stack = new int[capacity];
    for (int i = 0; i <= top; i++)
    {
      stack[i] = other.stack[i];
    }

    return *this; // returning the object
  }

  // cout << myStack; <- will print
  friend ostream &operator<<(ostream &os, const ArrayStack &stack);
};

// basically overloads the default defination of the output stream package
ostream &operator<<(ostream &os, const ArrayStack &stack)
{
  if (stack.isEmpty())
  {
    os << "Stack is empty!";
    return os;
  }

  os << "Stack (top to bottom): ";
  for (int i = stack.top; i >= 0; i--)
  {
    os << stack.stack[i] << " ";
  }

  return os;
}

#endif