#include "Loadable.hpp"

#include <filesystem>
#include <format>
#include <stdexcept>
#include <string>
#include <utility>

#include <junelib/FileReader.hpp>

namespace advent {

namespace {

std::string path_of_input_type(InputType input) {
    if (input == InputType::Small) {
        return "small.txt";
    }
    if (input == InputType::Large) {
        return "large.txt";
    }
    if (input == InputType::Test) {
        return "test.txt";
    }
    std::unreachable();
}

} // namespace

Loadable::Token
Loadable::load(const std::filesystem::path& data_folder, InputType input) {
    std::filesystem::path path = data_folder / path_of_input_type(input);
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error(
            std::format("loadable: {}", path.string())
        );
    }

    std::string contents = june::FileReader::read(path.string());
    process(contents);
    return Token();
}

} // namespace advent
