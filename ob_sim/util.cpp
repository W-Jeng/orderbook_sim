#include "util.h"

std::string double_to_string(const double& num) {
    // normal double to string leaves trailing zero at the end, here we implement one that doesn't leave trailing zeroes
    std::string str = std::to_string(num);

    // Remove trailing zeros and decimal point if no digits after it
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str;
}

std::string empty_space(const int length) {
    return std::string(length, ' ');
}
