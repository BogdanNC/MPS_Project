#include <vector>
#include <cmath>
#include <algorithm>
#include "FunctionKing.h"

// Function 1: Calculate the sum of the numbers and return the fractional part
double FunctionKing::function1(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return fmod(sum, 1.0);
}

// Function 2: Calculate the product of the numbers and return the fractional part
double FunctionKing::function2(const std::vector<double>& numbers) {
    double product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return fmod(product, 1.0);
}

// Function 3: Calculate the sum of square roots and return the fractional part
double FunctionKing::function3(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += sqrt(fabs(x));
    }
    return fmod(sum, 1.0);
}

// Function 4: Return the maximum of the first two numbers
double FunctionKing::function4(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double a = numbers[0];
    double b = numbers[1];
    return (a > b) ? a : b;
}

// Function 5: Return the minimum of the first two numbers
double FunctionKing::function5(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double a = numbers[0];
    double b = numbers[1];
    return (a < b) ? a : b;
}

// Function 6: Calculate the sum of absolute values and return the fractional part
double FunctionKing::function6(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 7: Calculate the sum of cubes and return the fractional part
double FunctionKing::function7(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(x, 3);
    }
    return fmod(result, 1.0);
}

// Function 8: Calculate the sum of exponentials and return the fractional part
double FunctionKing::function8(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += exp(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 9: Calculate the sum of absolute sines and return the fractional part
double FunctionKing::function9(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sin(x);
    }
    return fmod(fabs(result), 1.0);
}

// Function 10: Calculate the sum of absolute cosines and return the fractional part
double FunctionKing::function10(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += cos(x);
    }
    return fmod(fabs(result), 1.0);
}

// Function 11: Calculate the sum of logarithms and return the fractional part
double FunctionKing::function11(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += log(fabs(x) + 1);
    }
    return fmod(fabs(result), 1.0);
}

// Function 12: Calculate the sum of arctangents and return the fractional part
double FunctionKing::function12(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += atan(fabs(x));
    }
    return fmod(fabs(result), 1.0);
}

// Function 13: Calculate the sum of hyperbolic tangents and return the fractional part
double FunctionKing::function13(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += tanh(fabs(x));
    }
    return fmod(fabs(result), 1.0);
}

// Function 14: Calculate the sum of square roots of differences and return the fractional part
double FunctionKing::function14(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(1 - x * x));
    }
    return fmod(result, 1.0);
}

