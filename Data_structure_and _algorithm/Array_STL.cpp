// #include <iostream>
// #include <cstring>
// #include <array>
#include <bits/stdc++.h>
using namespace std;

array <int ,3> global; // global initialiation -> Default value = 0 for all elements

int main()
{
    for (auto x:global)  
    // auto keyword adjust its data-type as per reqirement
    // it will fetch the value from global and assign to x one-by-one
        cout << x << " ";  
    cout << endl;

    array <int , 3> local; // local initialization -> All values are Grabage
    for (auto x:local)
        cout << x << " ";  // will give garbage values
    cout << endl;

    array <int , 3> array1 = {1,2}; // initialized as : {1,2,0}
    array <int , 3> array2 = {1,2,3}; // initialized as : {1,2,3}

    // copy in intialize itself
    array <int , 3> array3 = array2; // initializes as : {1,2,3}
                                    // provided the size of the arrays must be same

    for (auto x : array3)
        cout << x << " ";
    cout << endl;

    cout << array1.size() << endl;  // gives the size of the array
    cout << array1.max_size() << endl;
    cout << array1.empty() << endl;  // returns the 1 if array size is 0
    array <int , 0> local1;
    cout << local1.empty() << endl;  //example

    cout << array2.at(2) << endl; // gives value at index 2;
    cout << array2[2] << endl; // gives value at index 2;

    cout << array2.front() << endl;  // gives ele. at index 0
    cout << array2.back() << endl;   // gives ele. at index size

    int *data = array2.data();  // .data() is a pointer to the 1st element
    cout << *(data +2) << endl;   // or data[2]

    const char* str = "Data Structure";  // example for data() function
    array <char , 20> charary;
    memcpy (charary.data() , str ,20);
    cout << charary.data() << endl;

    // rbegin and rend  (r -> reverse)
    for (auto it = array2.rbegin(); it != array2.rend(); ++it)  // print array in reverses order
        cout << *it << ' ';
    cout << endl;

    auto it = array2.rbegin();
    *it = 4;

    // modified 
    for (auto it = array2.rbegin(); it != array2.rend(); ++it)  // print array in reverses order
        cout << *it << ' ';
    cout << endl;

    // cbegin and cend
    for (auto it1 = array2.cbegin(); it1 != array2.cend(); ++it1 )
        cout << *it1 << ' ';
    cout << endl;

    // auto it1 = array2.cbegin();
    // *it1 = 4;  // will give the error as the cbegin (c -> constant) is un-modifible 
    
    // crbegin and crend 
    for (auto it1 = array2.crbegin(); it1 != array2.crend(); ++it1 )
        cout << *it1 << ' ';
    cout << endl;

    // same here we cant change the value of the crbegin as uit remains constant

    // fill function 
    array <int , 5> array4; 
    array4.fill(0); // will fill the array with 5 ele. in all places
    for (auto x : array4)
        cout << x << ' ';
    cout << endl;


    // swap 
    array <int, 4 > array5 = {1,2,3,4};
    array <int, 4 > array6 = {5,6,7,8};

    array5.swap(array6);  // swap the elements

    for (auto x : array5)
        cout << x << ' ';
    for (auto x : array6)
        cout << x << ' ';
     
   return 0;
}