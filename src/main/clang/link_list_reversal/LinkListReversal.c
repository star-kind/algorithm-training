#include "../../head/export_index.h"

#define maxRange 100

typedef struct LINK_NODE {
    int data;
    struct LINK_NODE *next;
} linkN;

void creates_link_node(int *array, int arr_len, linkN *head_node) {
    linkN *ptr, *tmp;
    int i = 0;

    ptr = head_node;

    while (arr_len--) {
        tmp = (linkN *) malloc(sizeof(linkN));

        tmp->data = *(array + i++);
        tmp->next = NULL;

        ptr->next = tmp;
        ptr = tmp;
    }
}

void ergodic_print_link(linkN *ptr) {
    linkN *temp = ptr->next;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n\r");
}

void ergodic_invert_link(linkN *ptr) {
    linkN *temp = ptr;
    while (temp->next) { //while (temp->next) being equal true(1)
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n\r");
}

linkN *invert_link_list(linkN *ptr_node) {
    linkN *mid, *head, *last;

    head = ptr_node;
    mid = NULL;//mid is in front of head

    while (head != NULL) {
        last = mid;//last is behind head
        mid = head;
        head = head->next;
        mid->next = last;
    }

    return mid;
}

int get_arr_size(int *array) {
    int *p = array;
    int e = 0, d = 0;

    while (*(p + e++)) {
        //printf("%d\n", *(p + d));
        d++;
    }
    printf("Array Length=%d\n\r", d);
    return d;
}

void link_list_initialization(linkN *link) {
    link = (linkN *) malloc(sizeof(linkN));
    link->next = NULL;
}

void link_list_export() {
    linkN lin;
    link_list_initialization(&lin);

    int arr[maxRange] = {10, 18, 26, 29, 33, 47, 49, 108};
    int arr_size = get_arr_size(arr);

    creates_link_node(arr, arr_size, &lin);
    ergodic_print_link(&lin);

    linkN *p = invert_link_list(&lin);
    ergodic_invert_link(p);
}