// Function 15: Calculate the sum of fractional parts and return the fractional part
double FunctionKing::function15(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 16: Calculate the product of square roots and return the fractional part
double FunctionKing::function16(const std::vector<double>& numbers) {
    double result = 1;
    for (auto x : numbers) {
        result *= sqrt(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 17: Calculate the sum of fractional parts and return the fractional part
double FunctionKing::function17(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 18: Calculate the sum of exponentials minus their integer part and return the fractional part
double FunctionKing::function18(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += exp(fabs(x)) - floor(exp(fabs(x)));
    }
    return fmod(result, 1.0);
}

// Function 19: Calculate the sum of fourth powers and return the fractional part
double FunctionKing::function19(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(x, 4);
    }
    return fmod(result, 1.0);
}

// Function 20: Calculate the sum of absolute sines and return the fractional part
double FunctionKing::function20(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fabs(sin(x));
    }
    return fmod(result, 1.0);
}

// Function 21: Calculate the sum of arctangents and return the fractional part
double FunctionKing::function21(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += atan(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 22: Calculate the sum of hyperbolic sines and return the fractional part
double FunctionKing::function22(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sinh(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 23: Calculate the sum of square roots of 1 + x^2 and return the fractional part
double FunctionKing::function23(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(1 + x * x);
    }
    return fmod(result, 1.0);
}

// Function 24: Calculate the sum of fractional parts and return the fractional part
double FunctionKing::function24(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 25: Calculate the sum of fractional parts and return the fractional part
double FunctionKing::function25(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 26: Calculate the sum of hyperbolic cosines and return the fractional part
double FunctionKing::function26(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += cosh(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 27: Calculate the sum of square roots of differences and return the fractional part
double FunctionKing::function27(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(1 - x * x));
    }
    return fmod(result, 1.0);
}

// Function 28: Calculate the sum of exponentials minus their integer part and return the fractional part
double FunctionKing::function28(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += exp(fabs(x)) - floor(exp(fabs(x)));
    }
    return fmod(result, 1.0);
}

// Function 29: Calculate the sum of fifth powers and return the fractional part
double FunctionKing::function29(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(x, 5);
    }
    return fmod(result, 1.0);
}

// Function 30: Calculate the sum of absolute cosines and return the fractional part
double FunctionKing::function30(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fabs(cos(x));
    }
    return fmod(result, 1.0);
}

// Function 31: Calculate the product of the first two numbers and return the fractional part
double FunctionKing::function31(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double a = numbers[0];
    double b = numbers[1];
    double product = a * b;
    return fmod(product, 1.0);
}

// Function 32: Calculate the sum of function1 and function3
double FunctionKing::function32(const std::vector<double>& numbers) {
    double result = function1(numbers) + function3(numbers);
    return fmod(result, 1.0);
}

// Function 33: Calculate the product of function4 and function5
double FunctionKing::function33(const std::vector<double>& numbers) {
    double result = function4(numbers) * function5(numbers);
    return fmod(result, 1.0);
}

// Function 34: Calculate the sum of function6 and function7
double FunctionKing::function34(const std::vector<double>& numbers) {
    double result = function6(numbers) + function7(numbers);
    return fmod(result, 1.0);
}

// Function 35: Calculate the product of function8 and function9
double FunctionKing::function35(const std::vector<double>& numbers) {
    double result = function8(numbers) * function9(numbers);
    return fmod(result, 1.0);
}

// Function 36: Calculate the sum of function10 and function11
double FunctionKing::function36(const std::vector<double>& numbers) {
    double result = function10(numbers) + function11(numbers);
    return fmod(result, 1.0);
}

// Function 37: Calculate the product of function12 and function13
double FunctionKing::function37(const std::vector<double>& numbers) {
    double result = function12(numbers) * function13(numbers);
    return fmod(result, 1.0);
}

// Function 38: Calculate the sum of function14 and function15
double FunctionKing::function38(const std::vector<double>& numbers) {
    double result = function14(numbers) + function15(numbers);
    return fmod(result, 1.0);
}

// Function 39: Calculate the product of function16 and function17
double FunctionKing::function39(const std::vector<double>& numbers) {
    double result = function16(numbers) * function17(numbers);
    return fmod(result, 1.0);
}

// Function 40: Calculate the sum of function18 and function19
double FunctionKing::function40(const std::vector<double>& numbers) {
    double result = function18(numbers) + function19(numbers);
    return fmod(result, 1.0);
}

// Function 41: Calculate the product of function20 and function21
double FunctionKing::function41(const std::vector<double>& numbers) {
    double result = function20(numbers) * function21(numbers);
    return fmod(result, 1.0);
}

// Function 42: Calculate the sum of function22 and function23
double FunctionKing::function42(const std::vector<double>& numbers) {
    double result = function22(numbers) + function23(numbers);
    return fmod(result, 1.0);
}

// Function 43: Calculate the product of function24 and function25
double FunctionKing::function43(const std::vector<double>& numbers) {
    double result = function24(numbers) * function25(numbers);
    return fmod(result, 1.0);
}

// Function 44: Calculate the sum of function26 and function27
double FunctionKing::function44(const std::vector<double>& numbers) {
    double result = function26(numbers) + function27(numbers);
    return fmod(result, 1.0);
}

// Function 45: Calculate the product of function28 and function29
double FunctionKing::function45(const std::vector<double>& numbers) {
    double result = function28(numbers) * function29(numbers);
    return fmod(result, 1.0);
}

// Function 46: Calculate the sum of function30 and function31
double FunctionKing::function46(const std::vector<double>& numbers) {
    double result = function30(numbers) + function31(numbers);
    return fmod(result, 1.0);
}

// Function 47: Calculate the product of function32 and function33
double FunctionKing::function47(const std::vector<double>& numbers) {
    double result = function32(numbers) * function33(numbers);
    return fmod(result, 1.0);
}

// Function 48: Calculate the sum of function34 and function35
double FunctionKing::function48(const std::vector<double>& numbers) {
    double result = function34(numbers) + function35(numbers);
    return fmod(result, 1.0);
}

// Function 49: Calculate the product of function36 and function37
double FunctionKing::function49(const std::vector<double>& numbers) {
    double result = function36(numbers) * function37(numbers);
    return fmod(result, 1.0);
}

// Function 50: Calculate the sum of function38 and function39
double FunctionKing::function50(const std::vector<double>& numbers) {
    double result = function38(numbers) + function39(numbers);
    return fmod(result, 1.0);
}

// Function 51: Calculate the maximum of 2-10 entries
double FunctionKing::function51(const std::vector<double>& numbers) {
    double maxVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        maxVal = std::max(maxVal, x);
    }
    return maxVal;
}

// Function 52: Calculate the minimum of 2-10 entries
double FunctionKing::function52(const std::vector<double>& numbers) {
    double minVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        minVal = std::min(minVal, x);
    }
    return minVal;
}

// Function 53: Calculate the arithmetic mean of 2-10 entries
double FunctionKing::function53(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return sum / numbers.size();
}

// Function 54: Calculate the geometric mean of 2-10 entries
double FunctionKing::function54(const std::vector<double>& numbers) {
    double product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return std::pow(product, 1.0 / numbers.size());
}

// Function 55: Calculate the weighted mean of 2-10 entries with weights provided in numbers
double FunctionKing::function55(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double sum = 0;
    double weights = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i] * numbers[i + numbers.size()];
        weights += numbers[i + numbers.size()];
    }
    return sum / weights;
}

