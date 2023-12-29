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

// Function to search for a key in the BST (non-recursive)
struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        // If the key is present at the root
        if (key == root->data) {
            return root;
        }

        // If the key is greater than the root's key, move to the right subtree
        if (key > root->data) {
            root = root->right;
        }
        // If the key is smaller than the root's key, move to the left subtree
        else {
            root = root->left;
        }
    }

    // Key not found
    return NULL;
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

    // Ask the user for the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Search for the key in the BST
    struct Node* result = search(root, key);

    // Display the search result
    if (result != NULL) {
        printf("Key %d found in the BST.\n", key);
    } else {
        printf("Key %d not found in the BST.\n", key);
    }

    return 0;
}
