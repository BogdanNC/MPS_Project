#include <bits/stdc++.h>
#include <filesystem>
#include <omp.h>
using namespace std;
 
// ./o_global 5 global/GlobalTest.csv global/LUTTest.csv
 
#define NUMBER_OF_ARGS_GLOBAL 5
#define NUMBER_OF_ARGS_LOCAL 3
 
#define MIN_TREE_LEVELS 1
#define MAX_TREE_LEVELS 7
#define MIN_NODES_ON_LEVEL 4
#define MAX_NODES_ON_LEVEL 20
 
#define NR_OF_FUNCTIONS 46
// No less than the number of trees you generate in a run with the Makefile
#define NR_BEST_TREES 7
 
#define CSV_EXTENSION ".csv"
#define TREES_TO_LOAD_FOLDER_GLOBAL "global/top5Graphs/"
#define TREES_TO_LOAD_FOLDER_LOCAL "local/top5Graphs/"
#define FILE_INPUTS_LOCAL "local/test"
 
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
 
// Function 22: Calculate the sum of square roots of 1 + x^2 and return the fractional part
static inline double function22(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += sqrt(1 + x * x);
    }
    return fmod(result, 1.0);
}
 
// Function 23: Calculate the sum of fractional parts and return the fractional part
static inline double function23(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += fmod(fabs(x), 1.0);
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
 
// Function 25: Calculate the sum of hyperbolic cosines and return the fractional part
static inline double function25(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += cosh(fabs(x));
    }
    return fmod(result, 1.0);
}
 
// Function 26: Calculate the sum of square roots of differences and return the fractional part
static inline double function26(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += sqrt(fabs(1 - x * x));
    }
    return fmod(result, 1.0);
}
 
// Function 27: Calculate the sum of fifth powers and return the fractional part
static inline double function27(const std::vector<double>& numbers) {
    result = 0;
    for (auto x : numbers) {
        result += pow(x, 5);
    }
    return fmod(result, 1.0);
}
 
// Function 28: Calculate the product of the first two numbers and return the fractional part
static inline double function28(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
 
    product = a * b;
    return fmod(product, 1.0);
}
 
// Function 29: Calculate the maximum of 2-10 entries
static inline double function29(const std::vector<double>& numbers) {
    double maxVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        maxVal = std::max(maxVal, x);
    }
    return maxVal;
}
 
// Function 30: Calculate the minimum of 2-10 entries
static inline double function30(const std::vector<double>& numbers) {
    double minVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        minVal = std::min(minVal, x);
    }
    return minVal;
}
 
// Function 31 Calculate the arithmetic mean of 2-10 entries
static inline double function31(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return sum / numbers.size();
}
 
// Function 32: Calculate the geometric mean of 2-10 entries
static inline double function32(const std::vector<double>& numbers) {
    double product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return std::pow(product, 1.0 / numbers.size());
}
 
// Function 33: Calculate the weighted mean of 2-10 entries with weights provided in numbers
static inline double function33(const std::vector<double>& numbers) {
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
 
// Function 34: Apply if/else logic with 4 entries (if i1 < i2 then i3 else i4)
static inline double function34(const std::vector<double>& numbers) {
    if (numbers.size() < 4) {
        return 0;
    }
    double i1 = numbers[0];
    double i2 = numbers[1];
    double i3 = numbers[2];
    double i4 = numbers[3];
    return (i1 < i2) ? i3 : i4;
}
 
// Function 35: Apply arithmetic operations to limit the result in [0,1] with 1 entry
static inline double function35(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x * x));
}
 
// Function 36: Apply arithmetic operations to limit the result in [0,1] with 2 entries
static inline double function36(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double x = numbers[0];
    double y = numbers[1];
    return std::max(0.0, std::min(1.0, std::abs(x - y)));
}
 
