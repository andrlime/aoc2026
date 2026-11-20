#pragma once

#include <chrono>

namespace june {

class Timedelta {
public:
    static Timedelta of_ns(std::chrono::nanoseconds ns) noexcept;

    double to_ns() const noexcept;
    double to_us() const noexcept;
    double to_ms() const noexcept;
    double to_s() const noexcept;
    double to_min() const noexcept;
    double to_hours() const noexcept;
    double to_days() const noexcept;

    Timedelta operator+(const Timedelta& other) const noexcept;
    Timedelta operator-(const Timedelta& other) const noexcept;

private:
    explicit Timedelta(std::chrono::nanoseconds ns) noexcept;

    template <typename Ratio> double to() const noexcept;

    std::chrono::nanoseconds ns_;
};

} // namespace june
