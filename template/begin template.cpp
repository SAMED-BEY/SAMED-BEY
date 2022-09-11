/*
TR :her kullanilan template fonksiyonu için başına template <...> yazılmalı
    template amaci veri tipini girilen değer ne ise onun veri tipini alır
ENG :For each template function used, template <...> should be written before it.
    template purpose ;gets the data type the entered value is

*/

#include <iostream>
using namespace std;

template <typename T>
T add(T x)              //any type of operation
{
    return x+1;
}


//Cannot be used to replace integer with double
template <typename T>
void change(T&x, T&y) //replacing data with addresses
{
    T temp =x;
    x=y;
    y = temp;
}


template<class T>
class samedSinifi
{
    public:
        T data;
        samedSinifi(T data): data(data){}

};




int main()
{
    int i =1;
    double d =1.2;

    cout<<"add func\n";
    cout<<"interger for :\t "<<add(i)
        <<"\ndouble for   :\t "<<add(d)<<endl;

    int a = 5;

    cout<<"\n\nchange func\n";
    cout <<a << "\t"<< i<< "\tchange befor"<<endl;
    change(a,i);
    cout <<a << "\t"<< i<< "\tchange after"<<endl<<endl;

    
    cout<<"change func\n";
    char k = 'k',m ='m';
    cout <<k << "\t"<< m<< "\tchange befor"<<endl;
    change(k,m);
    cout <<k << "\t"<< m<< "\tchange after"<<endl;

    //class example

    samedSinifi<int> b (10);                // you must say <int> or whatever
    samedSinifi<char> c('C');
    samedSinifi<double> f(d) ;
    cout<<"\n\n\nsamed sinifi example\n\n";
    cout<<b.data<<endl<<c.data<<endl<<f.data<<endl;


    return 0;
}
