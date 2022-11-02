#include "./binTree.h"

TreeNodeStack* newTreeNodeStack(){
    TreeNodeStack* res = (TreeNodeStack*)malloc(sizeof(TreeNodeStack));
    res->head = NULL;
    return res;
}

void push(TreeNodeStack* stack, TreeNode* value){
    stack->head = newStackNode(value, stack->head);
}

TreeNode* pop(TreeNodeStack* stack) {
    if(stack->head == NULL)
        return NULL;

    TreeNodeStackNode* toFree = stack->head;
    TreeNode* res = toFree->value;
    stack->head = toFree->next;
    free(toFree);
    return res;
}

TreeNodeStackNode* newStackNode(TreeNode* val, TreeNodeStackNode* next) {
    TreeNodeStackNode* res = (TreeNodeStackNode*)malloc(sizeof(TreeNodeStackNode));
    res->value = val;
    res->next = next;
    return res;
}

int isEmpty(TreeNodeStack* stack){
    return stack->head == NULL;
}

