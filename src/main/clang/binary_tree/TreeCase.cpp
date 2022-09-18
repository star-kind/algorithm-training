#include "../../head/clang_plus_x.h"

#define DWORD unsigned long
#define SUCCESS 1
#define ERROR -1

template<class T>
class TreeNode {
public:
    T element;

    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;

    TreeNode(T &ele) {
        //initialize
        memset(&element, 0, sizeof(TreeNode));
        //assignment for element
        memcpy(&element, &ele, sizeof(T));
        left = right = parent = NULL;
    }

    //overload:==,comapre whether equals or not between two node
    bool operator==(TreeNode<T> *node) {
        return node->element == element ? true : false;
    }
};

template<class T>
class BSortTree {
public:
    BSortTree();

    ~BSortTree();

public:
    DWORD Insert(T ele);

    void InOrderTraverse(TreeNode<T> *ptNode);

    TreeNode<T> *getRootNode();

private:
    DWORD InsertNode(T ele, TreeNode<T> *ptNode);

    void ClearMemory(TreeNode<T> *node);

private:
    TreeNode<T> *mPtrRoot;
    int size;
};


template<class T>
BSortTree<T>::BSortTree() {
    cout << "structor" << endl;
    mPtrRoot = NULL;
    size = 0;
}

template<class T>
TreeNode<T> *BSortTree<T>::getRootNode() {
    return mPtrRoot;
}

template<class T>
BSortTree<T>::~BSortTree() {
    cout << "destructor" << endl;
    ClearMemory(mPtrRoot);
}

template<class T>
void BSortTree<T>::ClearMemory(TreeNode<T> *node) {
    if (node != NULL) {
        ClearMemory(node->left);
        ClearMemory(node->right);
        delete node;
        node = NULL;
    }
}

template<class T>
DWORD BSortTree<T>::Insert(T element) {
    if (!mPtrRoot)//if root node is empty
    {
        mPtrRoot = new TreeNode<T>(element);
        size++;
        return SUCCESS;
    }

    return InsertNode(element, mPtrRoot);
}

template<class T>
DWORD BSortTree<T>::InsertNode(T element, TreeNode<T> *pNode) {
    TreeNode<T> *pNewNode = new TreeNode<T>(element);

    //if element equals current node,direct return
    if (element == pNode->element) {
        return SUCCESS;
    }

    if (pNode->left == NULL && element < pNode->element) {
        pNode->left = pNewNode;
        pNewNode->parent = pNode;
        size++;
        return SUCCESS;
    }

    if (pNode->right == NULL && element > pNode->element) {
        pNode->right = pNewNode;
        pNewNode->parent = pNode;
        size++;
        return SUCCESS;
    }

    if (element < pNode->element) {
        InsertNode(element, pNode->left);
    } else {
        InsertNode(element, pNode->right);
    }

    return SUCCESS;
}

template<class T>
void BSortTree<T>::InOrderTraverse(TreeNode<T> *node) {
    if (node != NULL) {
        InOrderTraverse(node->left);
        cout << node->element << endl;
        InOrderTraverse(node->right);
    }
}

void TestTreeCase() {
    BSortTree<int> t;

    t.Insert(10);
    t.Insert(13);
    t.Insert(15);
    t.Insert(17);
    t.Insert(19);
    t.Insert(22);
    t.Insert(24);

    TreeNode<int> *q = t.getRootNode();
    t.InOrderTraverse(q);
}