#include <iostream>
using namespace std;

class plant
{
    int id, height;
    public:
    plant()
    {
        cin >> id >> height;
    }
    friend void sort (int, plant p[]);
};

void sort(int m, plant p[])
{
    int temp;
    for (int i=0; i<m; i++)
    {
        for (int j=i+1; j<m; j++)
        {
            if (p[j].height < p[i].height)
            {
                // temp = p[i].height;
                // p[i].height = p[j].height;
                // p[j].height = temp;
                temp = p[i].id;
                p[i].id = p[j].id;
                p[j].id = temp;
            }
        }
    }
    for (int i=0 ; i<m; i++)
    {
        cout << p[i].id << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    plant p[n];
    sort (n, p);
    return 0;
}