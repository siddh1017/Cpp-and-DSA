#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out;
    out.open("file.txt"); // will open the file 
    
    // out will add/display the strings in file mentioned
    out << "siddh is good person" << endl;
    out << "siddh is person" << endl;
    out << "siddh is good human" << endl;
    out.close(); // closing file (closing path between th eout and file)

    ifstream in;
    string content;
    in.open("file.txt"); // will open the file (will open the path between the file and in)
    
    while (in.eof()==0) // eof ---> end of file
    // loop wil be executed till it reaches end of file (eof)
    {
        getline(in, content); // will transfer the things in content from file through in
        
        cout << content << endl; // print content
    }
    in.close(); // will close the file (will close path between the file and in)
    return 0;
}