#include <ios>
#include <iostream>
#include <string_view>

#include "stack.h"

namespace {

bool isBalanced(std::string_view input_str) {
  Stack stack;

  for (std::size_t i{0}; i < input_str.size(); ++i) {
    if (input_str[i] == '(') {
      stack.push('(');
    } else if (input_str[i] == ')') {
      if (stack.isEmpty()) {
        return false;
      }

      if (stack.peek() == '(') {
        stack.pop();
      }
    }
  }

  return stack.isEmpty();
}

}  // namespace

auto main() -> int {
  std::string_view input_str{"((()))"};
  std::cout << "Is Balanced? " << std::boolalpha << isBalanced(input_str)
            << '\n';
  std::string_view input_strb{"(()"};
  std::cout << "Is Balanced? " << std::boolalpha << isBalanced(input_strb)
            << '\n';
  return 0;
}
