#include "./binTree.h"

int main() {
	int length = 0;
	
	TreeNode* root = generateTree();
	int* resArr = inorderTraversal(root, &length);

	printf("len is: %d \n", length);
	for (int i = 0; i < length; i++) {
		printf("%d ", resArr[i]);
	}
	printf("\n");
}



