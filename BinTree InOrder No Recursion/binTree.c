#include "./binTree.h"

TreeNode* generateTree() {
    TreeNode* n1 = newTreeNode(1);
    TreeNode* n2 = newTreeNode(2);
    TreeNode* n3 = newTreeNode(3);
    TreeNode* n4 = newTreeNode(4);
    TreeNode* n5 = newTreeNode(5);
    TreeNode* n6 = newTreeNode(6);
    TreeNode* n7 = newTreeNode(7);
    TreeNode* n8 = newTreeNode(8);

    n1->left = n2;
    n2->left = n3;
    n3->left = n4;
    n2->right = n5;
    n5->left = n6;
    n3->right = n7;
    n6->left = n8;

    return n1;
}

TreeNode* newTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int* inorderTraversal(TreeNode* A, int* len1) {
    int arrLen = 0;
    int* resArr = (int*)malloc(0);

    TreeNode* temp = A;
    TreeNodeStack* stack = newTreeNodeStack();

    int counter = 0;
    int index = 0;

    while (temp != NULL) {
        counter++;
        while (temp->left != NULL) {
            counter++;
            push(stack, temp);
            temp = temp->left;
        }
        arrLen += counter;
        resArr = (int*)realloc(resArr, sizeof(int) * arrLen);

        counter = 0;
        resArr[index++] = temp->val;
        while (!isEmpty(stack) && temp->right == NULL) {
            temp = pop(stack);
            resArr[index++] = temp->val;
        }
        temp = temp->right;
    }
    *len1 = arrLen;

    return resArr;
}

