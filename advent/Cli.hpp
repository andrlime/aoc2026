#pragma once

#include <cstdint>
#include <string_view>

namespace advent {

enum class InputType : std::uint8_t { Small, Large, Test };

InputType input_type_of_string(std::string_view input);
std::string_view string_of_input_type(InputType type) noexcept;

struct Cli {
    Cli(int argc, char** argv) noexcept;

    static void print_help_text();

    std::string_view solution_id;
    InputType input_type;
};

} // namespace advent