// Function 37: Apply arithmetic operations to limit the result in [0,1] with 2 entries
static inline double function37(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        return 0;
    }
    double x = numbers[0];
    double y = numbers[1];
    return std::max(0.0, std::min(1.0, x * y));
}
 
// Function 38: Apply arithmetic operations to limit the result in [0,1] with 1 entry
static inline double function38(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, x + 0.5));
}
 
// Function 39: Apply arithmetic operations to limit the result in [0,1] with 1 entry
static inline double function39(const std::vector<double>& numbers) {
    if (numbers.size() < 1) {
        return 0;
    }
    double x = numbers[0];
    return std::max(0.0, std::min(1.0, 2 * x));
}
 
// Function 40: Calculate the sum of absolute differences and return the fractional part
static inline double function40(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += std::abs(x - 0.5);
    }
    return fmod(sum, 1.0);
}
 
// Function 41: Calculate the maximum of 2-10 entries
static inline double function41(const std::vector<double>& numbers) {
    double maxVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        maxVal = std::max(maxVal, x);
    }
    return maxVal;
}
 
// Function 42: Calculate the minimum of 2-10 entries
static inline double function42(const std::vector<double>& numbers) {
    double minVal = (numbers.empty()) ? 0 : numbers[0];
    for (auto x : numbers) {
        minVal = std::min(minVal, x);
    }
    return minVal;
}
 
// Function 43: Calculate the arithmetic mean of 2-10 entries
static inline double function43(const std::vector<double>& numbers) {
    double sum = 0;
    for (auto x : numbers) {
        sum += x;
    }
    return sum / numbers.size();
}
 
// Function 44: Calculate the geometric mean of 2-10 entries
static inline double function44(const std::vector<double>& numbers) {
    double product = 1;
    for (auto x : numbers) {
        product *= x;
    }
    return std::pow(product, 1.0 / numbers.size());
}
 
// Function 45: Calculate the weighted mean of 2-10 entries with weights provided in numbers
static inline double function45(const std::vector<double>& numbers) {
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
 
// Function 46: Calculate the median of 2-10 entries
static inline double function46(const std::vector<double>& numbers) {
    std::vector<double> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int n = sortedNumbers.size();
    if (n % 2 == 0) {
        return (sortedNumbers[n / 2 - 1] + sortedNumbers[n / 2]) / 2.0;
    } else {
        return sortedNumbers[n / 2];
    }
}
 
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
 
static inline bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}
 
static inline void loadTreeFromFile(const string& filename, tree& current_tree) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
 
    fin >> current_tree.fm_value >> current_tree.nr_nodes;
    current_tree.nodes.resize(current_tree.nr_nodes);
 
    auto readNode = [&fin](node& n) {
        fin >> n.node_id >> n.function_id >> n.value;
        int child_count;
        fin >> child_count;
        n.child_nodes_id.resize(child_count);
        for (int& child_id : n.child_nodes_id) {
            fin >> child_id;
        }
    };
 
    for_each(current_tree.nodes.begin(), current_tree.nodes.end(), readNode);
}
 
static inline void load_trees(bool global = 1) {
    bool filesFound = true;
 
    std::string path;
    if(global == 1)
        path = TREES_TO_LOAD_FOLDER_GLOBAL;
    else
        path = TREES_TO_LOAD_FOLDER_LOCAL;
 
    for (int i = 1; i <= NR_BEST_TREES; ++i) {
        std::string filename = path + "tree_to_load_" + std::to_string(i);
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
        std::string filename = path + "tree_to_load_" + std::to_string(i);
        loadTreeFromFile(filename, current_tree);
        bestTrees.push_back(current_tree);
    }
 
    std::cout << "Loading trees: " << std::endl;
    for (const tree& t : bestTrees) {
        std::cout << "Fm Value: " << t.fm_value << std::endl;
    }
}
 
