#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Sucess_CALL (printf("LOG -> Sucess Called by ,%s \n", __FUNCTION__))
#define ERR_CALL (printf("LOG -> Errors Called by ,%s \n", __FUNCTION__))

typedef struct Node {
    int valueue;
    struct Node* left;
    struct Node* right;
} Node;

Node* new_NODE(int valueue);

void insert(Node** root, int valueue)
{
    Node* n_NODE = new_NODE(valueue);
    if (*root == NULL) {
        Sucess_CALL;
        *root = n_NODE;
    } else if (valueue >= (*root)->valueue) {
        insert(&(*root)->right, valueue);
        free(n_NODE);
        Sucess_CALL;
    } else if (valueue <= (*root)->valueue) {

        insert(&(*root)->left, valueue);
        free(n_NODE);
        Sucess_CALL;
    }
}

void display_tree(Node* tree)
{
    if (tree == NULL) {
        return;
    }
    printf("[%d] ->", tree->valueue);
    display_tree(tree->left);
    display_tree(tree->right);
}

void free_tree(Node* root)
{
    if (root == NULL) {
        return;
    }
    free_tree(root->right);
    free_tree(root->left);
    printf("LOG -> Clear memory at : %p ", root);
    free(root);
    Sucess_CALL;
}

int main(int argc, char* argv[])
{
    Node* root = NULL;

    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 30);
    insert(&root, 50);

    display_tree(root);

    free_tree(root);
    return EXIT_SUCCESS;
}

Node* new_NODE(int valueue)
{
    Node* NODE = malloc(sizeof(Node));
    if (NODE == NULL) {
        ERR_CALL;
        return new_NODE(valueue);
    }
    NODE->valueue = valueue;
    NODE->left = NULL;
    NODE->right = NULL;
    Sucess_CALL;
    return NODE;
}
