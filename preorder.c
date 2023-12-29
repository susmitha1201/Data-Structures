#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* create()
{
    int input, data;
    printf("Do you want to add a node? (0 for NO and 1 for YES): ");
    scanf("%d", &input);

    if (!input)
        return NULL;
    else
    {
        struct node* new_node = malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
        new_node->data = data;

        printf("Left child of %d:\n", new_node->data);
        new_node->left = create();

        printf("Right child of %d:\n", new_node->data);
        new_node->right = create();

        return new_node;
    }
}

// Function to display the binary tree using inorder traversal
void displayInorder(struct node* root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

// Function to display the binary tree using preorder traversal
void displayPreorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

// Function to display the binary tree using postorder traversal
void displayPostorder(struct node* root)
{
    if (root != NULL)
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node* root = create();

    printf("\nInorder Traversal: ");
    displayInorder(root);

    printf("\nPreorder Traversal: ");
    displayPreorder(root);

    printf("\nPostorder Traversal: ");
    displayPostorder(root);

    return 0;
}



