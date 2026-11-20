#pragma once

#include "Cli.hpp"

#include <filesystem>
#include <string>

namespace advent {

class Loadable {
public:
    class Token {
    public:
        Token(const Token&) = default;
        Token& operator=(const Token&) = default;

    private:
        friend class Loadable;
        Token() = default;
    };

    virtual ~Loadable() = default;

    Token load(const std::filesystem::path& data_folder, InputType input);

protected:
    virtual void process(std::string input) = 0;
};

} // namespace advent
