#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

#define NUMBER_OF_ARGS 4
#define MIN_TREE_LEVELS 3
#define MAX_TREE_LEVELS 6
#define MIN_NODES_ON_LEVEL 2
#define MAX_NODES_ON_LEVEL 7
#define NR_OF_FUNCTIONS 100
#define NR_BEST_TREES 7
#define TREES_TO_LOAD_FOLDER "global/top5Graphs/"
#define CSV_EXTENSION ".csv"
#define GENERATE_UNIQUE 0

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int node_id;
    int function_id;
    double value;
    vector<int> child_nodes_id;
};

struct tree {
    double fm_value;
    int nr_nodes;
    vector<node> nodes;
};

vector<tree> bestTrees;

// Optimization
double result = 0;
double sum = 0;
double product = 1;
double a = 0;
double b = 0;

// Function 1: Calculate the sum of the numbers and return the fractional part
static inline double function1(const vector<double>& numbers) {
    sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return fmod(sum, 1.0);
}

// Function 2: Calculate the product of the numbers and return the fractional part
static inline double function2(const std::vector<double>& numbers) {
    product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return fmod(product, 1.0);
}

// Function 3: Calculate the sum of square roots and return the fractional part
static inline double function3(const std::vector<double>& numbers) {
    sum = 0;
    for (auto x : numbers) {
        sum += sqrt(fabs(x));
    }
    return fmod(sum, 1.0);
}

// Function 4: Return the maximum of the first two numbers
static inline double function4(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    a = numbers[0];
    b = numbers[1];
    return (a > b) ? a : b;
}

// Function 5: Return the minimum of the first two numbers
static inline double function5(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    a = numbers[0];
    b = numbers[1];
    return (a < b) ? a : b;
}

// Function 6: Calculate the sum of absolute values and return the fractional part
static inline double function6(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 7: Calculate the sum of cubes and return the fractional part
static inline double function7(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += pow(x, 3);
    }
    return fmod(result, 1.0);
}

// Function 8: Calculate the sum of exponentials and return the fractional part
static inline double function8(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += exp(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 9: Calculate the sum of absolute sines and return the fractional part
static inline double function9(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += sin(x);
    }
    return fmod(fabs(result), 1.0);
}

// Function 10: Calculate the sum of absolute cosines and return the fractional part
static inline double function10(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += cos(x);
    }
    return fmod(fabs(result), 1.0);
}

// Function 11: Calculate the sum of logarithms and return the fractional part
static inline double function11(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += log(fabs(x) + 1);
    }
    return fmod(fabs(result), 1.0);
}

// Function 12: Calculate the sum of arctangents and return the fractional part
static inline double function12(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += atan(fabs(x));
    }
    return fmod(fabs(result), 1.0);
}

// Function 13: Calculate the sum of hyperbolic tangents and return the fractional part
static inline double function13(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += tanh(fabs(x));
    }
    return fmod(fabs(result), 1.0);
}

// Function 14: Calculate the sum of square roots of differences and return the fractional part
static inline double function14(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(1 - x * x));
    }
    return fmod(result, 1.0);
}

// Function 15: Calculate the sum of fractional parts and return the fractional part
static inline double function15(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 16: Calculate the product of square roots and return the fractional part
static inline double function16(const std::vector<double>& numbers) {
    result = 1;
    for (auto x : numbers) {
        result *= sqrt(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 17: Calculate the sum of fractional parts and return the fractional part
static inline double function17(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 18: Calculate the sum of exponentials minus their integer part and return the fractional part
static inline double function18(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += exp(fabs(x)) - floor(exp(fabs(x)));
    }
    return fmod(result, 1.0);
}

// Function 19: Calculate the sum of fourth powers and return the fractional part
static inline double function19(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += pow(x, 4);
    }
    return fmod(result, 1.0);
}

// Function 20: Calculate the sum of absolute sines and return the fractional part
static inline double function20(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fabs(sin(x));
    }
    return fmod(result, 1.0);
}

// Function 21: Calculate the sum of arctangents and return the fractional part
static inline double function21(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += atan(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 22: Calculate the sum of hyperbolic sines and return the fractional part
static inline double function22(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += sinh(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 23: Calculate the sum of square roots of 1 + x^2 and return the fractional part
static inline double function23(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += sqrt(1 + x * x);
    }
    return fmod(result, 1.0);
}

// Function 24: Calculate the sum of fractional parts and return the fractional part
static inline double function24(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 25: Calculate the sum of fractional parts and return the fractional part
static inline double function25(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
    }
    return fmod(result, 1.0);
}

// Function 26: Calculate the sum of hyperbolic cosines and return the fractional part
static inline double function26(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += cosh(fabs(x));
    }
    return fmod(result, 1.0);
}

// Function 27: Calculate the sum of square roots of differences and return the fractional part
static inline double function27(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(1 - x * x));
    }
    return fmod(result, 1.0);
}

// Function 28: Calculate the sum of exponentials minus their integer part and return the fractional part
static inline double function28(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += exp(fabs(x)) - floor(exp(fabs(x)));
    }
    return fmod(result, 1.0);
}

// Function 29: Calculate the sum of fifth powers and return the fractional part
static inline double function29(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += pow(x, 5);
    }
    return fmod(result, 1.0);
}

