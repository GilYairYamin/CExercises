//============================================================================
// Name        : InorderBinaryTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>

// Definition for binary tree
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode treenode;

treenode* treenode_new(int val) {
	treenode *node = (treenode*) malloc(sizeof(treenode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct treeStack {
	treenode *value;
	treeStack *next;
};

int* copyArrayWithExtraSpace(int *arr, int *len, int addition) {
	int newLength = *len + addition;
	int *newArr = (int*)calloc(newLength, sizeof(int));

	for (int i = 0; i < *len; i++) {
		newArr[i] = arr[i];
	}
	*len += addition;
	return newArr;
}

int* inorderTraversal(treenode *A, int *len1) {
	int *resArr = NULL;
	int *tempArr = NULL;
	treenode *temp = A;
	treeStack *stack = NULL;
	treeStack *tempNode = NULL;

	int counter = 0;
	int index = 0;

	while (temp != NULL) {
		counter++;
		while (temp->left != NULL) {
			counter++;
			tempNode = (treeStack*) malloc(sizeof(struct treeStack));
			tempNode->value = temp;
			tempNode->next = stack;
			stack = tempNode;
			temp = temp->left;
		}
		tempArr = copyArrayWithExtraSpace(resArr, len1, counter);
		free(resArr);
		resArr = tempArr;
		counter = 0;
		resArr[index++] = temp->val;
		while (stack != NULL && temp->right == NULL) {
			temp = stack->value;
			tempNode = stack;
			stack = stack->next;
			free(tempNode);
			resArr[index++] = temp->val;
		}
		temp = temp->right;
	}
	return resArr;
}

int main() {
	int length = 0;
	int *resArr = NULL;
	int check[0] = { };
	resArr = check;

	treenode *n1 = treenode_new(1);
	treenode *n2 = treenode_new(2);
	treenode *n3 = treenode_new(3);
	treenode *n4 = treenode_new(4);
	treenode *n5 = treenode_new(5);
	treenode *n6 = treenode_new(6);
	treenode *n7 = treenode_new(7);
	treenode *n8 = treenode_new(8);

	n1->left = n2;
	n2->left = n3;
	n3->left = n4;
	n2->right = n5;
	n5->left = n6;
	n3->right = n7;
	n6->left = n8;

	resArr = inorderTraversal(n1, &length);

	printf("len is: %d \n", length);
	for (int i = 0; i < length; i++) {
		printf("%d ", resArr[i]);
	}
	printf("\n");
}

