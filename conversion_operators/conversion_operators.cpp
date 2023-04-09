/**
 * @file conversion_operators.cpp
 *
 * @brief Conversion Operator
 *
 * @details Overload a cast operator for casting a class to another type
 *
 * @ref https://www.geeksforgeeks.org/conversion-operators-in-cpp/
 *
 * @author Miguel Amado
 */

#include <iostream>
#include <string>

// Class with only integers
class IntegerClass
{
public:
    IntegerClass() = delete;
    IntegerClass(const int integer, const int decimal) : integer_part_{integer}, decimal_part_{decimal} {};

    // Conversion operator
    // - converts class variables: "int" to "string"
    // - makes possible to add this class w/ a string variable
    operator std::string() const
    {
        return std::to_string(integer_part_) + "." + std::to_string(decimal_part_);
    }

private:
    int integer_part_;
    int decimal_part_;
};

int main()
{
    std::string string{"Twelve dot seventy eight | "};
    IntegerClass number{12, 78};

    std::cout << string << std::endl;
    // Output: Twelve dot seventy eight |

    // Using the convertion operator:
    std::cout << (string += number) << std::endl;
    // Output: Twelve dot seventy eight | 12.78

    return 0;
}