// Function 30: Calculate the sum of absolute cosines and return the fractional part
static inline double function30(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fabs(cos(x));
    }
    return fmod(result, 1.0);
}

// Function 31: Calculate the product of the first two numbers and return the fractional part
static inline double function31(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    
    product = a * b;
    return fmod(product, 1.0);
}

// Function 32: Calculate the sum of function1 and function3
static inline double function32(const std::vector<double>& numbers) {
    result = function1(numbers) + function3(numbers);
    return fmod(result, 1.0);
}

// Function 33: Calculate the product of function4 and function5
static inline double function33(const std::vector<double>& numbers) {
    result = function4(numbers) * function5(numbers);
    return fmod(result, 1.0);
}

// Function 34: Calculate the sum of function6 and function7
static inline double function34(const std::vector<double>& numbers) {
    result = function6(numbers) + function7(numbers);
    return fmod(result, 1.0);
}

// Function 35: Calculate the product of function8 and function9
static inline double function35(const std::vector<double>& numbers) {
    result = function8(numbers) * function9(numbers);
    return fmod(result, 1.0);
}

// Function 36: Calculate the sum of function10 and function11
static inline double function36(const std::vector<double>& numbers) {
    result = function10(numbers) + function11(numbers);
    return fmod(result, 1.0);
}

// Function 37: Calculate the product of function12 and function13
static inline double function37(const std::vector<double>& numbers) {
    result = function12(numbers) * function13(numbers);
    return fmod(result, 1.0);
}

// Function 38: Calculate the sum of function14 and function15
static inline double function38(const std::vector<double>& numbers) {
    result = function14(numbers) + function15(numbers);
    return fmod(result, 1.0);
}

// Function 39: Calculate the product of function16 and function17
static inline double function39(const std::vector<double>& numbers) {
    result = function16(numbers) * function17(numbers);
    return fmod(result, 1.0);
}

// Function 40: Calculate the sum of function18 and function19
static inline double function40(const std::vector<double>& numbers) {
    result = function18(numbers) + function19(numbers);
    return fmod(result, 1.0);
}

// Function 41: Calculate the product of function20 and function21
static inline double function41(const std::vector<double>& numbers) {
    result = function20(numbers) * function21(numbers);
    return fmod(result, 1.0);
}

// Function 42: Calculate the sum of function22 and function23
static inline double function42(const std::vector<double>& numbers) {
    result = function22(numbers) + function23(numbers);
    return fmod(result, 1.0);
}

// Function 43: Calculate the product of function24 and function25
static inline double function43(const std::vector<double>& numbers) {
    result = function24(numbers) * function25(numbers);
    return fmod(result, 1.0);
}

// Function 44: Calculate the sum of function26 and function27
static inline double function44(const std::vector<double>& numbers) {
    result = function26(numbers) + function27(numbers);
    return fmod(result, 1.0);
}

// Function 45: Calculate the product of function28 and function29
static inline double function45(const std::vector<double>& numbers) {
    result = function28(numbers) * function29(numbers);
    return fmod(result, 1.0);
}

// Function 46: Calculate the sum of function30 and function31
static inline double function46(const std::vector<double>& numbers) {
    result = function30(numbers) + function31(numbers);
    return fmod(result, 1.0);
}

// Function 47: Calculate the product of function32 and function33
static inline double function47(const std::vector<double>& numbers) {
    result = function32(numbers) * function33(numbers);
    return fmod(result, 1.0);
}

// Function 48: Calculate the sum of function34 and function35
static inline double function48(const std::vector<double>& numbers) {
    result = function34(numbers) + function35(numbers);
    return fmod(result, 1.0);
}

