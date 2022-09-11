#include <iostream>

using namespace std;

template <typename T>
T add(T x)              //any type of operation
{
    return x+1;
}

int main()
{
    int i =1;
    double d =1.2;

    cout<<"interger for :\t "<<add(i)
        <<"\ndouble for   :\t "<<add(d)<<endl;
}
