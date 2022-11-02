#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode TreeNode;
typedef struct treeNodeStackNode TreeNodeStackNode;
typedef struct treeNodeStack TreeNodeStack;

struct treeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

struct treeNodeStackNode {
    TreeNode* value;
    TreeNodeStackNode* next;
};

struct treeNodeStack {
    TreeNodeStackNode* head;
};

int* inorderTraversal(TreeNode* A, int* len1);
TreeNode* newTreeNode(int);
TreeNode* generateTree();

TreeNodeStack* newTreeNodeStack();
TreeNodeStackNode* newStackNode(TreeNode*, TreeNodeStackNode*);
void push(TreeNodeStack*, TreeNode*);
TreeNode* pop(TreeNodeStack*);
int isEmpty(TreeNodeStack*);