// Function 49: Calculate the product of function36 and function37
static inline double function49(const std::vector<double>& numbers) {
    result = function36(numbers) * function37(numbers);
    return fmod(result, 1.0);
}

// Function 50: Calculate the sum of function38 and function39
static inline double function50(const std::vector<double>& numbers) {
    result = function38(numbers) + function39(numbers);
    return fmod(result, 1.0);
}

// Function 51: Calculate the maximum of 2-10 entries
static inline double function51(const std::vector<double>& numbers) {
    double maxVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        maxVal = std::max(maxVal, x);
    }
    return maxVal;
}

// Function 52: Calculate the minimum of 2-10 entries
static inline double function52(const std::vector<double>& numbers) {
    double minVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        minVal = std::min(minVal, x);
    }
    return minVal;
}

// Function 53: Calculate the arithmetic mean of 2-10 entries
static inline double function53(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return sum / numbers.size();
}

// Function 54: Calculate the geometric mean of 2-10 entries
static inline double function54(const std::vector<double>& numbers) {
    double product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return std::pow(product, 1.0 / numbers.size());
}

// Function 55: Calculate the weighted mean of 2-10 entries with weights provided in numbers
static inline double function55(const std::vector<double>& numbers) {
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
static inline double function56(const std::vector<double>& numbers) {
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
static inline double function57(const std::vector<double>& numbers) {
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
static inline double function58(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x * x));
}

// Function 59: Apply arithmetic operations to limit the result in [0,1] with 2 entries
static inline double function59(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double x = numbers[0];
    double y = numbers[1];
    return std::max(0.0, std::min(1.0, std::abs(x - y)));
}

// Function 60: Apply arithmetic operations to limit the result in [0,1] with 2 entries
static inline double function60(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double x = numbers[0];
    double y = numbers[1];
    return std::max(0.0, std::min(1.0, x * y));
}

// Function 61: Apply arithmetic operations to limit the result in [0,1] with 1 entry
static inline double function61(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x + 0.5));
}

// Function 62: Apply arithmetic operations to limit the result in [0,1] with 1 entry
static inline double function62(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, 2 * x));
}

// Function 63: Calculate the sum of absolute differences and return the fractional part
static inline double function63(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += std::abs(x - 0.5);
    }
    return fmod(sum, 1.0);
}

// Function 64: Calculate the sum of square roots of absolute differences and return the fractional part
static inline double function64(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += sqrt(fabs(x - 0.5));
    }
    return fmod(result, 1.0);
}

// Function 65: Calculate the sum of absolute values squared and return the fractional part
static inline double function65(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(fabs(x), 2);
    }
    return fmod(result, 1.0);
}

// Function 66: Calculate the sum of hyperbolic cosines squared and return the fractional part
static inline double function66(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(cosh(x), 2);
    }
    return fmod(result, 1.0);
}

// Function 67: Calculate the sum of square roots of cubes and return the fractional part
static inline double function67(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += sqrt(pow(x, 3));
    }
    return fmod(result, 1.0);
}

// Function 68: Calculate the sum of logarithms of absolute values and return the fractional part
static inline double function68(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += log(fabs(x) + 2);
    }
    return fmod(result, 1.0);
}

// Function 69: Calculate the sum of absolute tangents and return the fractional part
static inline double function69(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += fabs(tan(x));
    }
    return fmod(result, 1.0);
}

// Function 70: Calculate the sum of hyperbolic tangents squared and return the fractional part
static inline double function70(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(tanh(x), 2);
    }
    return fmod(result, 1.0);
}

// Function 71: Calculate the sum of square roots of absolute sines and return the fractional part
static inline double function71(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += sqrt(fabs(sin(fabs(x))));
    }
    return fmod(result, 1.0);
}

// Function 72: Calculate the sum of absolute cosines squared and return the fractional part
static inline double function72(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(fabs(cos(fabs(x))), 2);
    }
    return fmod(result, 1.0);
}

// Function 73: Calculate the product of function63 and function61
static inline double function73(const std::vector<double>& numbers) {
    result = function63(numbers) * function61(numbers);
    return fmod(result, 1.0);
}

// Function 74: Calculate the product of function65 and function67
static inline double function74(const std::vector<double>& numbers) {
    result = function65(numbers) * function67(numbers);
    return fmod(result, 1.0);
}

