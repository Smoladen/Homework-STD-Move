#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class big_integer{
private:
    std::string digids;
public:
    big_integer() : digids("0"){}

    big_integer(const std::string& str) : digids(str) {
        std::reverse(digids.begin(), digids.end());
    }

    big_integer(const big_integer &other) : digids(other.digids) {}

    big_integer(big_integer &&other) noexcept : digids(std::move(other.digids)) {}


    big_integer &operator=(const big_integer &other) {
        digids = other.digids;
        return *this;
    }
    big_integer &operator=(big_integer &&other) noexcept {
        digids = std::move(other.digids);
        return *this;
    }
};


int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099
    return 0;
}
