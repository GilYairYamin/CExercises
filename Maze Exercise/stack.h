#pragma once
#include <stdlib.h>
#include <stdio.h>

struct stack typedef Stack;

struct stack {
    int* arr;
    int len;
    int maxLen;
};

Stack* newStack();
void pushStack(Stack*, int, int);
void popStack(Stack*, int*, int*);
void deleteStack(Stack*);

int isEmptyStack(Stack*);