#pragma once

#include <string>
#include <sstream>
#include <type_traits>
#include <iterator>
#include <utility>

// Trait to detect containers (has begin() and end()), excluding std::string
template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename T>
struct is_container<T, std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
>> : std::true_type {};

template <>
struct is_container<std::string> : std::false_type {};

// Forward declaration
template <typename T>
std::string PrintElement(const T& elem);

// Generic container printer
template <typename Container>
std::string PrintContainer(const Container& container) {
    std::ostringstream oss;
    oss << "[ ";

    auto it = container.begin();
    while (it != container.end()) {
        oss << PrintElement(*it);
        ++it;
        if (it != container.end()) oss << ", ";
    }

    oss << " ]";
    return oss.str();
}

// Pair printer
template <typename T1, typename T2>
std::string PrintElement(const std::pair<T1, T2>& p) {
    return "(" + PrintElement(p.first) + ", " + PrintElement(p.second) + ")";
}

// Generic element printer
template <typename T>
std::string PrintElement(const T& elem) {
    if constexpr (std::is_same_v<T, std::string>) {
        return "\"" + elem + "\"";
    } else if constexpr (std::is_arithmetic_v<T>) {
        return std::to_string(elem);
    } else if constexpr (is_container<T>::value) {
        return PrintContainer(elem);
    } else {
        return "<unprintable>";
    }
}
