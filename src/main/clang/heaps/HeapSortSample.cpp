#include "../../head/clang_enhance.h"

int heapArray[] = {4, 5, 3, 6, 2, 7};

void sinking2(int nodeIndex, int size) {
    // left child node's index = nodeIndex*2+1
    while ((nodeIndex * 2 + 1) < size) {// if left child node has exists
        int childIndex = nodeIndex * 2 + 1;

        // childIndex<length : if right child node has exists
        // heapArray[childIndex]<heapArray[childIndex+1] : if left child less than right child
        if (childIndex < size && heapArray[childIndex] < heapArray[childIndex + 1]) {
            childIndex++;// so child node index will be pointing to right child
        }

        // if parent node's value is greater than is's childs both left and right
        if (heapArray[nodeIndex] >= heapArray[childIndex]) {
            //meet the requirements, do not exhange, jump out of the loop
            break;
        } else {
            // exchange value with it's children of greater one
            swap(heapArray[nodeIndex], heapArray[childIndex]);
        }

        // pointing to new position of after exchange, continue comparing downward, until the leaf of bottom
        nodeIndex = childIndex;
    }
}

void raiseSorts(int nodeIndex) {
    while (heapArray[nodeIndex] > heapArray[(nodeIndex - 1) / 2]) {
        swap(heapArray[nodeIndex], heapArray[(nodeIndex - 1) / 2]);
        // point to parent of itself
        nodeIndex = (nodeIndex - 1) / 2;
    }
}

/**
 * make the left less than right on every tier
 */
void exchangeLeftAndRight(int length) {
    int n = length - 1;

    // (i * 2 + 1 < length - 1) : means the right child already exists
    for (int i = n / 2; i >= 0; i--) {
        if ((i * 2 + 1 < length - 1) && (heapArray[i * 2 + 1] > heapArray[i * 2 + 2])) {
            swap(heapArray[i * 2 + 1], heapArray[i * 2 + 2]);
        }
    }
}

void buildingMaxHeap(int length) {
    for (int i = length - 1; i >= 0; i--) {
        raiseSorts(i);
    }

    exchangeLeftAndRight(length);
}

void buildMinHeap(int length) {
    buildingMaxHeap(length);

    length = length - 1;

    while (length > 0) {
        // keep exchanging with top one of the tree
        swap(heapArray[0], heapArray[length--]);
        sinking2(0, length);
    }
}

void executeHeapSortSample() {
    int length = sizeof(heapArray) / sizeof(int);
    buildMinHeap(length);

    for (int i = 0; i < length; ++i) {
        cout << heapArray[i] << "  ";
    }
}