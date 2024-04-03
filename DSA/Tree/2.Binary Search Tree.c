#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *insertBST (struct node *root, int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> left = 0;
    newnode -> right = 0;
    newnode -> data = data;
    if (root == 0) {
        root = newnode;
    }
    else {
        if (newnode -> data < root -> data) {
            root -> left = insertBST (root -> left, data);
        }
        else {
            root -> right = insertBST (root -> right, data);
        }
    }
    return root;
}

// To print 
void inOrder (struct node *root) {
    if(root == 0){
        return;
    }
    inOrder (root -> left);
    printf("%d\t", root -> data);
    inOrder (root -> right);
}

// Search function
void search(struct node *root, int key){
    if(root == 0){
        printf("Not Found\n");
        return;
    }
    if(key == root -> data){
        printf("Found\n");
        return;
    }
    if(key < root -> data){
        search(root -> left, key);
    }
    else{
        search(root -> right, key);
    }
}

// To calculate minm element / inorder successor
struct node *min(struct node *root){
    struct node *curr = root;
    while(curr -> left != 0){
        curr = curr -> left;
    }
    return curr;
}

// Deletion function
struct node *deleteBST(struct node *root, int key){
    if (root == 0) {
        return root;
    }

    if(key < root -> data){
        root -> left = deleteBST(root -> left, key);
    }
    else if(key > root -> data){
        root -> right = deleteBST(root -> right, key);
    }
    else{
        if(root -> left == 0){
            struct node *temp = root -> right;
            free(root);
            return temp;    
        }
        else if(root -> right == 0){
            struct node *temp = root -> left;
            free(root);
            return temp;
        }
        else{
            struct node *temp = min(root -> right);
            root -> data = temp -> data;
            root -> right = deleteBST(root -> right, temp -> data);
        }
    }
    return root;
}

int main(){
    int x;
    struct node *root = 0;
    do{
        printf("Enter data (-1 to exit) : ");
        scanf("%d", &x);
        if(x == -1){
            break;
        }
        root = insertBST(root , x);
    }
    while( x!= -1);
    search(root, 5);
    inOrder(root);
    root = deleteBST(root, 3);
    printf("\n");
    inOrder(root);
}