static inline void store_tree(int index, const tree& t, bool global = 1) {
    stringstream tree_filename, fm_filename;
 
    if(global == 1) {
        tree_filename << TREES_TO_LOAD_FOLDER_GLOBAL << "tree_to_load_" << index;
        fm_filename << TREES_TO_LOAD_FOLDER_GLOBAL << "f_measure_tree_" << index;
    } else {
        tree_filename << TREES_TO_LOAD_FOLDER_LOCAL << "tree_to_load_" << index;
        fm_filename << TREES_TO_LOAD_FOLDER_LOCAL << "f_measure_tree_" << index;
    }
 
    ofstream tree_file(tree_filename.str()), fm_file(fm_filename.str());
    fm_file << "Fm Value: " << t.fm_value << '\n'
            << "Number of nodes: " << t.nr_nodes << '\n';
 
    tree_file << t.fm_value << " " << t.nr_nodes << " ";
    for (const auto& node : t.nodes) {
        tree_file << node.node_id << " " << node.function_id << " " << node.value << " "
                  << node.child_nodes_id.size() << " ";
        copy(node.child_nodes_id.begin(), node.child_nodes_id.end(), ostream_iterator<int>(tree_file, " "));
        tree_file << '\n';
    }
}
 
static inline void store_tree_explicit(int index, const tree& t, bool global = 1) {
    stringstream tree_filename;
 
    if(global == 1)
        tree_filename << TREES_TO_LOAD_FOLDER_GLOBAL << "tree_to_load_" << index << "_explicit";
    else
        tree_filename << TREES_TO_LOAD_FOLDER_LOCAL << "tree_to_load_" << index << "_explicit";
 
    ofstream tree_file(tree_filename.str());
    tree_file << "Fmeasure: " << t.fm_value << "\n"
              << "Num. nodes: " << t.nr_nodes << "\n\n";
 
    for (const auto& node : t.nodes) {
        tree_file << "Node id: " << node.node_id << "\n"
                  << "Node function: " << node.function_id << "\n"
                  << "Node value: " << node.value << '\n'
                  << "Node childs: " << node.child_nodes_id.size() << "\nChilds: ";
 
        if (node.child_nodes_id.empty()) {
            tree_file << "I AM A LEAF!" << '\n';
        } else {
            copy(node.child_nodes_id.begin(), node.child_nodes_id.end(), ostream_iterator<int>(tree_file, " "));
            tree_file << '\n';
        }
        tree_file << '\n';
    }
}
 
static inline void printNodeWithDepth(const node& n, int depth, const string& prefix) {
    cout << prefix;
    if (depth > 0) {
        cout << "|-- ";
    }
 
    cout << "*" << n.node_id << "-(" << n.value << ")-[" << n.function_id << "]";
    if (n.child_nodes_id.empty()) {
        cout << " (LEAF)";
    }
    cout << endl;
}
 
static inline void printNodeWithDepth(ofstream& out, const node& n, int depth, const string& prefix) {
    out << prefix;
    if (depth > 0) {
        out << "|-- ";
    }
 
    out << "*" << n.node_id << "-(" << n.value << ")-[" << n.function_id << "]";
    if (n.child_nodes_id.empty()) {
        out << " (LEAF)";
    }
    out << endl;
}
 
static inline void printTreeWithDepth(ofstream& out, const vector<node>& nodes, const map<int, int>& nodeIndexMap, int node_id, int depth = 0, const string& prefix = "") {
    auto it = nodeIndexMap.find(node_id);
    if (it == nodeIndexMap.end()) return; // Node not found
 
    const node& n = nodes[it->second];
    printNodeWithDepth(out, n, depth, prefix);
 
    string newPrefix = prefix + (depth > 0 ? "|   " : "    ");
    for (size_t i = 0; i < n.child_nodes_id.size(); ++i) {
        int child_id = n.child_nodes_id[i];
        if (i == n.child_nodes_id.size() - 1) {
            newPrefix = prefix + "    ";
        }
        printTreeWithDepth(out, nodes, nodeIndexMap, child_id, depth + 1, newPrefix);
    }
}
 
