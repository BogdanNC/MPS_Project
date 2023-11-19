#include <bits/stdc++.h>
#include <omp.h>
#include "FunctionKing.h"
using namespace std;

// ./o_global 5 global/GlobalTest.csv global/LUTTest.csv

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define NUMBER_OF_ARGS 4
#define MAX_TREE_LEVELS 6
#define MAX_NODES_ON_LEVEL 6
#define NR_OF_FUNCTIONS 9
#define NR_BEST_TREES 5
#define BEST_TREES_PATH "global/top5Graphs/"
#define CSV_EXTENSION ".csv"

// Create an instance of the FunctionKing class
FunctionKing functionKing;

struct node {
    int node_id;
    int function_id;
    double value;
    vector<int> child_nodes_id;
};
map<int, string> func_description;


struct tree {
    double fm_value;
    int nr_nodes;
    vector<node> nodes;
};

vector<tree> bestTrees;

void load_trees() {
    for (int i = 1; i <= NR_BEST_TREES; ++i) {
        ifstream fin(BEST_TREES_PATH + to_string(i) + "_structure");
        tree current_tree;
        fin >> current_tree.fm_value;
        fin >> current_tree.nr_nodes;
        for (int j = 0; j < current_tree.nr_nodes; ++j) {
            node current_node;
            fin >> current_node.node_id >> current_node.function_id >> current_node.value;
            int childs_nr;
            fin >> childs_nr;
            for (int t = 0; t < childs_nr; ++t) {
                int child_id;
                fin >> child_id;
                current_node.child_nodes_id.push_back(child_id);
            }
            current_tree.nodes.push_back(current_node);
        }
        bestTrees.push_back(current_tree);
    }
}

