// exer6_42.cpp : make_plural 函数，见prog6_3_2
//

#include <iostream>
#include <string>

// const std::string &ending，也可以是 const std::string ending 或 std::string ending，但不能是std::string &ending
std::string make_plural(size_t str, const std::string& word, const std::string &ending = "s")
{
    return (str > 1) ? word + ending : word;
}

int main()
{
    std::cout << make_plural(2, "success", "es") << std::endl;
    std::cout << make_plural(2, "failure") << std::endl;

    return 0;
}

// 