// Function 75: Calculate the sum of function69 and function70
static inline double function75(const std::vector<double>& numbers) {
    result = function69(numbers) + function70(numbers);
    return fmod(result, 1.0);
}

// Function 76: Calculate the sum of function71 and function72
static inline double function76(const std::vector<double>& numbers) {
    result = function71(numbers) + function72(numbers);
    return fmod(result, 1.0);
}

// Function 77: Calculate the product of function73 and function74
static inline double function77(const std::vector<double>& numbers) {
    result = function73(numbers) * function74(numbers);
    return fmod(result, 1.0);
}

// Function 78: Calculate the product of function75 and function76
static inline double function78(const std::vector<double>& numbers) {
    result = function75(numbers) * function76(numbers);
    return fmod(result, 1.0);
}

// Function 79: Calculate the sum of function77 and function78
static inline double function79(const std::vector<double>& numbers) {
    result = function77(numbers) + function78(numbers);
    return fmod(result, 1.0);
}

// Function 80: Calculate the maximum of 2-10 entries
static inline double function80(const std::vector<double>& numbers) {
    double maxVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        maxVal = std::max(maxVal, x);
    }
    return maxVal;
}

// Function 81: Calculate the minimum of 2-10 entries
static inline double function81(const std::vector<double>& numbers) {
    double minVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        minVal = std::min(minVal, x);
    }
    return minVal;
}

// Function 82: Calculate the arithmetic mean of 2-10 entries
static inline double function82(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return sum / numbers.size();
}

// Function 83: Calculate the geometric mean of 2-10 entries
static inline double function83(const std::vector<double>& numbers) {
    double product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return std::pow(product, 1.0 / numbers.size());
}

// Function 84: Calculate the weighted mean of 2-10 entries with weights provided in numbers
static inline double function84(const std::vector<double>& numbers) {
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
static inline double function85(const std::vector<double>& numbers) {
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
static inline double function86(const std::vector<double>& numbers) {
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
static inline double function87(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x * x * x));
}

// Function 88: Apply arithmetic operations to limit the result in [0,1] with 1 entry
static inline double function88(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, 1 / (x + 1)));
}

// Function 89: Calculate the sum of absolute differences and return the fractional part
static inline double function89(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += std::abs(x - 0.75);
    }
    return fmod(sum, 1.0);
}

// Function 90: Calculate the sum of absolute values squared and return the fractional part
static inline double function90(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(fabs(x), 3);
    }
    return fmod(result, 1.0);
}

// Function 91: Calculate the sum of hyperbolic cosines squared and return the fractional part
static inline double function91(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(cosh(x), 3);
    }
    return fmod(result, 1.0);
}

// Function 92: Calculate the sum of square roots of cubes and return the fractional part
static inline double function92(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += sqrt(pow(x, 4));
    }
    return fmod(result, 1.0);
}

// Function 93: Calculate the sum of logarithms of absolute values and return the fractional part
static inline double function93(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += log(fabs(x) + 3);
    }
    return fmod(result, 1.0);
}

// Function 94: Calculate the sum of absolute tangents and return the fractional part
static inline double function94(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += fabs(tan(fabs(x)));
    }
    return fmod(result, 1.0);
}

// Function 95: Calculate the sum of hyperbolic tangents squared and return the fractional part
static inline double function95(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(tanh(fabs(x)), 2);
    }
    return fmod(result, 1.0);
}

// Function 96: Calculate the sum of square roots of absolute sines and return the fractional part
static inline double function96(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += sqrt(fabs(sin(fabs(x))));
    }
    return fmod(result, 1.0);
}

// Function 97: Calculate the sum of absolute cosines squared and return the fractional part
static inline double function97(const std::vector<double>& numbers) {
    
    for (auto x : numbers) {
        result += pow(fabs(cos(fabs(x))), 3);
    }
    return fmod(result, 1.0);
}

// Function 98: Calculate the product of function89 and function95
static inline double function98(const std::vector<double>& numbers) {
    result = function89(numbers) * function95(numbers);
    return fmod(result, 1.0);
}

// Function 99: Calculate the product of function96 and function97
static inline double function99(const std::vector<double>& numbers) {
    result = function96(numbers) * function97(numbers);
    return fmod(result, 1.0);
}

// Function 100: Calculate the sum of function98 and function99
static inline double function100(const std::vector<double>& numbers) {
    result = function98(numbers) + function99(numbers);
    return fmod(result, 1.0);
}

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

