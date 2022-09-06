#include <iostream>
int  kare(int &c)
{ 
  return c*c;
}

using namespace ::std;

int main() 
{
    int l=5;
  
    cout<<l<<endl<<kare(l);
    return 0;

}
