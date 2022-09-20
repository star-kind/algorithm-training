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

void centralCapital();

#endif //ALGORITHM_TRAINING_CLANG_ENHANCE_H
