#include <iostream>
#include <stdexcept>
#include <string_view>
#include <unordered_map>
#include <vector>
namespace {

const std::unordered_map<char, std::string_view> digits_to_letters{
    // O(2^n)
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
};

std::vector<std::string> letterCombinations(std::string_view digits) {
  if (digits.empty()) {
    return {};
  }

  std::vector<std::string> result{""};

  for (char digit : digits) {
    if (!digits_to_letters.contains(digit)) {
      throw std::runtime_error("Invalid Digit");
    }

    std::string_view letters = digits_to_letters.at(digit);
    std::vector<std::string> new_result{};

    for (const std::string& combo : result) {
      for (char letter : letters) {
        new_result.push_back(combo + letter);
      }
    }

    result = std::move(new_result);
  }

  return result;
}

}  // namespace

auto main() -> int {
  std::string_view input{"43556"};

  auto combos = letterCombinations(input);

  std::cout << "Count: " << combos.size() << '\n';

  for (std::size_t i = 0; i < 3 && i < combos.size(); ++i) {
    std::cout << combos[i] << '\n';
  }
}
