#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Creation

struct node *create () {
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf ("Enter the data (-1 for no node) : ");
    scanf ("%d", &x);
    if (x == -1){
        return 0;
    }
    newnode -> data = x;
    printf ("Enter the left node of %d\n", newnode -> data);
    newnode -> left = create();
    printf ("Enter the right node of %d\n", newnode -> data);
    newnode -> right = create();

    return newnode;
}

// Traversal

void preorder (struct node *root) {
    if (root == 0) {
        return;
    }
    printf ("%d\t", root -> data);
    preorder(root -> left);
    preorder(root -> right);

}

void inorder (struct node *root) {
    if (root == 0) {
        return;
    }
    inorder(root -> left);
    printf ("%d\t", root -> data);
    inorder(root -> right);

}


void postorder (struct node *root) {
    if (root == 0) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf ("%d\t", root -> data);
}

int main () {
    struct node *root;
    root = 0;
    root = create();
    printf("The preorder traversal is : ");
    preorder(root);
    printf("\n");
    printf("The inorder traversal is : ");
    inorder(root);
    printf("\n");
    printf("The postorder traversal is : ");
    postorder(root);
    printf("\n");
}