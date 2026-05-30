#include <iostream>
#include <optional>
#include <string_view>
#include <vector>
namespace {
std::optional<std::string_view> getLastWorkExperience(
    std::vector<std::string_view> work_experiences) {
  if (work_experiences.empty()) {
    return std::nullopt;
  }
  return work_experiences.back();
}
}  // namespace

auto main() -> int {
  std::vector<std::string_view> work_experiences{
      "Software Engineer", "Data Analyst", "Project Manager"};
  std::optional<std::string_view> opt{getLastWorkExperience(work_experiences)};
  if (opt) {
    std::cout << "Last work experience: " << *opt << '\n';
  } else {
    std::cout << "No working experience." << '\n';
  }
  return 0;
}