void loadTreeFromFile(const std::string& filename, tree& current_tree) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    fin >> current_tree.fm_value;
    fin >> current_tree.nr_nodes;
    current_tree.nodes.reserve(current_tree.nr_nodes);

    for (int j = 0; j < current_tree.nr_nodes; ++j) {
        node current_node;
        fin >> current_node.node_id >> current_node.function_id >> current_node.value;
        int childs_nr;
        fin >> childs_nr;
        current_node.child_nodes_id.reserve(childs_nr);

        for (int t = 0; t < childs_nr; ++t) {
            int child_id;
            fin >> child_id;
            current_node.child_nodes_id.push_back(child_id);
        }
        current_tree.nodes.push_back(current_node);
    }
}

void load_trees() {
    bool filesFound = true;

    for (int i = 1; i <= NR_BEST_TREES; ++i) {
        std::string filename = std::string(TREES_TO_LOAD_FOLDER) + "tree_to_load_" + std::to_string(i);
        if (!fileExists(filename)) {
            filesFound = false;
            break;
        }
    }

    if (!filesFound) {
        std::cout << "Files not found. Tree build from scratch!" << std::endl;
        return;
    }

    std::cout << "Files found! Reusing previous files in building the trees" << std::endl;

    tree current_tree;
    for (int i = 1; i <= NR_BEST_TREES; ++i) {
        std::string filename = std::string(TREES_TO_LOAD_FOLDER) + "tree_to_load_" + std::to_string(i);
        loadTreeFromFile(filename, current_tree);
        bestTrees.push_back(current_tree);
    }

    std::cout << "Loading trees: " << std::endl;
    for (const tree& t : bestTrees) {
        std::cout << "Fm Value: " << t.fm_value << std::endl;
    }
    std::cout << std::endl<< "Finished loading trees: " << std::endl;
}

void store_tree_explicit(int i, tree tree) {
    std::ofstream fout(std::string(TREES_TO_LOAD_FOLDER) + "tree_to_load_" + std::to_string(i) + "_explicit");
    std::ofstream fout1(std::string(TREES_TO_LOAD_FOLDER) + "f_measure_tree_" + std::to_string(i));
    fout1 << "Fm Value: " << tree.fm_value << "\n";
    fout1 << "Number of nodes: " << tree.nr_nodes << "\n\n";
    fout << "Fmeasure: " << tree.fm_value << "\n";
    fout << "Num. nodes: " << tree.nr_nodes << "\n\n";
    for (auto current_node : tree.nodes) {
        fout << "Node id: " << current_node.node_id << "\n" << "Node function: " << current_node.function_id << "\n" << "Node value: " << current_node.value << '\n';
        fout << "Node childs: " << current_node.child_nodes_id.size() << "\nChilds: ";

        if(current_node.child_nodes_id.size() == 0) {
            fout << "I AM A LEAF!" << std::endl;
            fout << "\n";
        } else {
            for (auto c : current_node.child_nodes_id) {
                fout << c << " ";
            }
            fout << "\n";
            fout << "\n";
        }
    }
}

void store_tree(int i, tree tree) {
    ofstream fout(std::string(TREES_TO_LOAD_FOLDER) + "tree_to_load_" + std::to_string(i));
    ofstream fout1(std::string(TREES_TO_LOAD_FOLDER) + "f_measure_tree_" + std::to_string(i));
    fout1 << "Fm Value: " << tree.fm_value << '\n';
    fout << tree.fm_value << " ";
    fout1 << "Number of nodes: " << tree.nr_nodes << '\n';
    fout << tree.nr_nodes << " ";
    for (auto current_node : tree.nodes) {
        fout << current_node.node_id << " " << current_node.function_id << " " << current_node.value << '\n';
        fout << current_node.child_nodes_id.size() << " ";
        for (auto c : current_node.child_nodes_id) {
            fout << c << " ";
            fout1 << c << " ";
        }
        fout << '\n';
        fout1 << '\n';
    }
}

