/*
  the following two lines tells the compiler
  ifndef -> if not defined DOUBLY_LINKED_LIST_H then 
  define -> define DOUBLY_LINKED_LIST_H
*/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;

  Node() : data(0), next(nullptr), prev(nullptr) {}
  Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
  Node *first;
  Node *last;
  int size;

public:
  DoublyLinkedList() : first(nullptr), last(nullptr), size(0) {};

  void add(int data)
  {
    Node *newNode = new Node(data);
    size++;

    if (!first && !last)
    {
      first = newNode;
      last = newNode;
      return;
    }

    Node *curr = first;
    while (curr->next)
    {
      curr = curr->next;
    }

    newNode->prev = curr;
    curr->next = newNode;

    last = newNode;
  }

  int length() const { return size; }

  void printList()
  {
    Node *curr = first;
    while (curr)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
  }

  void printListReverse()
  {
    Node *curr = last;
    while (curr)
    {
      cout << curr->data << " ";
      curr = curr->prev;
    }
    cout << endl;
  }

  // dont need dummy here
  void remove(int toRemove)
  {
    Node *curr = first;

    while (curr)
    {
      if (curr->data == toRemove)
      {
        Node *removed = curr;

        if (removed->prev)
          removed->prev->next = removed->next;
        else
          first = removed->next;

        if (removed->next)
          removed->next->prev = removed->prev;
        else
          last = removed->prev;

        curr = removed->next;
        delete removed;
        size--;
      }
      else
      {
        curr = curr->next;
      }
    }
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
      add(data);
      return;
    }

    Node *newNode = new Node(data);

    if (index == 0)
    {
      newNode->next = first;
      if (first)
        first->prev = newNode;
      first = newNode;
      if (size == 0)
      {
        last = newNode;
      }
      size++;
      return;
    }

    Node *curr = first;
    for (int i = 0; i < index - 1; i++)
    {
      curr = curr->next;
    }

    newNode->prev = curr;
    newNode->next = curr->next;
    if (curr->next)
      curr->next->prev = newNode;
    curr->next = newNode;

    size++;
  }

  int find(int data)
  {
    Node *curr = first;
    int index = 0;
    while (curr)
    {
      if (curr->data == data)
        return index;
      index++;
      curr = curr->next;
    }

    return -1;
  }

  // to delete all nodes
  void clear()
  {
    Node *curr = first;
    while (curr)
    {
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }
    first = last = nullptr;
    size = 0;
  }

  void reverse()
  {
    Node *curr = first;
    Node *temp = nullptr;

    while (curr)
    {
      temp = curr->prev;
      curr->prev = curr->next;
      curr->next = temp;

      // increase
      curr = curr->prev;
    }

    if (temp)
    {
      temp = first;
      first = last;
      last = temp;
    }
  }

  ~DoublyLinkedList()
  {
    clear();
  }
};

#endif