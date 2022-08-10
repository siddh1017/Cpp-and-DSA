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


void MIN_ele(tree* root) 
{
    tree* prev;
    while (root != NULL)
    {
        prev = root;
        root = root->left;
    }
    cout << "min ele.: "<< prev->data << endl;
}

void MAX_ele(tree* root)
{
    tree* prev;
    while (root != NULL)
    {
        prev = root;
        root = root->right;
    }
    cout << "max ele.: " << prev->data << endl;
}


tree * min_ele(tree* root)    //--------> using recursion
{
    if (root == NULL)
    {
        cout << "EMPTY"<< endl;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    return min_ele(root->left);
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

    tree *min = min_ele (root);
    cout << min->data << endl;

    MIN_ele (root);
    MAX_ele (root);
    return 0;
}