void tree_build(int id, map<int, node> &nodes) {
    for (auto x : nodes[id].child_nodes_id) {
        tree_build(x, nodes);
    }

    vector<double> child_values;
    for (auto c : nodes[id].child_nodes_id) {
        child_values.push_back(nodes[c].value);
    }

    switch(nodes[id].function_id) {
    case 1:
        nodes[id].value = function1(child_values);
        break;
    case 2:
        nodes[id].value = function2(child_values);
        break;
    case 3:
        nodes[id].value = function3(child_values);
        break;
    case 4:
        nodes[id].value = function4(child_values);
        break;
    case 5:
        nodes[id].value = function5(child_values);
        break;
    case 6:
        nodes[id].value = function6(child_values);
        break;
    case 7:
        nodes[id].value = function7(child_values);
        break;
    case 8:
        nodes[id].value = function8(child_values);
        break;
    case 9:
        nodes[id].value = function9(child_values);
        break;
    case 10:
        nodes[id].value = function10(child_values);
        break;
    case 11:
        nodes[id].value = function11(child_values);
        break;
    case 12:
        nodes[id].value = function12(child_values);
        break;
    case 13:
        nodes[id].value = function13(child_values);
        break;
    case 14:
        nodes[id].value = function14(child_values);
        break;
    case 15:
        nodes[id].value = function15(child_values);
        break;
    case 16:
        nodes[id].value = function16(child_values);
        break;
    case 17:
        nodes[id].value = function17(child_values);
        break;
    case 18:
        nodes[id].value = function18(child_values);
        break;
    case 19:
        nodes[id].value = function19(child_values);
        break;
    case 20:
        nodes[id].value = function20(child_values);
        break;
    case 21:
        nodes[id].value = function21(child_values);
        break;
    case 22:
        nodes[id].value = function22(child_values);
        break;
    case 23:
        nodes[id].value = function23(child_values);
        break;
    case 24:
        nodes[id].value = function24(child_values);
        break;
    case 25:
        nodes[id].value = function25(child_values);
        break;
    case 26:
        nodes[id].value = function26(child_values);
        break;
    case 27:
        nodes[id].value = function27(child_values);
        break;
    case 28:
        nodes[id].value = function28(child_values);
        break;
    case 29:
        nodes[id].value = function29(child_values);
        break;
    case 30:
        nodes[id].value = function30(child_values);
        break;
    case 31:
        nodes[id].value = function31(child_values);
        break;
    case 32:
        nodes[id].value = function32(child_values);
        break;
    case 33:
        nodes[id].value = function33(child_values);
        break;
    case 34:
        nodes[id].value = function34(child_values);
        break;
    case 35:
        nodes[id].value = function35(child_values);
        break;
    case 36:
        nodes[id].value = function36(child_values);
        break;
    case 37:
        nodes[id].value = function37(child_values);
        break;
    case 38:
        nodes[id].value = function38(child_values);
        break;
    case 39:
        nodes[id].value = function39(child_values);
        break;
    case 40:
        nodes[id].value = function40(child_values);
        break;
    case 41:
        nodes[id].value = function41(child_values);
        break;
    case 42:
        nodes[id].value = function42(child_values);
        break;
    case 43:
        nodes[id].value = function43(child_values);
        break;
    case 44:
        nodes[id].value = function44(child_values);
        break;
    case 45:
        nodes[id].value = function45(child_values);
        break;
    case 46:
        nodes[id].value = function46(child_values);
        break;
    case 47:
        nodes[id].value = function47(child_values);
        break;
    case 48:
        nodes[id].value = function48(child_values);
        break;
    case 49:
        nodes[id].value = function49(child_values);
        break;
    case 50:
        nodes[id].value = function50(child_values);
        break;
    case 51:
        nodes[id].value = function51(child_values);
        break;
    case 52:
        nodes[id].value = function52(child_values);
        break;
    case 53:
        nodes[id].value = function53(child_values);
        break;
    case 54:
        nodes[id].value = function54(child_values);
        break;
    case 55:
        nodes[id].value = function55(child_values);
        break;
    case 56:
        nodes[id].value = function56(child_values);
        break;
    case 57:
        nodes[id].value = function57(child_values);
        break;
    case 58:
        nodes[id].value = function58(child_values);
        break;
    case 59:
        nodes[id].value = function59(child_values);
        break;
    case 60:
        nodes[id].value = function60(child_values);
        break;
    case 61:
        nodes[id].value = function61(child_values);
        break;
    case 62:
        nodes[id].value = function62(child_values);
        break;
    case 63:
        nodes[id].value = function63(child_values);
        break;
    case 64:
        nodes[id].value = function64(child_values);
        break;
    case 65:
        nodes[id].value = function65(child_values);
        break;
    case 66:
        nodes[id].value = function66(child_values);
        break;
    case 67:
        nodes[id].value = function67(child_values);
        break;
    case 68:
        nodes[id].value = function68(child_values);
        break;
    case 69:
        nodes[id].value = function69(child_values);
        break;
    case 70:
        nodes[id].value = function70(child_values);
        break;
    case 71:
        nodes[id].value = function71(child_values);
        break;
    case 72:
        nodes[id].value = function72(child_values);
        break;
    case 73:
        nodes[id].value = function73(child_values);
        break;
    case 74:
        nodes[id].value = function74(child_values);
        break;
    case 75:
        nodes[id].value = function75(child_values);
        break;
    case 76:
        nodes[id].value = function76(child_values);
        break;
    case 77:
        nodes[id].value = function77(child_values);
        break;
    case 78:
        nodes[id].value = function78(child_values);
        break;
    case 79:
        nodes[id].value = function79(child_values);
        break;
    case 80:
        nodes[id].value = function80(child_values);
        break;
    case 81:
        nodes[id].value = function81(child_values);
        break;
    case 82:
        nodes[id].value = function82(child_values);
        break;
    case 83:
        nodes[id].value = function83(child_values);
        break;
    case 84:
        nodes[id].value = function84(child_values);
        break;
    case 85:
        nodes[id].value = function85(child_values);
        break;
    case 86:
        nodes[id].value = function86(child_values);
        break;
    case 87:
        nodes[id].value = function87(child_values);
        break;
    case 88:
        nodes[id].value = function88(child_values);
        break;
    case 89:
        nodes[id].value = function89(child_values);
        break;
    case 90:
        nodes[id].value = function90(child_values);
        break;
    case 91:
        nodes[id].value = function91(child_values);
        break;
    case 92:
        nodes[id].value = function92(child_values);
        break;
    case 93:
        nodes[id].value = function93(child_values);
        break;
    case 94:
        nodes[id].value = function94(child_values);
        break;
    case 95:
        nodes[id].value = function95(child_values);
        break;
    case 96:
        nodes[id].value = function96(child_values);
        break;
    case 97:
        nodes[id].value = function97(child_values);
        break;
    case 98:
        nodes[id].value = function98(child_values);
        break;
    case 99:
        nodes[id].value = function99(child_values);
        break;
    case 100:
        nodes[id].value = function100(child_values);
        break;
    case -1:
        // Nod frunza, nu aplicam functie
        break;
    default:
        std::cerr << "Function number not found: " << nodes[id].function_id << "!\n";
        break;
    }   
}

