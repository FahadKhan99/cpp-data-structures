#ifndef TRIE_H
#define TRIE_H

/*

  Character exists:
    If the its reference exists.

  Word exists:
    If the last character's reference has flag = true.

*/

#include <iostream>

class Trie
{
private:
  struct Node
  {
    Node *links[26]; // a - z
    bool flag = false;

    // checks if reference exists
    bool containsKey(char ch)
    {
      return (links[ch - 'a'] != nullptr);
    }

    void put(char ch, Node *node)
    {
      links[ch - 'a'] = node;
    }

    Node *getNext(char ch)
    {
      return links[ch - 'a'];
    }

    void setEnd()
    {
      flag = true;
    }

    bool isEnd()
    {
      return flag;
    }
  };
  Node *root;

public:
  Trie()
  {
    root = new Node(); // an empty reference
  }

  void insert(std::string word)
  {
    Node *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!curr->containsKey(word[i]))
      {
        curr->put(word[i], new Node()); // also pass new reference
      }
      // move to the reference
      curr = curr->getNext(word[i]);
    }
    curr->setEnd();
  }

  std::string search(std::string word)
  {
    Node *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!curr->containsKey(word[i]))
      {
        return "false";
      }
      curr = curr->getNext(word[i]);
    }

    if (curr->isEnd())
      return "true";
    return "false";
  }

  std::string startsWith(std::string prefix)
  {
    Node *curr = root;
    for (int i = 0; i < prefix.length(); i++)
    {
      if (!curr->containsKey(prefix[i]))
      {
        return "false";
      }
      curr = curr->getNext(prefix[i]);
    }
    return "true";
  }
};

#endif