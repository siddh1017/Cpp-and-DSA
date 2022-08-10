#include <iostream>
using namespace std;

class student
{
    protected:
    int student_Id;
    public:
    void set_student_Id (int );
    void get_student_Id (void);
};

class exam : public student
{
    protected:
    float maths;
    float physics;
    public:
    void get_marks (float, float);
};

class result : public exam 
{
    float percentage;
    public:
    void process (void);
    void display_result(void);
};

// student class functions
void student :: set_student_Id (int id)
{
    student_Id = id;
}
void student :: get_student_Id (void)
{
    cout << student_Id << endl;
}

// exam class functions
void exam :: get_marks (float m , float p)
{
    maths = m;
    physics = p;
}

// result class functions
void result :: display_result(void)
{
    percentage = (maths+physics)/2;
    cout << percentage;
    
}

int main()
{
    result siddh;
    siddh.set_student_Id(94);
    siddh.get_marks(82,87);
    siddh.display_result();
    return 0;
}