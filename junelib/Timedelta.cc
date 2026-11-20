#include "Timedelta.hpp"

#include <chrono>
#include <ratio>

namespace june {

Timedelta::Timedelta(std::chrono::nanoseconds ns) noexcept : ns_(ns) {}

Timedelta Timedelta::of_ns(std::chrono::nanoseconds ns) noexcept {
    return Timedelta{ns};
}

template <typename Ratio> double Timedelta::to() const noexcept {
    return std::chrono::duration<double, Ratio>(ns_).count();
}

double Timedelta::to_ns() const noexcept {
    return to<std::nano>();
}

double Timedelta::to_us() const noexcept {
    return to<std::micro>();
}

double Timedelta::to_ms() const noexcept {
    return to<std::milli>();
}

double Timedelta::to_s() const noexcept {
    return to<std::ratio<1>>();
}

double Timedelta::to_min() const noexcept {
    return to<std::ratio<60>>();
}

double Timedelta::to_hours() const noexcept {
    return to<std::chrono::hours::period>();
}

double Timedelta::to_days() const noexcept {
    return to<std::chrono::days::period>();
}

Timedelta Timedelta::operator+(const Timedelta& other) const noexcept {
    return Timedelta::of_ns(ns_ + other.ns_);
}

Timedelta Timedelta::operator-(const Timedelta& other) const noexcept {
    return Timedelta::of_ns(ns_ - other.ns_);
}

} // namespace june
