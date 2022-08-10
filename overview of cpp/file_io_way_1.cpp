#include <iostream>
#include <fstream>
using namespace std;

/*
class for working with files in c++
1. fstreambase 
2. ifstream ---> derived from fstreambase
2. ofstream ---> derived from fstreambase
*/

/*
to read and read files, 2 ways
1. using canstructor
2.using member function open() of the files 
*/
int main()
{
    ofstream out ("file2.txt"); // creating a type of tunel which flows data from the program to file2.
    string name ;
    cout << "Enter name : ";

    // cin >> name; // it will take only one word as input

    getline (cin , name); // it will take a complete string as input

    out << name + " is good person"; // it will add/display the things in mentioned file
    
    out.close(); // closing the tunel

    ifstream in("file2.txt"); // creating a type of tunel which flows data from the file2 to program.
    string content;
    // in >> content;
    
    getline (in, content); // it will take the complete line form file to content through the in
    cout << "The content is " << content;
    in.close();
    
    return 0;
}