//SAMED ÇALIK  tarafindan yapilmistir

#include<iostream>     
#include <vector>
#include <algorithm>

using namespace  ::std ;

void printVector(vector <int>& s)
{ 
	for (int i=0; i<s.size();i++)
     cout<<s.at(i)<<"  ";
}

void sirala_k(vector <int>& d)   // kucukten buguye siralama fonk
{
	int min=0;
	
	for(int k=0;k<d.size();k++)
	for(int i=0;i<d.size();i++)
    {
    	if(d[i+1]<d[i])
    	{
    		min=d[i+1];
    		d[i+1]=d[i];
    		d[i]=min;
		}
    	
	}

  printVector(d);
}


void sirala_b(vector <int>& d)  //buyukten kucuge siralma fonk
{
		int max=0;
	
	for(int k=0;k<d.size();k++)
	for(int i=0;i<d.size();i++)
    {
    	if(d[i]<d[i+1])
    	{
    		max=d[i+1];
    	
			d[i+1]=d[i];
    	
			d[i]=max;
		}
    	
	}

   printVector(d);
}


int arama(vector <int>& d)
{
	int c;
	cout<<"\n\nbulunmasi istenen sayiyi gir\n";
	cin>> c;
	
	for(int i=0;i<d.size();i++)
    {
    	if(d[i]==c)
    	{
		  cout<<c<<"  sayisi vektorde bulunmaktadir\n";
		  return 1 ;
		  
		}
}




cout<<c<<"  sayisi vektorde bulunamadi\n\n";
return 0;
}

int main()
{

		vector <int > vektor(50);
	for(int i=0;i<50;i++)
	{
		vektor[i]=rand()/100;
	}
	
	
cout<<"50 elemanli vektorumuz\n\n"	;
     printVector(vektor);
	
	cout<<"\n\nkucukten buguye siralanmis hali:\n\n";
	 sirala_k(vektor);
	
	cout<<"\n\nbuyukten kucuge  siralanmis hali:\n\n";
	cout<<"yeni ekledik bunlar 500, 700 ,555, 422, 333\n\n";
	
	vektor.push_back(500);       // en sonlarýna sayi ekledik
	vektor.push_back(700);
	vektor.push_back(555);
	vektor.push_back(422);
	vektor.push_back(333);
	
	sirala_b(vektor);
	arama (vektor);
	//ut<<endl<<endl<<endl;
	
	
	return 0;
}
