#include <iostream>
using namespace std;

class tree
{
public:
    int data;
    tree *left;
    tree *right;
};

tree *createNode(int data) // creating the nodes
{
    tree *node;
    node = (tree *)malloc(sizeof(tree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertion(int data, tree *root)
{
    tree *temp = root;
    tree *prev = NULL;
    tree *ptr = createNode(data);

    cout << ptr->data << endl;
    while (temp != NULL)
    {
        prev = temp;
        if (temp->data == data)
            return;
        if (data > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    if (data > prev->data)
        prev->right = ptr;
    else
        prev->left = ptr;
}

void inOrder(tree *root)
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

    // BST to be created
    //      9
    //    /  \
    //   7    13
    //  / \   / \ 
    // 2   8 10  15   //15 to be inserted
    /// \      \
   //1   5      11
    cout << "Before insersion: ";
    inOrder(root);
    cout << endl;

    insertion(6, root);

    cout << "After insersion: ";
    inOrder(root);
    return 0;
}