vector<int> randomPermutation(int n) {
    vector<int> permutation;
    for (int i = 1; i <= n; ++i) {
        permutation.push_back(i);
    }

    random_device rd;
    mt19937 gen(rd());

    shuffle(permutation.begin(), permutation.end(), gen);

    return permutation;
}

void initializeNonLeafNodes(map<int, node>& nodes, const vector<vector<int>>& tree_on_levels) {
    for (int i = 0; i < (int)tree_on_levels.size() - 1; ++i) {
        for (auto id : tree_on_levels[i]) {
            node new_node;
            new_node.node_id = id;
            new_node.value = -1; // Initialize non-leaf nodes with -1
            new_node.function_id = rng() % NR_OF_FUNCTIONS + 1;
            nodes[id] = new_node;
        }
    }
}

void connectNodes(map<int, node>& nodes, const vector<vector<int>>& tree_on_levels) {
    for (int i = 0; i < (int)tree_on_levels.size() - 1; ++i) {
        int first_id_on_next_level = tree_on_levels[i + 1][0];
        for (auto &n : tree_on_levels[i]) {
            int nr_childs = rng() % tree_on_levels[i + 1].size() + 1;
            vector<int> permutation = randomPermutation(nr_childs);
            for (auto x : permutation) {
                nodes[n].child_nodes_id.push_back(first_id_on_next_level + x - 1);
            }
        }
    }
}

void setLeafNodeValues(map<int, node>& nodes, const vector<vector<string>>& data, const vector<int>& leaf_node_ids) {
    for (int i = 0; i < (int)data.size(); ++i) {
        int p = 0;
        for (auto id : leaf_node_ids) {
            nodes[id].value = std::stod(data[i][p++]); // Set leaf node value from CSV
            nodes[id].function_id = -1;
        }
    }
}