// Function 56: Calculate the median of 2-10 entries
double FunctionKing::function56(const std::vector<double>& numbers) {
    std::vector<double> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int n = sortedNumbers.size();
    if (n % 2 == 0) {
        return (sortedNumbers[n / 2 - 1] + sortedNumbers[n / 2]) / 2.0;
    } else {
        return sortedNumbers[n / 2];
    }
}

// Function 57: Apply if/else logic with 4 entries (if i1 < i2 then i3 else i4)
double FunctionKing::function57(const std::vector<double>& numbers) {
    if (numbers.size() < 4) {
        return 0;
    }
    double i1 = numbers[0];
    double i2 = numbers[1];
    double i3 = numbers[2];
    double i4 = numbers[3];
    return (i1 < i2) ? i3 : i4;
}

// Function 58: Apply arithmetic operations to limit the result in [0,1] with 1 entry
double FunctionKing::function58(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x * x));
}

// Function 59: Apply arithmetic operations to limit the result in [0,1] with 2 entries
double FunctionKing::function59(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double x = numbers[0];
    double y = numbers[1];
    return std::max(0.0, std::min(1.0, std::abs(x - y)));
}

// Function 60: Apply arithmetic operations to limit the result in [0,1] with 2 entries
double FunctionKing::function60(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double x = numbers[0];
    double y = numbers[1];
    return std::max(0.0, std::min(1.0, x * y));
}

// Function 61: Apply arithmetic operations to limit the result in [0,1] with 1 entry
double FunctionKing::function61(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x + 0.5));
}

// Function 62: Apply arithmetic operations to limit the result in [0,1] with 1 entry
double FunctionKing::function62(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, 2 * x));
}

