#include <iostream>
using namespace std;

class tree
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

int isBST(tree* root)
{
    static tree* prev = NULL;
    if (root!= NULL)
    {
        if (!isBST(root->left)){  // reaching the last sub left BST
            return 0;
        }
        if (prev != NULL && root->data <= prev->data){  // 
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}

// void func(tree* root, tree* prev, int f)
// {
//     if (!root){
//         return;
//     }
//     func (root->left , prev, f); // calling recursively to reach leftmost sub-tree
//     if (prev != NULL and root->data <= prev->data)  // after reaching the last left subtree, checking main condition of BST  
//     {
//         f=0; return;  // if fails turning the f=0;
//     }
//     prev = root; // if above condion fails, then change orev to root
//     func (root->right, prev, f); // same thing for the right sub-trees too
// }

// int isBST(tree* root){
//     int f = 1;
//     tree* prev = NULL;
//     func (root, prev, f);
//     return f;
// }

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
    cout << isBST(root);
    return 0;
}