static inline void findAndPrintRoots(ofstream& out, const vector<node>& nodes, const map<int, int>& nodeIndexMap) {
    // Finding root nodes (nodes that are not children of any other nodes)
    set<int> childNodes;
    for (const auto& n : nodes) {
        childNodes.insert(n.child_nodes_id.begin(), n.child_nodes_id.end());
    }
 
    for (const auto& n : nodes) {
        if (childNodes.find(n.node_id) == childNodes.end()) {
            // This node is not a child of any other node, hence it's a root
            printTreeWithDepth(out, nodes, nodeIndexMap, n.node_id);
            // out << endl; // Separate different trees/roots for clarity
        }
    }
}
 
static inline void tree_build(int id, map<int, node> &nodes) {
 
    for (auto x : nodes[id].child_nodes_id) {
        tree_build(x, nodes);
    }
 
    vector<double> child_values;
    for (auto c : nodes[id].child_nodes_id) {
        child_values.push_back(nodes[c].value);
    }
 
    if (nodes[id].function_id != -1) {
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
        case -1:
            // Nod frunza, nu aplicam functie
            nodes[id].value = 0;
            break;
        default:
            std::cerr << "Function number not found: " << nodes[id].function_id << "!\n";
            break;
        }
    }
}
 
std::mt19937 gen(std::random_device{}());
 
vector<int> randomPermutation(int n) {
    vector<int> permutation(n);
    iota(permutation.begin(), permutation.end(), 1);
    shuffle(permutation.begin(), permutation.end(), gen);
    return permutation;
}
 
int getRandomInRange(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}
 
static inline tree generate_tree(int data_size, map<int, node> &nodes) {
    int tree_levels = getRandomInRange(MIN_TREE_LEVELS, MAX_TREE_LEVELS);
    vector<vector<int>> tree_on_levels(tree_levels);
    tree tree;
    tree.nr_nodes = 0;
    int current_id = 1;
 
    // Parallelism here requires careful management of shared variables
    #pragma omp parallel for
    for (int i = 0; i < tree_levels; ++i) {
        int nr_on_level = (i == tree_levels - 1) ? data_size : getRandomInRange(MIN_NODES_ON_LEVEL, MAX_NODES_ON_LEVEL);
 
        #pragma omp critical
        {
            tree_on_levels[i].resize(nr_on_level);
            iota(tree_on_levels[i].begin(), tree_on_levels[i].end(), current_id);
            current_id += nr_on_level;
            tree.nr_nodes += nr_on_level;
        }
    }
 
    #pragma omp parallel for
    for (int i = 0; i < (int) tree_on_levels.size() - 1; ++i) {
        for (auto id : tree_on_levels[i]) {
            node new_node;
            new_node.node_id = id;
            new_node.value = -1;
            new_node.function_id = getRandomInRange(1, NR_OF_FUNCTIONS);
            nodes[id] = new_node;
        }
    }
 
    #pragma omp parallel for
    for (int i = 0; i < (int) tree_on_levels.size() - 1; ++i) {
        int first_id_on_next_level = tree_on_levels[i + 1][0];
        for(auto &n : tree_on_levels[i]) {
            int nr_childs = getRandomInRange(1, tree_on_levels[i + 1].size());
            vector<int> permutation = randomPermutation(nr_childs);
            for (auto x : permutation) {
                nodes[n].child_nodes_id.push_back(first_id_on_next_level + x - 1);
            }
        }
    }
 
    #pragma omp parallel for
    for (auto id : tree_on_levels.back()) {
        node new_node;
        new_node.node_id = id;
        new_node.function_id = -1;
        nodes[id] = new_node;
    }
 
    return tree;
 
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
 
    // Read lines from file
    while (getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string value;
 
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }
    file.close();
 
    return data;
}
 
