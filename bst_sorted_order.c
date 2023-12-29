#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build a BST from a sorted array
struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    // Get the middle element of the array as the root
    int mid = (start + end) / 2;
    struct Node* root = createNode(arr[mid]);

    // Recursively build the left and right subtrees
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to perform inorder traversal of a BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    int n;

    // Get the number of elements in the sorted array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the sorted array elements
    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Build the BST from the sorted array
    struct Node* root = sortedArrayToBST(arr, 0, n - 1);

    // Perform inorder traversal to verify the BST
    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

