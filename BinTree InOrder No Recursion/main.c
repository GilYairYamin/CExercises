#include "./binTree.h"

int main() {
	int length = 0;
	int* resArr = NULL;
	TreeNode* root = generateTree();
	resArr = inorderTraversal(root, &length);
	
	printf("len is: %d \n", length);
	for (int i = 0; i < length; i++) {
		printf("%d ", resArr[i]);
	}
	printf("\n");
}

