#ifndef ALGORITHM_TRAINING_CLANG_ENHANCE_H
#define ALGORITHM_TRAINING_CLANG_ENHANCE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef struct BinTreeNode {
    string data;
    struct BinTreeNode *left, *right;
} biTrNode;

vector<string> separate(string &str_parameter, char *identification);

void trunk_execute();

queue<biTrNode *> generate_root(biTrNode *&tr, queue<biTrNode *> q, vector<string> v);

queue<biTrNode *> create_tree_nodes(queue<biTrNode *> q, vector<string> v);

#endif //ALGORITHM_TRAINING_CLANG_ENHANCE_H
