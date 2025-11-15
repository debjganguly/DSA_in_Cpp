#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100];
    int size;
} Tree;

int leftNode(int index) {
    return (2*index)+1;
}
int rightNode(int index) {
    return (2*index) + 2;
}
int parentNode(int index) {
    return (index-1)/2;
}

void insert(Tree* tree, int val) {
    if(tree->size!=100) {
        tree->arr[tree->size++]=val;
    } else {
        printf("Tree is Full..burp\n");
    }
}

void delete(Tree* tree) {
    if(tree->size==0) {
        printf("Tree is Empty.. Must be Autumn!\n");
    }
    tree->size--;
}

void inorder(Tree* tree, int index) {
    if(index>=tree->size) return;
    inorder(tree,leftNode(index));
    printf("%d ",tree->arr[index]);
    inorder(tree,rightNode(index));
}

void postorder(Tree* tree, int index) {
    if(index>=tree->size) return;
    postorder(tree,leftNode(index));
    postorder(tree,rightNode(index));
    printf("%d ",tree->arr[index]);
}

void preorder(Tree* tree, int index) {
    if(index>=tree->size) return;
    printf("%d ",tree->arr[index]);
    preorder(tree,leftNode(index));
    preorder(tree,rightNode(index));
}

void levelorder(Tree* tree) {
    if(tree->size==0) {
        printf("Tree is Empty.. Must be the Wind\n");
        return;
    }
    for(int i=0;i<=tree->size;i++) printf("%d ",tree->arr[i]);
    printf("\n");
}
int main() {

    //Initialising Tree
    Tree* tree = (Tree*)(malloc)(sizeof(Tree));
    tree->size=0;

    int choice=0, val;

    printf("\n--- Binary Tree (Array Representation) ---\n");
    printf("1. Insert\n");
    printf("2. Delete Last Node\n");
    printf("3. Display Tree (Array Form)\n");
    printf("4. Inorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Level Order Traversal\n");
    printf("8. Exit\n");

    while(choice!=8) {
        printf("--------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter a Value: ");
                    scanf("%d",&val);
                    insert(tree,val);
                    break;
            
            case 2: delete(tree);
                    break;

            case 3: levelorder(tree);
                    break;

            case 4: inorder(tree,0); printf("\n"); break;

            case 5: preorder(tree,0); printf("\n"); break;

            case 6: postorder(tree,0); printf("\n"); break;

            case 7: levelorder(tree); break;

            case 8: ("Exiting, Chill.......\n");

            default: printf("Out of the Books... \n");
        }
    }

}
