#include "trie.h"

int main()
{
  Trie trie;
  trie.insert("apple");
  trie.insert("apps");
  trie.insert("apxl");
  trie.insert("bac");
  trie.insert("bat");

  std::cout << "Exists: " << trie.search("apple");
  return 0;
}
