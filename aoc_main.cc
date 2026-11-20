#include <string_view>

#include <advent/sample/ExampleSolution.hpp>
#include <advent/Solver.hpp>

namespace {

using AllSolutions = advent::SolutionList<advent::ExampleSolution>;

advent::Solver::Runnable get_solution(std::string_view id) {
    return advent::Solver::get(AllSolutions{}, id);
}

} // namespace

int main(int argc, char** argv) try {
    advent::Cli cli{argc, argv};
    advent::Solver::Runnable solution = get_solution(cli.solution_id);
    if (!solution) {
        advent::Cli::print_help_text();
        return 0;
    }
    solution(cli.input_type);
    return 0;
} catch (std::runtime_error& e) {
    std::println("aoc: {}", e.what());
} catch (...) {
    std::println("aoc: uncaught exception");
}
