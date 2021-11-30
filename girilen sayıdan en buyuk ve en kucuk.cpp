// girilen sayıdan en büyük ve en küçük sayıları çıktı olarak çıkartıyor.
// Samed ÇALIK

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void duzy(vector <int>& r)
{//sort(s.begin(),s.end());            // kucukten buyuge siralayip yazdiriyoruz
	for (int i=0;i<r.size();i++)
     cout<<r[i];
}



void tery(vector <int>&r)         //  siralnamis olan vektoru ters yazarak buyuk > kucuk yaziyo
{
    for (int i=r.size()-1; i>=0;i--)
     cout<<r[i];
}

int main(){
int e;

// sayiyi input olark aliyoruz
cin>>e;

vector <int > t;
int y;
int temp;
while(1)                             // sozsuz dongu icinde islemi yaptık break lede ciktik
{
    if((e/10)!=0)
    {
        temp=e/10;   //bunu yaparak son rakamdan kurtuluyoruz

        y=e%10;     // son rakamý asagýdaki satýrda goruldugu gibi vektore atýyoruz

        t.push_back(y);
        e=temp;

    }
    else
    {
        t.push_back(e);  // tek rakam kalıcagından en son rakamı burda vektore atadık
        break;
    }

}
sort(t.begin(),t.end());

cout<<"Bu rakamlardan olusabilecek en buyuk sayi: ";
tery(t);
cout<<endl;
cout<<"Bu rakamlardan olusabilecek en kucuk sayi: ";
duzy(t);
cout<<endl;

}