// Function 63: Calculate the sum of absolute differences and return the fractional part
double FunctionKing::function63(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += std::abs(x - 0.5);
    }
    return fmod(sum, 1.0);
}

// Function 64: Calculate the sum of square roots of absolute differences and return the fractional part
double FunctionKing::function64(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(x - 0.5));
    }
    return fmod(result, 1.0);
}

// Function 65: Calculate the sum of absolute values squared and return the fractional part
double FunctionKing::function65(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(fabs(x), 2);
    }
    return fmod(result, 1.0);
}

// Function 66: Calculate the sum of hyperbolic cosines squared and return the fractional part
double FunctionKing::function66(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(cosh(x), 2);
    }
    return fmod(result, 1.0);
}

// Function 67: Calculate the sum of square roots of cubes and return the fractional part
double FunctionKing::function67(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(pow(x, 3));
    }
    return fmod(result, 1.0);
}

// Function 68: Calculate the sum of logarithms of absolute values and return the fractional part
double FunctionKing::function68(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += log(fabs(x) + 2);
    }
    return fmod(result, 1.0);
}

// Function 69: Calculate the sum of absolute tangents and return the fractional part
double FunctionKing::function69(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fabs(tan(x));
    }
    return fmod(result, 1.0);
}

// Function 70: Calculate the sum of hyperbolic tangents squared and return the fractional part
double FunctionKing::function70(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(tanh(x), 2);
    }
    return fmod(result, 1.0);
}

// Function 71: Calculate the sum of square roots of absolute sines and return the fractional part
double FunctionKing::function71(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(sin(fabs(x))));
    }
    return fmod(result, 1.0);
}

// Function 72: Calculate the sum of absolute cosines squared and return the fractional part
double FunctionKing::function72(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(fabs(cos(fabs(x))), 2);
    }
    return fmod(result, 1.0);
}

// Function 73: Calculate the product of function63 and function61
double FunctionKing::function73(const std::vector<double>& numbers) {
    double result = function63(numbers) * function61(numbers);
    return fmod(result, 1.0);
}

// Function 74: Calculate the product of function65 and function67
double FunctionKing::function74(const std::vector<double>& numbers) {
    double result = function65(numbers) * function67(numbers);
    return fmod(result, 1.0);
}

// Function 75: Calculate the sum of function69 and function70
double FunctionKing::function75(const std::vector<double>& numbers) {
    double result = function69(numbers) + function70(numbers);
    return fmod(result, 1.0);
}

// Function 76: Calculate the sum of function71 and function72
double FunctionKing::function76(const std::vector<double>& numbers) {
    double result = function71(numbers) + function72(numbers);
    return fmod(result, 1.0);
}

// Function 77: Calculate the product of function73 and function74
double FunctionKing::function77(const std::vector<double>& numbers) {
    double result = function73(numbers) * function74(numbers);
    return fmod(result, 1.0);
}

// Function 78: Calculate the product of function75 and function76
double FunctionKing::function78(const std::vector<double>& numbers) {
    double result = function75(numbers) * function76(numbers);
    return fmod(result, 1.0);
}

// Function 79: Calculate the sum of function77 and function78
double FunctionKing::function79(const std::vector<double>& numbers) {
    double result = function77(numbers) + function78(numbers);
    return fmod(result, 1.0);
}

// Function 80: Calculate the maximum of 2-10 entries
double FunctionKing::function80(const std::vector<double>& numbers) {
    double maxVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        maxVal = std::max(maxVal, x);
    }
    return maxVal;
}

// Function 81: Calculate the minimum of 2-10 entries
double FunctionKing::function81(const std::vector<double>& numbers) {
    double minVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        minVal = std::min(minVal, x);
    }
    return minVal;
}

// Function 82: Calculate the arithmetic mean of 2-10 entries
double FunctionKing::function82(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return sum / numbers.size();
}

