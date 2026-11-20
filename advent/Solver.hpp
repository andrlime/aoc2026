#pragma once

#include "Loadable.hpp"
#include "Solvable.hpp"

#include <concepts>
#include <filesystem>
#include <functional>
#include <memory>
#include <print>
#include <string_view>
#include <utility>

#include <junelib/Timing.hpp>

namespace advent {

inline constexpr std::string_view INPUTS_FOLDER_NAME = "./inputs";

template <typename T>
concept ValidSolution = std::derived_from<T, Loadable>
                        && std::derived_from<T, Solvable> && requires(T) {
                               {
                                   T::SOLUTION_NAME
                               } -> std::convertible_to<std::string_view>;
                               {
                                   T::SOLUTION_ID
                               } -> std::convertible_to<std::string_view>;
                           };

template <ValidSolution... Ts> struct SolutionList {};

class Solver {
public:
    using Runnable = std::function<void(InputType)>;

    template <ValidSolution... Ts> static Runnable
    get(SolutionList<Ts...>, std::string_view id) {
        Runnable result;
        ((result =
              result ? std::move(result)
                     : (id == Ts::SOLUTION_ID ? make_runnable<Ts>() : nullptr)),
         ...);
        return result;
    }

protected:
    Solver() = default;

private:
    template <ValidSolution T> static Runnable make_runnable() {
        return
            [](InputType input) { Solver{}.run(std::make_unique<T>(), input); };
    }

    template <ValidSolution T> void
    run(std::unique_ptr<T> soln, InputType input) {
        Loadable::Token token = soln->load(
            std::filesystem::path(INPUTS_FOLDER_NAME) / T::SOLUTION_ID, input
        );
        const auto [result, duration] =
            june::ChronoTimer::time_function([&soln, token] {
                return soln->solve(token);
            });

        std::println("{}", T::SOLUTION_NAME);
        std::println("Solution: {}", result);

        if (duration.to_ms() < 1.0) {
            std::println(
                "Time: {} ms ({} μs)", duration.to_ms(), duration.to_us()
            );
        }
        else if (duration.to_s() < 1.0) {
            std::println("Time: {} ms", duration.to_ms());
        }
        else {
            std::println("Time: {} s", duration.to_s());
        }
    }
};

} // namespace advent
