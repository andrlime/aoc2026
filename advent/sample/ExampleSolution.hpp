#pragma once

#include <string>
#include <string_view>
#include <utility>

#include <advent/Loadable.hpp>
#include <advent/Solvable.hpp>

namespace advent {

struct ExampleSolution : public Loadable, public Solvable {
    static constexpr std::string_view SOLUTION_NAME = "Example Solution";
    static constexpr std::string_view SOLUTION_ID = "example";

    std::string input;

    void process(std::string input) override { this->input = std::move(input); }

    std::string solve(Loadable::Token) const override { return input; }
};

} // namespace advent
