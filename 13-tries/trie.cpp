#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Trie {
 public:
  Trie() : end_symbol('*') {}

  void add(std::string_view word) {
    Trie* current = this;

    for (char c : word) {
      if (!current->children.contains(c)) {
        current->children[c] = Trie{};
      }
      current = &current->children[c];
    }

    current->children[end_symbol] = Trie{};
  }

  bool exists(std::string_view word) {
    Trie* current = this;

    for (char c : word) {
      if (!current->children.contains(c)) {
        return false;
      }
      current = &current->children[c];
    }

    return current->children.contains(end_symbol);
  }

  std::vector<std::string> searchLevel(Trie* current_level,
                                       const std::string& current_prefix,
                                       std::vector<std::string>& words) {
    if (current_level->children.contains(end_symbol)) {
      words.push_back(current_prefix);
    }

    std::vector<char> chars;
    for (const auto& [c, _] : current_level->children) {
      chars.push_back(c);
    }

    std::sort(chars.begin(), chars.end());

    for (char c : chars) {
      if (c == end_symbol) {
        continue;
      }

      searchLevel(&current_level->children[c], current_prefix + c, words);
    }

    return words;
  }

  std::vector<std::string> wordsWithPrefix(std::string_view prefix) {
    Trie* current = this;

    for (char c : prefix) {
      if (!current->children.contains(c)) {
        return {};
      }
      current = &current->children[c];
    }

    std::vector<std::string> matched_words;

    return searchLevel(current, std::string(prefix), matched_words);
  }

  std::set<std::string_view> findMatches(std::string_view document) {
    std::set<std::string_view> matches{};

    for (std::size_t i{0}; i < document.size(); ++i) {
      Trie* current = this;

      for (std::size_t j{i}; j < document.size(); ++j) {
        char ch = document[j];

        if (!current->children.contains(ch)) {
          break;
        }

        current = &current->children[ch];

        if (current->children.contains(end_symbol)) {
          matches.insert(document.substr(i, j - i + 1));
        }
      }
    }

    return matches;
  }

  std::string longestCommonPrefix() {
    Trie* current = this;
    std::string prefix;

    while (true) {
      std::vector<char> children;

      for (const auto& [ch, _] : current->children) {
        if (ch == end_symbol) {
          continue;
        }
        children.push_back(ch);
      }

      if (current->children.contains(end_symbol)) {
        break;
      }

      if (children.size() == 1) {
        char child = children[0];
        prefix += child;
        current = &current->children[child];
      } else {
        break;
      }
    }

    return prefix;
  }

  std::set<std::string_view> advancedFindMatches(
      std::string_view document,
      const std::unordered_map<char, char>& variations) {
    std::set<std::string_view> matches{};

    for (std::size_t i{0}; i < document.size(); ++i) {
      Trie* current = this;

      for (std::size_t j{i}; j < document.size(); ++j) {
        char ch = document[j];

        if (variations.contains(ch)) {
          ch = variations.at(ch);
        }

        if (!current->children.contains(ch)) {
          break;
        }

        current = &current->children.at(ch);

        if (current->children.contains(end_symbol)) {
          matches.insert(document.substr(i, j - i + 1));
        }
      }
    }

    return matches;
  }

 private:
  std::unordered_map<char, Trie> children;
  char end_symbol;
};

auto main() -> int {
  Trie trie;

  trie.add("cat");
  trie.add("car");
  trie.add("care");
  trie.add("dog");

  auto words = trie.wordsWithPrefix("ca");

  for (const auto& word : words) {
    std::cout << word << ' ';
  }
  std::cout << '\n';

  std::string_view document{"my c@t is riding a c@r"};

  std::unordered_map<char, char> variations{{'@', 'a'}};

  auto matches = trie.advancedFindMatches(document, variations);

  for (const auto& match : matches) {
    std::cout << match << ' ';
  }
  std::cout << '\n';

  return 0;
}
