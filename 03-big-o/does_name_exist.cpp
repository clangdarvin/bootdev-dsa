#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>

namespace {

template <std::size_t N>
bool doesNameExist(const std::array<std::string_view, N>& first_names,
                   const std::array<std::string_view, N>& last_names,
                   std::string_view full_name) {
  // O(n^2) - Quadratic
  for (std::size_t i{0}; i < first_names.size(); ++i) {
    for (std::size_t j{0}; j < last_names.size(); ++j) {
      std::string combined_name =
          std::string{first_names[i]} + " " + std::string{last_names[j]};
      if (combined_name == full_name) {
        return true;
      }
    }
  }
  return false;
}
}  // namespace

auto main() -> int {
  std::array<std::string_view, 4> first_names{
      "John",
      "Jane",
      "Michael",
      "Alice",
  };

  std::array<std::string_view, 4> last_names{
      "Doe",
      "Smith",
      "Jordan",
      "Walker",
  };

  std::string_view full_name{"Michael Jordan"};

  if (doesNameExist(first_names, last_names, full_name)) {
    std::cout << "Name exists\n";
  } else {
    std::cout << "Name does not exist\n";
  }

  return 0;
}
