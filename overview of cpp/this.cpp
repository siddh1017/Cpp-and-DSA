using namespace std;
#include <stdio.h>
#include <iostream>
 

class complex
{
   public :
      int a,ai;
      int b,bi;
      
      void inpr(){cin>>a;cin>>b;}
      void inpi(){cin>>ai;cin>>bi;}
      void outr()
      {
         this->a+=b;
      }
      void outi(){this->ai+=bi;}
      void out(){printf("the complex number is %d + %di",a,ai);}
};

 

int main()
{
   complex c;
   c.inpr();
   c.inpi();
   c.outr();
   c.outi();
   c.out();
   return 0;
}