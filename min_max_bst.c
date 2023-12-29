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

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to find the maximum value node in a BST
struct Node* findMax(struct Node* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

// Function to perform inorder traversal of a BST and count nodes
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    int n, key;

    // Get the number of nodes from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Insert nodes into the BST based on user input
    printf("Enter the key values:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Find the minimum value node
    struct Node* minNode = findMin(root);
    printf("Minimum value in the BST: %d\n", minNode->data);

    // Find the maximum value node
    struct Node* maxNode = findMax(root);
    printf("Maximum value in the BST: %d\n", maxNode->data);

    // Count the number of nodes in the BST#include <stdio.h>
    int nodeCount = countNodes(root);
    printf("Number of nodes in the BST: %d\n", nodeCount);

    // Display the elements of the BST using inorder traversal
    printf("Elements of the BST (Inorder Traversal): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
