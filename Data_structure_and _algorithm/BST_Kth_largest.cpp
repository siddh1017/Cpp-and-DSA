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

int counter = 1;
void kth_smallest (tree* root, int k)
{
    if (root == NULL)
        return;
    kth_smallest (root->left, k);
    if (counter == k)
    {
        cout << root->data  << " ";
        counter ++;
        return;
    }
    else counter++;
    kth_smallest (root->right, k);
}

int count = 1;
void kth_largest (tree* root, int k)
{
    if (root == NULL)
        return;
    kth_largest (root->right, k);
    if (count == k)
    {
        cout << root->data << " ";
        count ++;
        return ;
    }
    else count ++;
    kth_largest (root->left, k);
}

int *arr; int i=0;
void small(tree* root, int k)
{
    if (root != NULL)
    {
        small (root->left, k);
        *(arr + i) = root->data;
        i++;
        small (root->right ,k);
    }
    cout << "ele : " << *(arr + k);
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

    kth_smallest(root, 2);
    kth_largest(root, 3);
    cout << endl;
    small (root, 2);
    return 0;
}