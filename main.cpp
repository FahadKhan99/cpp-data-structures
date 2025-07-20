#include "trie.h"
#include <iostream>

int main()
{
  Trie trie;

  // Insert words
  trie.insert("apple");
  trie.insert("app");
  trie.insert("app");
  trie.insert("apex");
  trie.insert("bat");
  trie.insert("batman");

  // Test search
  std::cout << "Search 'apple': " << trie.search("apple") << "\n";   // true
  std::cout << "Search 'app': " << trie.search("app") << "\n";       // true
  std::cout << "Search 'apex': " << trie.search("apex") << "\n";     // true
  std::cout << "Search 'bat': " << trie.search("bat") << "\n";       // true
  std::cout << "Search 'batman': " << trie.search("batman") << "\n"; // true
  std::cout << "Search 'bats': " << trie.search("bats") << "\n\n";     // false

  // Test startsWith
  std::cout << "StartsWith 'ap': " << trie.startsWith("ap") << "\n";     // true
  std::cout << "StartsWith 'batm': " << trie.startsWith("batm") << "\n"; // true
  std::cout << "StartsWith 'bad': " << trie.startsWith("bad") << "\n\n";   // false

  // Test countWordsEqualTo
  std::string word1 = "app";
  std::string word2 = "apple";
  std::cout << "Count 'app': " << trie.countWordsEqualTo(word1) << "\n";   // 2
  std::cout << "Count 'apple': " << trie.countWordsEqualTo(word2) << "\n\n"; // 1

  // Test countWordsStartingWith
  std::string prefix1 = "ap";
  std::string prefix2 = "bat";
  std::string prefix3 = "b";
  std::cout << "Count prefix 'ap': " << trie.countWordsStartingWith(prefix1) << "\n";  // 4
  std::cout << "Count prefix 'bat': " << trie.countWordsStartingWith(prefix2) << "\n"; // 2
  std::cout << "Count prefix 'b': " << trie.countWordsStartingWith(prefix3) << "\n\n";   // 2

  // Test erase
  trie.erase(word1); // erase one "app"
  std::cout << "After erase 'app':\n";
  std::cout << "Search 'app': " << trie.search("app") << "\n";                        // true
  std::cout << "Count 'app': " << trie.countWordsEqualTo(word1) << "\n";              // 1
  std::cout << "Count prefix 'ap': " << trie.countWordsStartingWith(prefix1) << "\n\n"; // 3

  trie.erase(word1); // erase another "app"
  std::cout << "After second erase 'app':\n";
  std::cout << "Search 'app': " << trie.search("app") << "\n";                        // false
  std::cout << "Count 'app': " << trie.countWordsEqualTo(word1) << "\n";              // 0
  std::cout << "Count prefix 'ap': " << trie.countWordsStartingWith(prefix1) << "\n\n"; // 2

  return 0;
}
