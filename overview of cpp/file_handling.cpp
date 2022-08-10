/*
Given two file name with 'n' integers in each of them, 
write a C++ program to print 'Greater' if ith number in file1 is greater than ith number in file2 and print 'Not greater' otherwise.

Input Format

First line contains the name of file1

Next line contains the name of file2

Output Format

For each pair of numbers either print Greater or Not greater

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fout; // output file stream class
    string line;
    fout.open("file1.txt"); //opening the file1.txt
    int i, n;
    i = 1;
    cin >> n;
    getline(cin, line);
    while (i <= n)
    {
        getline(cin, line);   //x
        fout << line << endl; // writing line string x to the file file1.txt
        i++;
    }
    fout.close();
    fout.open("file2.txt");
    i = 1;
    while (i <= n)
    {
        getline(cin, line);
        fout << line << endl;
        i++;
    }
    fout.close();

    ifstream fin1, fin2; //input file stream

    fin1.open("file1.txt");
    fin2.open("file2.txt");

    string line2;

    while (true)
    {
        if (fin1.eof() || fin2.eof())
            break;
        getline(fin1, line);
        getline(fin2, line2);
        cout << line << " " << line2 << endl;

        if (stoi(line) > stoi(line2))
            cout << "Greater\n";
        else
            cout << "Not Greater\n";
    }

    fin1.close();
    fin2.close();

    return 0;
}