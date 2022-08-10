#include <iostream>
using namespace std;

class employee
{
  int e_id;
  static int c;
  string name;
  float salary;

  public:

  /*float returnSalary()
  {
    return salary;
  }
  string returnName()
  {
    return name;
  }
  float returnId()
  {
    return e_id;
  }*/
  employee()
  {
    e_id=c++;
    cin>>name>>salary;
  }

  friend void findmax(employee e[], int x);
};

int employee::c=101;

void findmax(employee e[], int n)
{
  int max=e[0].salary;
  int temp;
  for (int i=1; i<n; i++)
  {
    if (e[i].salary>max)
    {
      max=e[i].salary;
      temp=i;
    }
  }
  cout<<e[temp].e_id<<" "<<e[temp].name<<" "<<e[temp].salary;
}

int main()
{
  int n;
  cin>>n;
  employee e[n]; 
  /*for (int i=0; i<n; i++)
  {
    cout<<e[i].returnId()<<" ";
    cout<<e[i].returnName()<<" ";
    cout<<e[i].returnSalary()<<" ";
  }*/
  findmax(e,n);
  return 0;
}