#include "../../head/clang_enhance.h"

int array[] = {23, 27, 15, 8, 3, 19, 12, 11, 5, 33, 30, 6, 3, 9};

void submerge(int nodeIndex, int heapCapacity) {
    //if left child had exist
    //left child index: (2 * nodeIndex + 1)
    //right child index: (2 * nodeIndex + 2)
    while ((2 * nodeIndex + 1) < heapCapacity) {
        int childIndex = (2 * nodeIndex + 1);

        // childIndex < heapCapacity : if this node's right child had exist
        // array[childIndex] < array[childIndex + 1]: left child < right child
        if (childIndex < heapCapacity && array[childIndex] < array[childIndex + 1]) {
            childIndex++;// point to right child
        }

        // if this node has been greater than it's childs (including left & right)
        if (array[nodeIndex] >= array[childIndex]) {
            break;//meet the heap sort conditions, jump it out
        } else {
            // exchange value with it child of greater node
            swap(array[nodeIndex], array[childIndex]);
        }

        //point to new position after exchange, continue to compare downwards, until the leafs submerge in bottom
        nodeIndex = childIndex;
    }
}

void creatingHeap(int nodeNums) {
    int lastParentIndex = (nodeNums - 1) / 2;

    for (int i = lastParentIndex; i >= 0; i--) {
        submerge(i, nodeNums);
    }
}

void heapSorting(int nodeQuantity) {
    creatingHeap(nodeQuantity);
    nodeQuantity -= 1;// index of last element in array

    while (nodeQuantity > 0) {
        swap(array[0], array[nodeQuantity--]);
        submerge(0, nodeQuantity);
    }
}

/**
 * building a min-heap sort program
 */
void executingHeapSortDemo1() {
    int capacity = sizeof(array) / sizeof(int);
    heapSorting(capacity);

    for (int i = 0; i < capacity; ++i) {
        cout << array[i] << "  ";
    }
}