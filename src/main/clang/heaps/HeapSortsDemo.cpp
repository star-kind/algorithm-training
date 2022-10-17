#include "../../head/clang_enhance.h"

/*

                                                        9
                                                        |
                                                 -------|-----------------
                                                |                        |
                                                3                        7
                                     ----------|-------          --------|------------
                                    |                 |         |                    |
                                    6                5          1                   10
                         -----------|
                        |
                        2

it's a entire binary tree, use array do store up:  {9,3,7,6,5,1,10,2}

*/

void ascent_block(int *array, int nodeIndex) {
    //if the node's value greater than it's parent node
    while (array[nodeIndex] > array[(nodeIndex - 1) / 2]) {
        //exchange values with each other
        swap(array[nodeIndex], array[(nodeIndex - 1) / 2]);
        //point to it's parent-node,continue to compare upwards,until the top's root
        nodeIndex = (nodeIndex - 1) / 2;
    }
}

void sink_blocks(int nodeIndex, int heapSize, int *array) {
    int leftIndex = nodeIndex * 2 + 1;
    while (leftIndex < heapSize) {
        int largeChildIndex = (leftIndex + 1 < heapSize && array[leftIndex] < array[leftIndex + 1]) ? leftIndex + 1
                                                                                                    : leftIndex;

        largeChildIndex = (array[largeChildIndex] > array[nodeIndex]) ? largeChildIndex : nodeIndex;

        if (largeChildIndex == nodeIndex) break;

        exchangeBlocks(array, largeChildIndex, nodeIndex);

        nodeIndex = largeChildIndex;
        leftIndex = nodeIndex * 2 + 1;
    }
}

void exchangeBlocks(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sorts_blocks(int *array, int arrSize) {
    if (array == NULL || arrSize == 0) {
        cout << "empty parameter" << endl;
        return;
    } else if (arrSize > 0 && arrSize <= 2) {
        cout << "it's not a binary tree" << endl;
        return;
    }

    for (int i = 0; i < arrSize; ++i) {
        ascent_block(array, i);// 0 ---> i
    }

    exchangeBlocks(array, 0, --arrSize);
    while (arrSize > 0) {
        sink_blocks(0, arrSize, array);
        exchangeBlocks(array, 0, --arrSize);
    }
}

void executeHeapSortsDemo() {
    int array[] = {9, 3, 7, 6, 5, 1, 10, 2};
    int heapSize = sizeof(array) / sizeof(int);

    sorts_blocks(array, heapSize);

    for (int i = 0; i < heapSize; ++i) {
        cout << array[i] << "  ";
    }
}