// Function 83: Calculate the geometric mean of 2-10 entries
double FunctionKing::function83(const std::vector<double>& numbers) {
    double product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return std::pow(product, 1.0 / numbers.size());
}

// Function 84: Calculate the weighted mean of 2-10 entries with weights provided in numbers
double FunctionKing::function84(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double sum = 0;
    double weights = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i] * numbers[i + numbers.size()];
        weights += numbers[i + numbers.size()];
    }
    return sum / weights;
}

// Function 85: Calculate the median of 2-10 entries
double FunctionKing::function85(const std::vector<double>& numbers) {
    std::vector<double> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int n = sortedNumbers.size();
    if (n % 2 == 0) {
        return (sortedNumbers[n / 2 - 1] + sortedNumbers[n / 2]) / 2.0;
    } else {
        return sortedNumbers[n / 2];
    }
}

// Function 86: Apply if/else logic with 4 entries (if i1 < i2 then i3 else i4)
double FunctionKing::function86(const std::vector<double>& numbers) {
    if (numbers.size() < 4) {
        return 0;
    }
    double i1 = numbers[0];
    double i2 = numbers[1];
    double i3 = numbers[2];
    double i4 = numbers[3];
    return (i1 < i2) ? i3 : i4;
}

// Function 87: Apply arithmetic operations to limit the result in [0,1] with 1 entry
double FunctionKing::function87(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x * x * x));
}

// Function 88: Apply arithmetic operations to limit the result in [0,1] with 1 entry
double FunctionKing::function88(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, 1 / (x + 1)));
}

// Function 89: Calculate the sum of absolute differences and return the fractional part
double FunctionKing::function89(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += std::abs(x - 0.75);
    }
    return fmod(sum, 1.0);
}

// Function 90: Calculate the sum of absolute values squared and return the fractional part
double FunctionKing::function90(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(fabs(x), 3);
    }
    return fmod(result, 1.0);
}

// Function 91: Calculate the sum of hyperbolic cosines squared and return the fractional part
double FunctionKing::function91(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(cosh(x), 3);
    }
    return fmod(result, 1.0);
}

// Function 92: Calculate the sum of square roots of cubes and return the fractional part
double FunctionKing::function92(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(pow(x, 4));
    }
    return fmod(result, 1.0);
}

// Function 93: Calculate the sum of logarithms of absolute values and return the fractional part
double FunctionKing::function93(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += log(fabs(x) + 3);
    }
    return fmod(result, 1.0);
}

// Function 94: Calculate the sum of absolute tangents and return the fractional part
double FunctionKing::function94(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += fabs(tan(fabs(x)));
    }
    return fmod(result, 1.0);
}

// Function 95: Calculate the sum of hyperbolic tangents squared and return the fractional part
double FunctionKing::function95(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(tanh(fabs(x)), 2);
    }
    return fmod(result, 1.0);
}

// Function 96: Calculate the sum of square roots of absolute sines and return the fractional part
double FunctionKing::function96(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(sin(fabs(x))));
    }
    return fmod(result, 1.0);
}

// Function 97: Calculate the sum of absolute cosines squared and return the fractional part
double FunctionKing::function97(const std::vector<double>& numbers) {
    double result = 0;
    for (auto x : numbers) {
        result += pow(fabs(cos(fabs(x))), 3);
    }
    return fmod(result, 1.0);
}

// Function 98: Calculate the product of function89 and function95
double FunctionKing::function98(const std::vector<double>& numbers) {
    double result = function89(numbers) * function95(numbers);
    return fmod(result, 1.0);
}

// Function 99: Calculate the product of function96 and function97
double FunctionKing::function99(const std::vector<double>& numbers) {
    double result = function96(numbers) * function97(numbers);
    return fmod(result, 1.0);
}

// Function 100: Calculate the sum of function98 and function99
double FunctionKing::function100(const std::vector<double>& numbers) {
    double result = function98(numbers) + function99(numbers);
    return fmod(result, 1.0);
}