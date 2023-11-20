#include <iostream>
#include "FunctionKing.h"

int main()
{
    // Create an instance of the FunctionKing class
    FunctionKing functionKing;

    // Create a vector of double values to pass to the function
    std::vector<double> numbers = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Call the function1 on the FunctionKing instance
    double result = functionKing.function1(numbers);

    // Display the result
    std::cout << "Result of function1: " << result << std::endl;
}