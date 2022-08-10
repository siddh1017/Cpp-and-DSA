#include <iostream>
using namespace std;

class tree  // tree structure
{
public:
    int data;
    tree *left;
    tree *right;

};

tree* createNode(int data)  // creating the nodes
{
    tree *node;
    node = (tree *)malloc(sizeof(tree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int count = 0;
int * arr;
void median (tree* root)   // func() to find middle ele. in BST
{
    if (root != NULL)
    {
        median(root->left);
        *(arr + count) = root->data;
        count ++;
        median(root->right);
    }
    cout <<  *(arr + (count/2)) << endl;
}

tree* smallest (tree* root)     // func() to find smallest ele. in BST
{
    while (root->left != NULL){
        root = root->left;
    }
    cout << root->data << endl;
    return root;
}

tree* largest (tree* root)  // func() to find largest ele. in BST
{
    while (root->right != NULL){
        root = root->right;
    }
    cout << root->data << endl;
    return root;
}

int main()
{
    tree *root, *l, *r, *ll, *lr, *llr, *lll, *rlr, *rl;
    root = createNode(9);
    l = createNode(7);
    r = createNode(13);
    ll = createNode(2);
    lr = createNode(8);
    llr = createNode(5);
    lll = createNode(1);
    rl = createNode(10);
    rlr = createNode(11);

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
   
    tree* new_root;  // root of new tree
    new_root = createNode (*(arr + (count/2)));
    cout << new_root->data;
    
    new_root->left = smallest(root); // smallest element of old BST as its left
    new_root->right = largest (root);  // largest element of old BST as its right

    cout << new_root->data << " ";
    cout << new_root->left->data << " ";
    cout << new_root->right->data << " ";

    return 0;
}