#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

// Front -> 1 - 2 - 3 - 4 <- Rear

#include <iostream>
using namespace std;

class ArrayQueue
{
private:
  int *queue;
  int capacity;
  int front;
  int rear;
  int count;

public:
  ArrayQueue(int size)
  {
    capacity = size;
    queue = new int[capacity];
    front = 0;
    rear = -1;
    count = 0;
  }

  ArrayQueue(const ArrayQueue &other)
  {
    capacity = other.capacity;
    count = other.count;
    front = other.front;
    rear = other.rear;

    queue = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
      queue[i] = other.queue[i];
    }
  }

  ArrayQueue &operator=(const ArrayQueue &other)
  {
    if (this == &other)
    {
      return *this;
    }

    delete[] queue;

    capacity = other.capacity;
    count = other.count;
    front = other.front;
    rear = other.rear;

    queue = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
      queue[i] = other.queue[i];
    }

    return *this;
  }

  ~ArrayQueue()
  {
    delete[] queue;
  }

  void enqueue(int data)
  {
    if (isFull())
    {
      cout << "Queue Overflow!" << endl;
      return;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = data;
    count++;
  }

  int dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue Underflow!" << endl;
      return -1;
    }
    int item = queue[front];
    count--;
    front = (front + 1) % capacity;
    return item;
  }

  int peek() const
  {
    if (isEmpty())
    {
      cout << "Queue Underflow!" << endl;
      return -1;
    }
    return queue[front];
  }

  bool isFull() const
  {
    return count == capacity;
  }

  bool isEmpty() const
  {
    return count == 0;
  }

  int length() const { return count; }

  void clear()
  {
    front = 0;
    rear = -1;
    count = 0;
  }

  friend ostream &operator<<(ostream &os, const ArrayQueue &q)
  {
    if (q.isEmpty())
    {
      os << "Queue is empty!" << endl;
      return os;
    }

    os << "Queue (front to rear): ";
    int k = q.front;
    for (int i = 0; i < q.count; i++)
    {
      os << q.queue[k] << " ";
      k = (k + 1) % q.capacity;
    }

    return os;
  }
};

#endif