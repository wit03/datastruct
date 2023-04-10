#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree
{
    int key;
    struct Tree *left, *right;
} Tree;

// Create a node
Tree *newNode(int item)
{
    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}

// Insert a node
Tree *insert(Tree *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);
    }
    return node;
}
// Find the inorder successor
Tree *minValueNode(Tree *node)
{
    Tree *current = node;
    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Tree *deleteNode(Tree *root, int key)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;
    // Find the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Tree *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            Tree *temp = root->left;
            free(root);
            return temp;
        }
        // If the node has two children
        Tree *temp = minValueNode(root->right);
        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
    Tree *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal: ");
    inorder(root);
    return 0;
}