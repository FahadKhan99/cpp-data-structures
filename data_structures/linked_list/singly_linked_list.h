#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node() : data(0), next(nullptr) {};
  Node(int data) : data(data), next(nullptr) {};
};

class SinglyLinkedList
{
private:
  Node *head;
  int size;

public:
  SinglyLinkedList() : head(nullptr), size(0) {}
  SinglyLinkedList(int data)
  {
    head = new Node(data);
    size = 1;
  }

  void add(int data)
  {
    Node *newNode = new Node(data);
    size++;

    if (!head)
    {
      head = newNode;
      return;
    }

    Node *curr = head;
    while (curr->next)
    {
      curr = curr->next;
    }

    curr->next = newNode;
  }

  int length() const { return size; };

  void printList()
  {
    Node *curr = head;
    while (curr)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
  }

  // also take care of duplicates
  void remove(int toRemove)
  {
    Node *dummy = new Node();
    dummy->next = head;

    Node *curr = dummy;
    while (curr->next)
    {
      if (curr->next->data == toRemove)
      {
        Node *remove = curr->next;
        curr->next = remove->next;
        delete remove;
        size--;
      }
      else
      {
        curr = curr->next;
      }
    }
    // update you head
    head = dummy->next;
    delete dummy;
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
      newNode->next = head;
      head = newNode;
      size++;
      return;
    }

    Node *curr = head;
    for (int i = 0; i < index - 1; i++)
    {
      curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    size++;
  }

  int find(int data)
  {
    Node *curr = head;
    int index = 0;

    while (curr)
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

  void reverse()
  {
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    head = prev; // new first node
  }

  void clear()
  {
    Node *curr = head;

    while (curr)
    {
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }
    head = nullptr;
    size = 0;
  }

  ~SinglyLinkedList()
  {
    clear();
  }
};

#endif // SINGLY_LINKED_LIST_H