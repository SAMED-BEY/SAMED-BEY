#include<iostream>
using namespace :: std;

bool c(int d[]);


int main()

{
	int b[5]={0};
	int *ptr;

	ptr=b;

    cout<<ptr<<endl<<*ptr<<endl<<endl<<endl;

    c(b);

}


bool c(int d[])
 {
   if( d[1]==5 )

	 return true;
 	else
  return false;
 }