void generate_tree(const vector<vector<string>>& data, const vector<vector<string>>& fm_data, int tree_id) {
    map<int, node> nodes;
    int min_tree_levels = MIN_TREE_LEVELS;  // Adjust the minimum tree depth as needed
    int max_tree_levels = MAX_TREE_LEVELS;  // Adjust the maximum tree depth as needed
    int tree_levels = rng() % (max_tree_levels - min_tree_levels + 1) + min_tree_levels;
    vector<vector<int>> tree_on_levels;
    tree tree;
    tree.nr_nodes = 0;
    int current_id = 1;

    for (int i = 1; i <= tree_levels; ++i) {
        int min_nr_on_level = MIN_NODES_ON_LEVEL;  // Minimum nodes on each level
        int max_nr_on_level = MAX_NODES_ON_LEVEL;  // Maximum nodes on each level
        int nr_on_level = rng() % (max_nr_on_level - min_nr_on_level + 1) + min_nr_on_level;

        if (i == tree_levels) {
            nr_on_level = data[0].size();
        }

        vector<int> id_nodes;
        for (int j = 1; j <= nr_on_level; ++j) {
            id_nodes.push_back(current_id++);
        }
        tree_on_levels.push_back(id_nodes);
        tree.nr_nodes += nr_on_level;
    }

    initializeNonLeafNodes(nodes, tree_on_levels);
    connectNodes(nodes, tree_on_levels);

    vector<int> leaf_node_ids = tree_on_levels.back();
    setLeafNodeValues(nodes, data, leaf_node_ids);

    double final_fm = 0;
    for (int i = 0; i < (int)data.size(); ++i) {
        tree_build(1, nodes);
        double res = nodes[1].value;
        double current_fm = std::stod(fm_data[i][255 * res]);
        final_fm += current_fm;
    }
    final_fm /= data.size();
    tree.fm_value = final_fm;
    for (int i = 1; i <= tree.nr_nodes; ++i) {
        tree.nodes.push_back(nodes[i]);
    }
    bestTrees.push_back(tree);
}

void parseArguments(int argc, char** argv, int& nrTrees, std::string& file1, std::string& file2) {
    if (argc != NUMBER_OF_ARGS) {
        std::cerr << "Wrong usage: different number of arguments!\n";
        std::cerr << "Correct usage: ./o_global nrTrees file1.csv file2.csv\n";
        exit(1);
    }
    nrTrees = std::atoi(argv[1]);
    file1 = argv[2];
    file2 = argv[3];
    if (file1.find(CSV_EXTENSION) == std::string::npos || file2.find(CSV_EXTENSION) == std::string::npos) {
        std::cerr << "Wrong file extensions!\n";
        std::cerr << "Correct usage: ./o_global nrTrees file1.csv file2.csv\n";
        exit(1);
    }
}

std::vector<std::vector<std::string>> readCsvFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        exit(1);
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }

    return data;
}

void generateAndStoreTrees(int nrTrees, const std::vector<std::vector<std::string>>& data, const std::vector<std::vector<std::string>>& fm_data) {
    
    load_trees();

    #pragma omp parallel for shared(data, fm_data)
    for (int i = 0; i < nrTrees; ++i) {
        tree newTree;
        generate_tree(data, fm_data, i + 1);
        bestTrees.push_back(newTree); // Add the newly generated tree to the list
    }

    for (const tree& t : bestTrees) {
        std::cout << "Fm Value: " << t.fm_value << std::endl;
    }

    // Sort the bestTrees vector to keep only the best NR_BEST_TREES
    std::sort(bestTrees.begin(), bestTrees.end(), 
        [](const tree &a, const tree &b) {
            return a.fm_value > b.fm_value;
        }
    );

    // Keep only the top NR_BEST_TREES
    if (bestTrees.size() > NR_BEST_TREES) {
        bestTrees.resize(NR_BEST_TREES);
    }

    // Store the best NR_BEST_TREES trees
    for (int i = 0; i < NR_BEST_TREES; ++i) {
        store_tree(i + 1, bestTrees[i]);
        store_tree_explicit(i + 1, bestTrees[i]);
    }

    // Final trees
    std::cout << "\nFinal stored trees:\n";
    int i = 0;
    for (const tree& t : bestTrees) {
        if(i == NR_BEST_TREES)
            break;
        std::cout << "Fm Value: " << t.fm_value << std::endl;
        i++;
    }
}

int main(int argc, char **argv) {
    int nrTrees;
    std::string file1, file2;

    parseArguments(argc, argv, nrTrees, file1, file2);

    auto data = readCsvFile(file1);
    auto fm_data = readCsvFile(file2);

    generateAndStoreTrees(nrTrees, data, fm_data);

    return 0;
}