void store_tree(int i, tree tree) {
    ofstream fout(BEST_TREES_PATH + to_string(i) + "_structure");
    ofstream fout1(BEST_TREES_PATH + to_string(i) + "_description");
    fout1 << "Fm Value: " << tree.fm_value << '\n';
    fout << tree.fm_value << " ";
    fout1 << "Number of nodes: " << tree.nr_nodes << '\n';
    fout << tree.nr_nodes << " ";
    for (auto current_node : tree.nodes) {
        fout1 << "Node #" << current_node.node_id << " has function " << func_description[current_node.function_id] << ", value " << current_node.value << " and child nodes: ";
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



void log_data(int node_id, map<int, node> nodes) {
    cout << "Node Id: " << node_id << '\n';
    cout << "Function aplied: " << func_description[nodes[node_id].function_id] << '\n';
    cout << "Value: " << nodes[node_id].value << '\n';
    cout << "Child nodes id's: ";
    for (auto x : nodes[node_id].child_nodes_id) {
        cout << x << " ";
    } 

    cout << "\n\n";

}

double apply_function(vector<double> numbers, int function_id) {
    double res = 0;
    if (function_id == 1) {
        for (auto x : numbers) {
            res += x;
        }
        res /= numbers.size();
    }
    else if (function_id == 2) {
        res = 1;
        for (auto x : numbers) {
            res *= x;
        }
        res = powf(res, 1. / numbers.size());
    }
    else if (function_id == 3) {
        for (auto x : numbers) {
            res += x;
        }
        res *= 100;
        res = (int) res % 17;
        res /= 100;
    }
    else if (function_id == 4) {
        for (auto x : numbers) {
            res = max(res, x);
        }
    }
    else if (function_id == 5) {
        res = 1e9;
        for (auto x : numbers) {
            res = min(res, x);
        }
    }
    else if (function_id == 6) {
        for (auto x : numbers) {
            res += abs(x - 0.33);
            if (res > 1) {
                --res;
            }
        }
    }
    else if (function_id == 7) {
        for (auto x : numbers) {
            res += sin(x);
        }
        res = abs(res);
        while (res >= 1) --res;
    }
    else if (function_id == 8) {
        for (auto x : numbers) {
            res -= cos(x);
        }
        res = abs(res);
        while (res >= 1) --res;
    }
    else if (function_id == 9) {
        for (auto x : numbers) {
            res += x * x * x;
            if (res >= 1) --res;
        }
    }
    else if (function_id == 10) {
        for (auto x : numbers) {
            res += sqrt(abs(x * x - 4 * x));
            if (res >= 1) --res;
        }
    }

    return res;
}

void tree_build(int id, map<int, node> &nodes) {
    for (auto x : nodes[id].child_nodes_id) {
        tree_build(x, nodes);
    }
    vector<double> childs_values;
    for (auto c : nodes[id].child_nodes_id) {
        childs_values.push_back(nodes[c].value);
    }

    nodes[id].value = apply_function(childs_values, nodes[id].function_id);

    // Concatenating to form a function name
    std::string baseName = "function";
    std::string funcName = baseName + std::to_string(nodes[id].function_id);

    // Calling the function
    /*
    try
    {
        if (functionKing._get_funcMap().find(funcName) != functionKing._get_funcMap().end()) {
            functionKing._get_funcMap()[funcName](childs_values); 
        } else {
            std::cout << "Function not found" << std::endl;
        }
    } catch (int e)
    {
        cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
    */
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

void generate_tree(vector<vector<string>> data, vector<vector<string>> fm_data, int tree_id) {

    map<int, node> nodes;
    int tree_levels = rng() % MAX_TREE_LEVELS + 1;
    vector<vector<int>> tree_on_levels;
    tree tree;
    tree.nr_nodes = 0;
    int current_id = 1;
    for (int i = 1; i <= tree_levels; ++i) {
        int nr_on_level = rng() % MAX_NODES_ON_LEVEL + 1;
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

    for (int i = 0; i < (int) tree_on_levels.size() - 1; ++i) {
        for (auto id : tree_on_levels[i]) {
            node new_node;
            new_node.node_id = id;
            new_node.value = -1;
            new_node.function_id = rng() % NR_OF_FUNCTIONS + 1;
            nodes[id] = new_node;
        }
    }

    for (int i = 0; i < (int) tree_on_levels.size() - 1; ++i) {
        int first_id_on_next_level = tree_on_levels[i + 1][0];
        for(auto &n : tree_on_levels[i]) {
            int nr_childs = rng() % tree_on_levels[i + 1].size() + 1;
            vector<int> permutation = randomPermutation(nr_childs);
            for (auto x : permutation) {
                nodes[n].child_nodes_id.push_back(first_id_on_next_level + x - 1);
            }
        }
    }

    double final_fm = 0;
    for (int i = 0; i < (int) data.size(); ++i) {
        int p = 0;
        for (auto id : tree_on_levels.back()) {
            node new_node;
            new_node.node_id = id;
            new_node.value = stod(data[i][p++]);
            new_node.function_id = -1;
            nodes[id] = new_node;
        }
        tree_build(1, nodes);
        double res = nodes[1].value;
        double current_fm = stod(fm_data[i][255 * res]);
        final_fm += current_fm;
    }
    final_fm /= data.size();
    tree.fm_value = final_fm;
    for (int i = 1; i <= tree.nr_nodes; ++i) {
        tree.nodes.push_back(nodes[i]);
    }
    bestTrees.push_back(tree);
}

bool cmp(const tree &a, const tree &b) {
    return a.fm_value > b.fm_value;
}

int main(int argc, char **argv)
{
    if (argc != NUMBER_OF_ARGS) {
        cout << "Wrong ussage: different number of arguments!\n";
        cout << "Correct ussage: ./o_global file1.csv file2.csv";
    }
    int nrTrees = atoi(argv[1]);
    string file1 = argv[2];
    string file2 = argv[3];
    if (file1.find(CSV_EXTENSION) == string::npos || file2.find(CSV_EXTENSION) == string::npos) {
        cout << "Wrong file extensions!\n";
        cout << "Correct ussage: ./o_global nrTrees file1.csv file2.csv";
    }

    ifstream image_file(file1);
    ifstream fm_file(file2);

    string line;
    vector<string> headers;
    vector<vector<string>> data;

    if (getline(image_file, line)) {
        stringstream ss(line);
        string header;
        while (getline(ss, header, ',')) {
            headers.push_back(header);
        }
    }

    while (getline(image_file, line)) {
        vector<string> row;
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }

    image_file.close();

    vector<string> fm_headers;
    vector<vector<string>> fm_data;
    if (getline(fm_file, line)) {
        stringstream ss(line);
        string header;
        while (getline(ss, header, ',')) {
            fm_headers.push_back(header);
        }
    }

    while (getline(fm_file, line)) {
        vector<string> row;
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        fm_data.push_back(row);
    }

    fm_file.close();

    load_trees();
    func_description[1] = "mean of numbers";
    func_description[2] = "geometric mean of numbers";
    func_description[3] = "sum of numbers % 17 divided by 100";
    func_description[4] = "max of numbers";
    func_description[5] = "min of numbers";
    func_description[6] = "sum of numbers |x - 0.33| reduced at less than 1";
    func_description[7] = "sum of sin(x) in absolute value reduced at less than 1";
    func_description[8] = "substraction of cos(x) in absolute value reduced at less than 1";
    func_description[9] = "sum of x^3 reduced at less than 1";
    func_description[10] = "sum of sqrt(abs(x * x - 4 * x)) educed at less than 1";

    // Parallel region starts here
    #pragma omp parallel for shared(data, fm_data)
    for (int i = 0; i < nrTrees; ++i) {
        int tree_id = i + 1; // Each thread gets a unique tree_id
        generate_tree(data, fm_data, tree_id);
    }
    // Parallel region ends here

    sort(bestTrees.begin(), bestTrees.end(), cmp);

    for (int i = 0; i < NR_BEST_TREES; ++i) {
        store_tree(i + 1, bestTrees[i]);
    }

    return 0;
}