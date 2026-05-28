#include <iostream>
#include <optional>
#include <string_view>
#include <unordered_map>

namespace {

std::optional<std::string_view> findLastName(
    const std::unordered_map<std::string_view, std::string_view>& names,
    std::string_view first_name) {
  // O(1) - Constant
  if (auto item{names.find(first_name)}; item != names.end()) {
    return item->second;
  }

  return std::nullopt;
}

}  // namespace

auto main() -> int {
  std::unordered_map<std::string_view, std::string_view> names{
      {"John0", "Doe0"},
      {"John1", "Doe1"},
      {"John2", "Doe2"},
  };

  std::string_view first_name{"John1"};

  auto result{findLastName(names, first_name)};

  if (result.has_value()) {
    std::cout << first_name << " " << *result << '\n';
    std::cout << *result << " is the surname." << '\n';
  } else {
    std::cout << "Not found\n";
  }

  return 0;
}
