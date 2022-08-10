#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    string file, n1, n2;
    cin >> file;
    
    in.open(file);
    while (in.eof()==0)
    {
        in >> n1;
        in >> n2;
        cout << "n1 = " << n1 << " " << "n2 = " << n2 << endl;
    }
    return 0;
}