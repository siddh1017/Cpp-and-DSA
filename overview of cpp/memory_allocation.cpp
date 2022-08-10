#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of arrry needed: ";
    cin >> n;
    int *ptr;

    // using MALLOC ------------------------------->
    // It atots the storage of required space from heap dynamically
    ptr = (int *)malloc(n * sizeof(int));
    // alloting the 10 int size to ptr
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ptr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;

    //use of CALLOC ------------------------------->
    int nc;
    cout << "Enter the size of arrry needed: ";
    cin >> nc;

    int *ptr_c;
    ptr_c = (int *)calloc(nc, sizeof(int));

    // It has same use as the malloc
    // only differnce is it has initialized value as 0 instead garbage
    // example
    for (int i = 0; i < nc; i++)
    {
        cout << ptr_c[i] << " ";
    }
    cout << endl;

    // taking input
    cout << "Enter the elements" << endl;
    for (int i = 0; i < nc; i++)
    {
        cin >> ptr_c[i];
    }
    for (int i = 0; i < nc; i++)
    {
        cout << ptr_c[i] << " ";
    }
    cout << endl;

    // use of REALLOC ------------------------>
    // used to resize the existing pointer from malloc/calloc

    int new_size;
    cout << "Enter the new size for ptr: ";
    cin >> new_size;

    ptr = (int *)realloc(ptr, new_size * sizeof(int));
    // if size is greater then we can just input in newly inserted storage
    // or we can over write the complete storage

    // for (int i=n ; i<new_size; i++) // taking input for new storage if it is greater then previous
    // {
    //     cin >> ptr[i];
    // }
    for (int i = 0; i < new_size; i++)
    {
        cin >> ptr[i];
    }
    for (int i = 0; i < new_size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;

    // use of FREE -------------------------->
    // It simply free all the memory from pointer

    free(ptr);
    // the bellow code will give now garbage value
    // for (int i=0 ; i<new_size; i++)
    // {
    //     cout << ptr[i] << " ";
    // }
    // cout << endl;

    free(ptr_c);
    return 0;
}