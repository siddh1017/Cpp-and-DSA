#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
     
    struct node* root = createNode(9);
    struct node* l = createNode(7);
    struct node* r = createNode(13);
    struct node* ll = createNode(2);
    struct node* lr = createNode(8);
    struct node* llr = createNode(5);
    struct node* lll = createNode(1);
    struct node* rl = createNode(10);
    struct node* rlr = createNode(11);

    // creating a BST
    //      9
    //    /  \
    //   7    13
    //  / \   /
    // 2   8  10
    /// \      \
   //1   5      11
    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;
    ll->right = llr;
    ll->left = lll;
    r->left = rl;
    rl->right = rlr;

    // preOrder(p);
    // printf("\n");
    // postOrder(p); 
    // printf("\n");
    inOrder(root);
    printf("\n");
    // printf("%d", isBST(p)); 
    if(isBST(root)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }
    return 0;
}
