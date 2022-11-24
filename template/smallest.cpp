/*
SAMED CALIK 
*/

#include <iostream>
using namespace std;

template <typename T>
T smallest(T arr[],int x)              	// any type of operation
{										
	int min_index=0;					// min index
    for(int i=0; i<x ; i++)				// diziyi tariyor
	{
		if (arr[i] < arr[min_index])	//  min degerde kabul ettigimiz indexteki deger arr[i] den kucuk degerde ise
			min_index = i;				// i indexini min indexe ata 
	}
	return min_index;

}


int main()
{
	int inta[7]={1,-7,0,3,-11,4,9};

	unsigned int smallest_i = smallest(inta,7);
	cout << "Smallest element is :\t\t" << inta[smallest_i] << endl;

	char a[] ={'c','a','b','t'};

	smallest_i = smallest(a,4);
	cout << "Smallest char element is :\t" << a[smallest_i] << endl;

	double d[5]={1.5, 3.75, -5.99, 8.0, 0.0};
	smallest_i = smallest(d,5);
	cout << "Smallest double element is :\t" << d[smallest_i] << endl;


	return 0;
}
