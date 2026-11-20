#pragma once

#include "Cli.hpp"
#include "Loadable.hpp"

#include <string>

namespace advent {

class Solvable {
public:
    virtual ~Solvable() = default;

protected:
    virtual std::string solve(Loadable::Token) const = 0;
};

} // namespace advent
