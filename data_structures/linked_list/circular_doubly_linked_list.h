#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;

  Node() : data(0), next(nullptr), prev(nullptr) {};
  Node(int data) : data(data), next(nullptr), prev(nullptr) {};
};

class CircularDoublyLinkedList
{
private:
  Node *first;
  Node *last;
  int size;

public:
  CircularDoublyLinkedList() : first(nullptr), last(nullptr), size(0) {};
  CircularDoublyLinkedList(int data)
  {
    Node *newNode = new Node(data);
    newNode->next = newNode;
    newNode->prev = newNode;
    first = newNode;
    last = newNode;
    size = 1;
  };

  void add(int data)
  {
    Node *newNode = new Node(data);
    size++;

    if (!first)
    {
      newNode->next = newNode;
      newNode->prev = newNode;
      first = last = newNode;
      return;
    }

    newNode->prev = last;
    newNode->next = first;

    last->next = newNode;
    first->prev = newNode;

    // update the last
    last = newNode;
  }

  int length() const { return size; }

  void printList()
  {
    Node *curr = first;

    cout << curr->data << " ";
    curr = curr->next;
    while (curr != first)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }

    cout << endl;
  }

  void printReverse()
  {
    Node *curr = last;

    cout << curr->data << " ";
    curr = curr->prev;
    while (curr != last)
    {
      cout << curr->data << " ";
      curr = curr->prev;
    }

    cout << endl;
  }

  void remove(int toRemove)
  {
    // if the list is empty
    if (!first)
    {
      cout << "List is empty!" << endl;
      return;
    }

    Node *curr = first;

    // remove the node at the start
    if (curr->data == toRemove)
    {
      if (first == last)
      {
        delete curr;
        first = last = nullptr;
      }
      else
      {
        first = curr->next;
        first->prev = last;
        last->next = first;
        delete curr;
      }
      size--;
      return;
    }

    // remove the node in the middle or the end
    curr = curr->next;
    while (curr != first)
    {
      if (curr->data == toRemove)
      {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        // If we removed the last node, update the last pointer
        if (curr == last)
        {
          last = curr->prev;
        }

        delete curr;
        size--;
        return;
      }
      curr = curr->next;
    }
    cout << "Node with value " << toRemove << " not found!" << endl;
  }

  void insertAt(int index, int data)
  {
    if (index < 0 || index > size)
    {
      cout << "Invalid index!" << endl;
      return;
    }

    if (index == size)
    {
      add(data); // take care of the size
      return;
    }

    Node *newNode = new Node(data);
    if (index == 0)
    {
      newNode->next = first;
      newNode->prev = last;
      first->prev = newNode;
      last->next = newNode;
      // update first
      first = newNode;
      size++;
      return;
    }

    Node *curr = first;
    for (int i = 0; i < index - 1; i++)
    {
      curr = curr->next;
    }

    newNode->next = curr->next;
    newNode->prev = curr;

    curr->next = newNode;
    curr->next->prev = newNode;
    size++;
  }

  int find(int data)
  {
    Node *curr = first;
    int index = 0;
    if (curr->data == data)
    {
      return index;
    }

    curr = curr->next;
    index++;
    while (curr != first)
    {
      if (curr->data == data)
      {
        return index;
      }
      curr = curr->next;
      index++;
    }
    return -1;
  }

  bool contains(int data)
  {
    Node *curr = first;

    do
    {
      if (curr->data == data)
      {
        return true;
      }
      curr = curr->next;
    } while (curr != first);
    return false;
  }

  void clear()
  {
    if (first == nullptr)
    {
      return; // List is already empty
    }

    Node *curr = first;
    Node *temp = nullptr;

    do
    {
      temp = curr;
      curr = curr->next;
      delete temp;
    } while (curr != first);

    first = last = nullptr;
    size = 0;
  }

  void reverse()
  {
    if (first == nullptr || first->next == first)
    {
      return;
    }

    Node *curr = first;
    Node *temp = nullptr;

    do
    {
      temp = curr->prev;
      curr->prev = curr->next;
      curr->next = temp;

      curr = curr->next;
    } while (curr != first);

    // udpate first and last pointers after reversal
    temp = first;
    first = last;
    last = temp;
  }

  void merge(CircularDoublyLinkedList &other)
  {
    if (other.isEmpty())
      return;

    if (isEmpty())
    {
      first = other.first;
      last = other.last;
      size = other.size;
      return;
    }

    last->next = other.first;
    other.first->prev = last;
    first->prev = last;
    other.last->next = first;

    size += other.size;
    other.first = other.last = nullptr;
    other.size = 0;
  }

  CircularDoublyLinkedList clone() const
  {
    CircularDoublyLinkedList newList;

    if (isEmpty())
      return newList;

    Node *curr = first;

    do
    {
      newList.add(curr->data);
      curr = curr->next;
    } while (curr != first);

    return newList;
  }

  bool isEmpty() const { return size == 0; }

  Node *getFirst() const { return first; }

  Node *getLast() const { return last; }

  int peekFirst() const
  {
    if (first)
    {
      return first->data;
    }
    return -1; // indicating list empty
  }

  int peekLast() const
  {
    if (last)
    {
      return last->data;
    }
    return -1;
  }

  void insertAfter(int target, int data)
  {
    if (isEmpty())
    {
      cout << "List is empty!" << endl;
      return;
    }

    Node *curr = first;
    do
    {
      if (curr->data == target)
      {
        Node *newNode = new Node(data);

        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;

        if (curr == last)
        {
          last = newNode;
        }

        size++;
        return;
      }
    } while (curr != first);

    cout << "Target not foun!" << endl;
  }

  ~CircularDoublyLinkedList()
  {
    clear();
  }
};

#endif