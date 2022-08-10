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

void preOrder(tree* root) 
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(tree* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(tree* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    tree *root, *l, *r, *ll, *lr;
    root=createNode(4);
    l=createNode(1);
    r=createNode(6);
    ll=createNode(5);
    lr=createNode(2);

    // creating a tree
    //     4
    //    / \
    //   1   6
    //  / \
    // 5   2

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;
    
    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << endl;
    
    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;
    return 0;
}