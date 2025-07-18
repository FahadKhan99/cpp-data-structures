#ifndef PRIORITY_QUEUE_HEAP_H
#define PRIORITY_QUEUE_HEAP_H

/*

BT representation in array:
  Parent: (i - 1) / 2
  Left child: 2 * i + 1
  Right child: 2 * i + 2


TC:
  enqueue: O(log n)
  dequeue: O(log n)
  peek: O(1)

*/

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class PriorityQueue
{
private:
  struct Node
  {
    T data;
    int priority;

    Node(const T &data, int priority) : data(data), priority(priority) {};

    // for comparison (max heap)
    bool operator<(const Node &other) const
    {
      return priority < other.priority;
    }

    // For comparison (min heap)
    bool operator>(const Node &other) const
    {
      return priority > other.priority;
    }
  };

  // vector to store binary tree (heap)
  std::vector<Node>
      heap;

  // Heapify up
  void bubbleUp(int index)
  {
    while (index > 0)
    {
      int parent = (index - 1) / 2;

      if (heap[index] < heap[parent])
        break;

      std::swap(heap[index], heap[parent]);
      index = parent;
    }
  }

  // Heapify down
  void bubbleDown(int index)
  {
    int size = heap.size();

    while (index < size)
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      int largest = index;

      if (left < size && heap[largest] < heap[left])
        largest = left;

      if (right < size && heap[largest] < heap[right])
        largest = right;

      if (largest == index)
        break; // breaks the infinite loop

      std::swap(heap[index], heap[largest]);
      index = largest;
    }
  }

public:
  void enqueue(const T &data, int priority)
  {
    heap.emplace_back(data, priority); // create node and then store.
    bubbleUp(heap.size() - 1);
  }

  T dequeue()
  {
    if (heap.empty())
    {
      throw std::runtime_error("PriorityQueue is empty");
    }

    T result = heap[0].data; // head
    heap[0] = heap.back();   // last element to head
    heap.pop_back();         // pop out that last element
    bubbleDown(0);           // restore heap property
    return result;
  }

  const T &peek() const
  {
    if (heap.empty())
    {
      throw std::runtime_error("PriorityQueue is empty");
    }

    return heap[0].data;
  }

  bool isEmpty() const
  {
    return heap.empty();
  }

  void print() const
  {
    for (const auto &item : heap)
    {
      std::cout << "[" << item.data << ", p=" << item.priority << "] ";
    }
    std::cout << "\n";
  }

  int length() const { return heap.size() }
};

#endif