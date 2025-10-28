#ifndef TRIE_H
#define TRIE_H

/*

  Character exists:
    If the its reference exists.

  Word exists:
    If the last character's reference has flag = true.

*/

#include <iostream>
#include <vector>
#include <string>

class Trie
{
private:
  struct Node
  {
    Node *links[26]; // a - z
    bool flag = false;
    int countEndWith = 0;
    int countPrefix = 0;

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

    // new helper for these

    void increaseEnd()
    {
      countEndWith++;
    }

    void increasePrefix()
    {
      countPrefix++;
    }

    void deleteEnd()
    {
      countEndWith--;
    }

    void reducePrefix()
    {
      countPrefix--;
    }

    int getEnd()
    {
      return countEndWith;
    }

    int getPrefix()
    {
      return countPrefix;
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
      curr->increasePrefix();
    }
    curr->setEnd();
    curr->increaseEnd();
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

  int countWordsEqualTo(std::string &word)
  {
    Node *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (curr->containsKey(word[i]))
      {
        curr = curr->getNext(word[i]);
      }
      else
      {
        return 0;
      }
    }
    return curr->getEnd();
  }

  int countWordsStartingWith(std::string &word)
  {
    Node *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (curr->containsKey(word[i]))
      {
        curr = curr->getNext(word[i]);
      }
      else
      {
        return 0;
      }
    }
    return curr->getPrefix();
  }

  void erase(std::string &word)
  {
    Node *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (curr->containsKey(word[i]))
      {
        curr = curr->getNext(word[i]);
        curr->reducePrefix();
      }
      else
      {
        return;
      }
    }
    curr->deleteEnd();
  }

  bool checkIfPrefixExists(std::string word)
  {
    Node *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (curr->containsKey(word[i]))
      {
        curr = curr->getNext(word[i]);
        if (!curr->isEnd())
          return false;
      }
      else
      {
        return false;
      }
    }

    return true;
  }

  // Longest Word with All Prefixes Present in the List
  std::string completeString(std::vector<std::string> &wordList)
  {
    std::string longest = "";

    for (auto &word : wordList)
    {
      if (checkIfPrefixExists(word))
      {
        if (word.length() > longest.length())
        {
          longest = word;
        }
        else if (word.length() == longest.length() && word < longest)
        {
          longest = word;
        }
      }
    }

    if (longest == "")
      return "None";
    return longest;
  }
};

#endif