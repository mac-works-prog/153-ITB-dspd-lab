//Pavan Bokare-IT-B-153
/* AIM: Implement Binary search tree(BST) with following Menu operations.
        1.	Search an element in BST(Display NULL if not found, If found Display Found)
        2.	Insert an element in BST
        3.	Delete leaf element in BST
        4.	Exit
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
void search(struct Node* root, int key) {
    while(root != NULL) {
        if(key == root->data) {
            printf("Found\n");
            return;
        }
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    printf("NULL\n");
}
struct Node* deleteLeaf(struct Node* root, int key) {
    if(root == NULL) {
        printf("NULL\n");
        return NULL;
    }
    if(root->data == key && root->left == NULL && root->right == NULL) {
        free(root);
        printf("Leaf Node Deleted\n");
        return NULL;
    }
    if(key < root->data)
        root->left = deleteLeaf(root->left, key);
    else
        root->right = deleteLeaf(root->right, key);

    return root;
}
int main() {
    struct Node* root = NULL;
    int choice, value;
    while(1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Search\n2. Insert\n3. Delete Leaf Node\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 3:
                printf("Enter leaf node value to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}