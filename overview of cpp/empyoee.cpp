#include <iostream>

using namespace std;

class employee
{
public:
  int e_id;
  static int c;
  string name;
  float salary;

  float returnSalary()
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
  }
  employee()
  {
    e_id = c++;
    cin >> name >> salary;
  }
};

int employee::c = 101;

int main()
{
  int n;
  cin >> n;
  employee e[n];
  int max = e[0].salary;
  int temp;
  for (int i = 1; i < n; i++)
  {
    if (e[i].salary > max)
    {
      max = e[i].salary;
      temp = i;
    }
  }
  cout << e[temp].e_id << " " << e[temp].name << " " << e[temp].salary;
  return 0;
}