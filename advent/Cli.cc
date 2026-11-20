#include "Cli.hpp"

#include <cstdlib>
#include <format>
#include <print>
#include <stdexcept>
#include <utility>

namespace advent {

InputType input_type_of_string(std::string_view input) {
    if (input == "small") {
        return InputType::Small;
    }
    if (input == "large") {
        return InputType::Large;
    }
    if (input == "test") {
        return InputType::Test;
    }
    throw std::runtime_error(std::format("invalid input type: {}", input));
}

std::string_view string_of_input_type(InputType type) noexcept {
    switch (type) {
        case InputType::Small: return "small";
        case InputType::Large: return "large";
        case InputType::Test: return "test";
    }
    std::unreachable();
}

void Cli::print_help_text() {
    std::println("Usage: aoc <solution_id> [small|large|test]");
    std::println("  solution_id   id of the day's solution to run");
    std::println("  input_type    which input file to use (default: large)");
}

Cli::Cli(int argc, char** argv) noexcept {
    if (argc < 2 || argc > 3) {
        print_help_text();
        std::exit(0);
    }

    solution_id = argv[1];
    try {
        input_type = input_type_of_string(argc == 3 ? argv[2] : "large");
    } catch (const std::runtime_error&) {
        print_help_text();
        std::exit(0);
    }
}

} // namespace advent