static inline void f_measure_build(int p, vector<vector<string>> data, vector<vector<string>> fm_data) {
    map<int, node> nodes;
 
    double final_fm = 0;
    int nr_files = 0;
    tree tree;
    if (p != 1) {
        bool first_tree = true;
        for (const auto& entry : filesystem::directory_iterator(FILE_INPUTS_LOCAL)) {
            auto data = readCsvFile(entry.path().string());
            if (first_tree) {
                tree = generate_tree(data[0].size() - 2, nodes);
                first_tree = false;
            }
            double tp = 0, fp = 0, tn = 0, fn = 0;
            for (size_t i = 0; i < data.size(); ++i) {
                int contor = 2;
                for (int j = 1; j <= tree.nr_nodes; ++j) {
                    if (nodes[j].function_id == -1) {
                        nodes[j].value = stod(data[i][contor++]);
                    }
                }
                tree_build(1, nodes);
                double res = nodes[1].value;
                double pixel_value = stod(data[i][0]);
                int ground_truth = stoi(data[i][1]);
                int value = pixel_value < res ? 0 : 1;
                if (value == 1 && ground_truth == 1) tp++;
                if (value == 1 && ground_truth == 0) fp++;
                if (value == 0 && ground_truth == 0) tn++;
                if (value == 0 && ground_truth == 1) fn++;
            }   
            double current_fm = tp / (tp + 0.5 * (fp + fn));
            final_fm += current_fm;
            ++nr_files;
        }
        final_fm /= nr_files;
        final_fm *= 100;
    } else {
        #pragma omp parallel for
        for (size_t i = 0; i < data.size(); ++i) {
            tree = generate_tree(data[i].size(), nodes);
            int contor = 0;
            #pragma omp parallel for
            for (int j = 1; j <= tree.nr_nodes; ++j) {
                if (nodes[j].function_id == -1) {
                    nodes[j].value = stod(data[i][contor++]);
                }
            }
            tree_build(1, nodes);
            double res = nodes[1].value;
            if (res < 0 || res > 1) {
                // Handle the error for 'res' being out of expected range
                // std::cerr << "Res out of bonds! Res:" << res << " value: " << nodes[1].value << std::endl;
            }
 
            int index = static_cast<int>(255 * res);
            if (index < 0 || index >= fm_data[i].size()) {
                // Handle the error for index being out of bounds
                // std::cerr << "Index out of bonds: " << index << std::endl;
            } else {
                try {
                    double current_fm = stod(fm_data[i][index]);
                    final_fm += current_fm;
                } catch (const std::invalid_argument& e) {
                    // Handle the error for invalid string to double conversion
                    // std::cerr << "Invalid string conversion to double!"<< std::endl;
                }
            }
        }
        final_fm /= data.size();
    }
    tree.fm_value = final_fm;
    for (int i = 1; i <= tree.nr_nodes; ++i) {
        tree.nodes.push_back(nodes[i]);
    }
 
    bestTrees.push_back(tree);
 
}
 
// Function to check if a filename has a valid CSV extension
bool hasValidCsvExtension(const std::string& filename) {
    return filename.find(CSV_EXTENSION) != std::string::npos;
}
 
// Function to load data from a CSV file and remove the header
std::vector<std::vector<std::string>> loadDataFromFile(const std::string& filename) {
    std::vector<std::vector<std::string>> data = readCsvFile(filename);
 
    if (!data.empty()) {
        data.erase(data.begin()); // Remove the header
    }
 
    return data;
}
 
// Function to sort and keep the best trees
void sortAndKeepBestTrees(std::vector<tree>& bestTrees) {
    std::sort(bestTrees.begin(), bestTrees.end(), [](const tree& a, const tree& b) {
        return a.fm_value > b.fm_value;
    });
}
 
