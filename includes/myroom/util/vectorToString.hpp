#pragma once

#include <ostream>
#include <vector>

namespace myroom { namespace util {
    template<typename T>
    std::ostream &operator<<(std::ostream &out, std::vector<T> const &v) {
        out << '[';
        std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << ']';
        return out;
    }
}}