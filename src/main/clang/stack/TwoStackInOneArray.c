#include "../../head/export_index.h"

#define maxSize 20
#define stackLeftCode 0
#define stackRightCode 1

typedef struct TwoStack {
    int *arrayPointer;
    int left;
    int right;
    int capacity;
} stacks;

void CreateStack(stacks *st) {
    st->capacity = maxSize;

    st->arrayPointer = (int *) malloc(sizeof(int) * st->capacity);

    st->left = 0;
    st->right = st->capacity - 1;
}

bool whetherEmpty(stacks *st, int stackNum) {
    bool flag = true;

    // 0 represent left, 1 represent right
    switch (stackNum) {
        case 0:
            if (st->left == 0) {
                printf("stack-left has empty\n");
                flag = false;
            }
            break;

        case 1:
            if (st->right == st->capacity - 1) {
                printf("stack-right has empty\n");
                flag = false;
            }
            break;
        default:
            printf("invalid number\n");
            break;
    }

    return flag;
}

bool whetherFull(stacks *st) {
    if ((st->left + 1) == st->right) {
        printf("\nthis stacks had fulled\n");
        return false;
    }
    return true;
}

void push_ele_to_stack_left(int value, stacks *st) {
    //judge it has full
    whetherFull(st);
    *(st->arrayPointer + st->left) = value;
    st->left++;
}

void push_ele_to_stack_right(int value, stacks *st) {
    //judge it has full
    whetherFull(st);
    *(st->arrayPointer + st->right) = value;
    st->right--;
}

void pop_top_left(stacks *st) {
    //judge it has empty
    bool check = whetherEmpty(st, stackLeftCode);
    if (check == false) {
        return;
    }

    //because index from zero
    int l = *(st->arrayPointer + st->left - 1);
    printf("pop LEFT value: %d\n", l);
    st->left--;
}

void pop_top_right(stacks *st) {
    //judge it has empty
    bool check = whetherEmpty(st, stackRightCode);
    if (check == false) {
        return;
    }

    //because the index from zero
    int r = *(st->arrayPointer + st->right + 1);
    printf("pop RIGHT value: %d\n", r);
    st->right++;
}

void export_two_stack_one_arr() {
    stacks st;
    CreateStack(&st);

    push_ele_to_stack_left(3, &st);
    push_ele_to_stack_left(6, &st);

    push_ele_to_stack_right(96, &st);
    push_ele_to_stack_right(160, &st);

    for (int i = 0; i < 4; ++i) {
        pop_top_left(&st);
        pop_top_right(&st);
    }
}