// Function to print trees
void printTrees(const std::vector<tree>& bestTrees) {
    std::cout << std::endl << "New trees:" << std::endl;
    int cnt = 0;
    for (const tree& t : bestTrees) {
        std::cout << "Tree: " << ++cnt << " Fm Value: " << t.fm_value << std::endl;
    }
}
// Function to store a tree and its structure
void storeTreeAndStructure(int treeIndex, const tree& tree) {
    store_tree(treeIndex, tree, 1);
    store_tree_explicit(treeIndex, tree, 1);
 
    std::map<int, int> nodeIndexMap;
    for (int j = 0; j < tree.nodes.size(); ++j) {
        nodeIndexMap[tree.nodes[j].node_id] = j;
    }
 
    // Open an ofstream for writing the tree structure
    std::stringstream treeStructureFilename;
    treeStructureFilename << "global/top5Graphs/tree_structure_" << treeIndex << ".txt";
    std::ofstream treeStructureFile(treeStructureFilename.str());
 
    // Print the tree structure to the file
    findAndPrintRoots(treeStructureFile, tree.nodes, nodeIndexMap);
 
    // Close the ofstream
    treeStructureFile.close();
}
 
static inline void start_global_solution(int argc, char **argv) {
 
    if (argc < 5) {
        exit(-1);
    }
 
    int nrTrees = std::atoi(argv[2]);
    std::string file1 = argv[3];
    std::string file2 = argv[4];
 
    if (!hasValidCsvExtension(file1) || !hasValidCsvExtension(file2)) {
        std::cerr << "Wrong file extensions!" << std::endl;
        exit(-1);
    }
 
    std::vector<std::vector<std::string>> data = loadDataFromFile(file1);
    std::vector<std::vector<std::string>> fm_data = loadDataFromFile(file2);
 
    load_trees(1);
 
    int tree_id = 1;
    #pragma omp parallel for
    for (int i = 0; i < nrTrees; ++i) {
        f_measure_build(1, data, fm_data);
        #pragma omp atomic
        ++tree_id;
    }
 
    // Sort and keep the best trees
    sortAndKeepBestTrees(bestTrees);
 
    // Print the new trees
    printTrees(bestTrees);
 
    // Store the best NR_BEST_TREES trees and their structures
    for (int i = 0; i < NR_BEST_TREES && i < bestTrees.size(); ++i) {
        storeTreeAndStructure(i + 1, bestTrees[i]);
    }
 
    // Print the final stored trees
    std::cout << "\nFinal stored trees:\n";
    int i = 0;
    for (const tree& t : bestTrees) {
        if (i == NR_BEST_TREES) {
            break;
        }
        std::cout << "Fm Value: " << t.fm_value << std::endl;
        i++;
    }
}
 
static inline void start_local_solution(int argc, char **argv) {
 
    if (argc < 3) {
        exit(-1);
    }
 
    int nrTrees = std::atoi(argv[2]);
 
    load_trees(0);
 
    vector<vector<string>> data;
 
    int tree_id = 1;
    #pragma omp parallel for
    for (int i = 0; i < nrTrees; ++i) {
        f_measure_build(2, data, data);
        #pragma omp atomic
        ++tree_id;
    }
 
    for (const tree& t : bestTrees) {
        std::cout << "Fm Value: " << t.fm_value << std::endl;
    }
 
    // Sort and keep the best trees
    sortAndKeepBestTrees(bestTrees);
 
    // Print the new trees
    printTrees(bestTrees);
 
    // Store the best NR_BEST_TREES trees and their structures
    for (int i = 0; i < NR_BEST_TREES && i < bestTrees.size(); ++i) {
        storeTreeAndStructure(i + 1, bestTrees[i]);
    }
 
    // Print the final stored trees
    std::cout << "\nFinal stored trees:\n";
    int i = 0;
    for (const tree& t : bestTrees) {
        if (i == NR_BEST_TREES) {
            break;
        }
        std::cout << "Fm Value: " << t.fm_value << std::endl;
        i++;
    }
}
 
int main(int argc, char **argv) {
 
    if (strcmp(argv[1], "global") == 0) {
        start_global_solution(argc, argv);
    }
    else {
        start_local_solution(argc, argv);
    }
 
    return 0;
}