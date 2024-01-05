#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node* left_child;
    struct Node* right_child;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left_child = newNode->right_child = NULL;
    return newNode;
}

// Function to insert a key into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left_child = insert(root->left_child, key);
    } else if (key > root->key) {
        root->right_child = insert(root->right_child, key);
    }

    return root;
}

// Function to find the minimum value node in BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left_child != NULL) {
        current = current->left_child;
    }
    return current;
}

// Function to delete a key from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left_child = deleteNode(root->left_child, key);
    } else if (key > root->key) {
        root->right_child = deleteNode(root->right_child, key);
    } else {
        // Node with only one child or no child
        if (root->left_child == NULL) {
            struct Node* temp = root->right_child;
            free(root);
            return temp;
        } else if (root->right_child == NULL) {
            struct Node* temp = root->left_child;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = minValueNode(root->right_child);
        root->key = temp->key;
        root->right_child = deleteNode(root->right_child, temp->key);
    }

    return root;
}

// Function to find the minimum value in BST
int findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left_child != NULL) {
        current = current->left_child;
    }
    return current->key;
}

// Function to find the maximum value in BST
int findMax(struct Node* root) {
    struct Node* current = root;
    while (current->right_child != NULL) {
        current = current->right_child;
    }
    return current->key;
}
//searching
// Function to search for a key in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left_child, key);
    } else {
        return search(root->right_child, key);
    }
}
// Function to perform inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left_child);
        printf("%d ", root->key);
        inorderTraversal(root->right_child);
    }
}
int main() {
    struct Node* root = NULL;
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Original BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Min: %d\n", findMin(root));
    printf("Max: %d\n", findMax(root));

    printf("Enter a value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("BST after deleting %d: ", key);
    inorderTraversal(root);
    printf("\n");

    printf("Min: %d\n", findMin(root));
    printf("Max: %d\n", findMax(root));

    return 0;
}


