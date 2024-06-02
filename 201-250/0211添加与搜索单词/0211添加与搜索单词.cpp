#include <string>
#include <vector>

class TrieNode {
 public:
  std::vector<TrieNode*> children;
  bool isEndOfWord;

  TrieNode() : isEndOfWord(false) {
    children.resize(26, nullptr);  // 26 个字母
  }
};

class WordDictionary {
 private:
  TrieNode* root;

  bool searchHelper(TrieNode* node, const std::string& word, int index) {
    if (node == nullptr) {
      return false;
    }

    if (index == word.length()) {
      return node->isEndOfWord;
    }

    char currentChar = word[index];
    if (currentChar == '.') {
      // 递归搜索所有可能的子节点
      for (auto child : node->children) {
        if (child != nullptr && searchHelper(child, word, index + 1)) {
          return true;
        }
      }
    } else {
      int childIndex = currentChar - 'a';
      // 递归搜索特定的子节点
      return (node->children[childIndex] != nullptr &&
              searchHelper(node->children[childIndex], word, index + 1));
    }

    return false;
  }

 public:
  WordDictionary() : root(new TrieNode()) {}

  void addWord(std::string word) {
    TrieNode* cursor = root;
    for (char ch : word) {
      int index = ch - 'a';
      if (cursor->children[index] == nullptr) {
        cursor->children[index] = new TrieNode();
      }
      cursor = cursor->children[index];
    }
    cursor->isEndOfWord = true;
  }

  bool search(std::string word) { return searchHelper(root, word, 0); }
};