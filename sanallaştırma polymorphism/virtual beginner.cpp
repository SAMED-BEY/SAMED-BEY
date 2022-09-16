#include <iostream>

using namespace std;

class Dog
{
    public:
       virtual void voices(){           // virtual o func ezmesini izin veriyoruz
            cout<<"Hav Hav "<<endl;
        }
        void deneme()
        {
            cout<<"deneme \n";
        }
};

class Cat:public Dog{       // kimin torunu ise onun önune dedesi yazilcak public þeklinde
    public:
        void voices(){

            cout<<"Miyav"<<endl;
        }
};

int main()
{
    Dog d;
    Cat c;
    d.voices();
    c.voices();

    Dog* dizi[2];
    dizi[0] = &d;
    dizi[1] = &c;

    dizi[0]->voices();
    dizi[1]->voices();

    c.deneme();                 //kendi class inda olmadigi halde miras yoluyla aktarýyor
    return 0;
}
