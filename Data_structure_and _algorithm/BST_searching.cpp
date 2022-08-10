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

tree *search(int x, tree *root) // search RECURSION.........
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
        return root;
    if (x > root->data)
        return search(x, root->right);
    else
        return search(x, root->left);
}

tree * inOrderPre (tree* root)
{
    root = root->left;
    while (root != NULL)
        root = root->right;
    return root;
}

void search_deletition(int x, tree *root) // search RECURSION.........
{
    while (x != root->data) // it will  give the elemnet to be deleted
    {
        if (x < root->data)
            root = root->left;
        if (x > root->data)
            root = root->right;
    }

    cout << root->data;
    if (root == NULL)
        return ;
    else if (root->left == NULL && root->right == NULL) { // it means it is  the root element found is leaf root
        free (root);
        return;
    }
    else 
    {
        tree* pre;
        pre = inOrderPre (root);
        root->data  = pre->data;
        
    }
    
}

int search_iterative(int x, tree *root) // search ITERATIVE.....
{
    if (root == NULL)
        return 0;
    else
    {
        while (root != NULL)
        {
            if (root->data == x)
                return x;
            if (x > root->data)
                root = root->right;
            if (x < root->data)
                root = root->left;
        }
        return 0;
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

    int n;
    cout << "Enter the no. to be searched: ";
    cin >> n; // 8

    // tree *random = search(n, root);
    // if (random != NULL)
    //     cout << "Data Found";
    // else if (random == NULL)
    //     cout << "No Data Found";

    // cout << endl;
    // int d = search_iterative(n, root);
    // cout << d << endl;

    cout << "Before deletion: ";
    inOrder (root);
    cout << endl;

    // tree *s = search(n, root);
    // if (s == NULL)
    // {
    //     cout << "data NOT Found" << endl;
    // }
    // else 
    // {
    //     cout << "data was found" << endl;
    //     s == NULL;
    // }
    search_deletition (n , root);

    cout << "After deletion: ";
    inOrder (root);

    return 0;
}