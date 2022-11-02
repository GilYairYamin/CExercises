#include "./stack.h"

#define INIT_SIZE 4
#define MULTIPLY 2

Stack* newStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->len = 0;
    newStack->maxLen = INIT_SIZE;
    newStack->arr = (int*)calloc(sizeof(int), INIT_SIZE);
    return newStack;
}

int isEmptyStack(Stack* stack) {
    return stack->len == 0;
}

void pushStack(Stack* stack, int row, int col) {
    if (stack->len >= stack->maxLen - 1) {
        stack->maxLen = stack->maxLen * MULTIPLY;
        stack->arr = (int*)realloc(stack->arr, sizeof(int) * stack->maxLen);
    }
    stack->arr[stack->len++] = row;
    stack->arr[stack->len++] = col;
}

void popStack(Stack* stack, int* row, int* col) {
    if (stack->len < 1)
        return;
    *col = stack->arr[--stack->len];
    *row = stack->arr[--stack->len];
}

void deleteStack(Stack* stack) {
    free(stack->arr);
}