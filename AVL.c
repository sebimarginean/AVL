#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode
{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode *createNode(int key)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

AVLNode *rotateRight(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *xRightChild = x->right;

    x->right = y;
    y->left = xRightChild;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode *rotateLeft(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *yLeftChild = y->left;

    y->left = x;
    x->right = yLeftChild;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode *insert(AVLNode *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && key < root->left->key)
        return rotateRight(root);

    if (balanceFactor < -1 && key > root->right->key)
        return rotateLeft(root);

    if (balanceFactor > 1 && key > root->left->key)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balanceFactor < -1 && key < root->right->key)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorderTraversal(AVLNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main()
{
    AVLNode *root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2); // Add more nodes if necessary

    printf("Inorder traversal of the constructed AVL tree is \n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
