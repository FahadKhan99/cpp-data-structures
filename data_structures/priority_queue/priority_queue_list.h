#ifndef PRIORITY_QUEUE_LIST_H
#define PRIORITY_QUEUE_LIST_H

/*
  No need to implement the rule of five, because we are not using raw pointers.

  TC:
    enqueue -> O(1)
    dequeue -> O(n)
    peek -> O(n)
  
  using heap would improve the TC
*/

#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>

template<typename T>
class PriorityQueue
{
private:
  struct Node
  {
    T data;
    int priority;

    Node(const T &data, int pri) : data(data), priority(pri) {}
  };

  std::list<std::unique_ptr<Node>> items;

public:
  void enqueue(const T &data, int priority)
  {
    items.push_back(std::make_unique<Node>(data, priority));
  }

  T dequeue()
  {
    if (items.empty())
      throw std::runtime_error("PriorityQueue is empty");

    auto maxItemIt = items.begin();
    for (auto it = items.begin(); it != items.end(); it++)
    {
      if ((*it)->priority > (*maxItemIt)->priority)
      {
        maxItemIt = it;
      }
    }

    T value = (*maxItemIt)->data;
    items.erase(maxItemIt);
    return value;
  }

  const T &peek() const
  {
    if (items.empty())
      throw std::runtime_error("PriorityQueue is empty");

    auto maxItemIt = items.begin();
    for (auto it = items.begin(); it != items.end(); it++)
    {
      if ((*it)->priority > (*maxItemIt)->priority)
      {
        maxItemIt = it;
      }
    }

    return (*maxItemIt)->data;
  }

  bool isEmpty() const
  {
    return items.empty();
  }

  void print() const
  {
    for (const auto &item : items)
    {
      std::cout << "[" << item->data << ", p=" << item->priority << "] ";
    }
    std::cout << "\n";
  }
};

#endif