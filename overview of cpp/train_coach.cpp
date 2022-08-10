#include <iostream>
using namespace std;
class coach 
{
    int capacity;
    int cno;
    int alloted;
    public:
    static int count;
    coach()
    {
        cno=count;
        cin>>capacity;
        alloted=0;
        count++;
    }
//void setCapacity(int x){capacity=x;alloted=0;}
    void AllotSeats(int x)
    {
    alloted=alloted+x;
    }
    int returnAvailableseats()
    {
        return capacity-alloted;
    }
    void put()
    {
        cout<<cno<<" "<<returnAvailableseats()<<endl;
    }
};
int coach::count=1;

int main()
{

char choice; //A- coach creataiton, B- AllotSeats C- display E - exit
int i,n=0;
cin>>n;
coach c[n];

while(1)
{
    cin>>choice;
    if(choice=='B')
    {
    int y; // no of seats to be allotted
    cin>>y;
    for(i=0;i<n && y>0;i++)
    {
        int a=c[i].returnAvailableseats(); //available seats in coach i
        //cout<<"available seats in coach "<<i+1<<" "<<a<<endl;
        if(a>0 &&y>0)
        {
            if(y>a)
            {
                c[i].AllotSeats(a);
                y=y-a;
                // c[i].put();
            }
            else 
            {
                c[i].AllotSeats(y);
                y=0;
                //c[i].put();       
                break;
            }
        }
    }
}
else if (choice =='C')
{
    for(i=0;i<n;i++)
    {
        c[i].put();
    }
}
else if (choice=='E' ) break;
}
}