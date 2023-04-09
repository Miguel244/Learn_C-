/**
 * @file increment_operators.cpp
 *
 * @brief Increment Operators
 *
 * @details Create pre and pos increment and decrement operators
 *
 * @ref https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/
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

    // Pre increment operator
    IntegerClass &operator++()
    {
        int inc{1};
        // 1st: Increment the values
        integer_part_ += inc;
        decimal_part_ += inc;
        // 2nd: Return the updated instance
        return *this;
        // Note: It returns the address because, after the operation, the instance wants to have the updated values
    }
    // Pos increment operator
    IntegerClass operator++(int)
    {
        // 1st: Save the current instance values
        IntegerClass temp{*this};
        // 2nd: Increment the values
        int inc{1};
        integer_part_ += inc;
        decimal_part_ += inc;
        // 3rd: Return the instance status before the increment step
        return temp;
        // Note: It returns the initial instance values (temp) because, after the operation, the instance wants to deliver the previous values
    }

    // The logic is the same for the decrement operators but with the sign - instead of +:
    // IntegerClass &operator--()
    // IntegerClass operator--(int)

    // Extra content for debug:
    friend std::ostream &operator<<(std::ostream &out, const IntegerClass &that)
    {
        out << that.integer_part_ << "," << that.decimal_part_ << std::endl;
        return out;
    }

private:
    int integer_part_;
    int decimal_part_;
};

int main()
{
    IntegerClass number{10, 20};

    // Using pos increment:
    std::cout << number++ << std::endl;
    // Output: 10,20

    // Using pre increment:
    std::cout << ++number << std::endl;
    // Output: 12,22

    return 0;
}
