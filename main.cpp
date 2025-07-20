#include <iostream>
#include <vector>
#include "trie.h" // Make sure this has the Trie and Node class definitions

int main()
{
  Trie trie;

  std::vector<std::string> words1 = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
  std::vector<std::string> words2 = {"a", "ab", "abc", "abcd"};
  std::vector<std::string> words3 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  std::vector<std::string> words4 = {"k", "ki", "kin", "king", "kingd", "kingdo", "kingdom"};
  std::vector<std::string> words5 = {"a", "ab", "abc", "abd", "abcd"};

  auto test = [&](const std::vector<std::string> &wordList)
  {
    Trie temp;
    for (const auto &word : wordList)
    {
      temp.insert(word);
    }
    std::cout << "Longest complete string in list: " << temp.completeString(const_cast<std::vector<std::string> &>(wordList)) << "\n\n";
  };

  std::cout << "Test Case 1:\n";
  test(words1); // Expected: "ninja"

  std::cout << "Test Case 2:\n";
  test(words2); // Expected: "abcd"

  std::cout << "Test Case 3:\n";
  test(words3); // Expected: "apple"

  std::cout << "Test Case 4:\n";
  test(words4); // Expected: "kingdom"

  std::cout << "Test Case 5:\n";
  test(words5); // Expected: "abcd"

  return 0;
}
