#include <iostream>
#include <vector>
#include<stdlib.h> //rand için
#include<math.h>
using namespace std ;

double V[19][3];                 // bunlar sirasiyla xekseni y ekseni , elma türü

int n=19; // elma sayisi

double Left[19][3]={0}; //

double Right[19][3]={0};  // kademe 1 sag

double  LeftRight[19][3]={0}; // 1kademe sol 2 kademe sag

double  LeftL[19][3]={0}; // 1kademe sol 2 kademe sol


double RightS[19][3]={0};  // 1kademe sag 2 kademe sag



double RightLeft[19][3]={0}; // 1kademe sag 2 kademe sol




vector<double>f; // I ları topladığımız yer


void xeks(double x, double d[][3]);  //x ler icin gerekn hesaplama

void yeks(double y, double d[][3]);  // y ler icin hesaolama
void bilgi_kazanimi(double birUsteki[][3],int L , int R  );


double tempR[19][3] ={0};
double tempL[19][3] ={0};

//vector<int>R_L_sayisi(int ,int);

int main()
{



    cout<<"verileri girin : "<< endl;


 for(int i=0;i<n;i++)   //diziye degerleir atýyoruz
 {
     cin>>V[i][0];
     cin>>V[i][1];
     cin>>V[i][2];

 }

double X1;  //sorular icin x ve y kordinatlari
double X2;
double Y1;
double Y2;

X1 =(rand()%50)/10;   //rand ile sayi uretiyot
X2 =(rand()%50)/10;
Y2 =(rand()%50)/10;
Y1 =(rand()%50)/10;



xeks(X1,V);
xeks(X2,V);
yeks(Y1,V);
yeks(Y2,V);


double er[]={X1,X2,Y1,Y2};

int mi=0;
for(int i=0 ;i<4;i++)  // I degeri hangisi ugunsa onu bulup sag ve sol kola ataması için indexi arıyor
{
    if( f[mi]<f[i] )
     mi=i;

}
 if(mi<2)
    xeks(mi,V);
else
    yeks(mi,V);
for(int i =0 ;i<19 ; i++)
{
   Left[i][0]=tempL[i][0];
    Left[i][1]=tempL[i][1];
    Left[i][2]=tempL[i][2];
    Right[i][0]=tempR[i][0];
    Right[i][1]=tempR[i][1];
    Right[i][2]=tempR[i][2];
}
X1 =(rand()%50)/10;   //rand ile sayi uretiyot
X2 =(rand()%50)/10;
Y2 =(rand()%50)/10;
Y1 =(rand()%50)/10;
xeks(X1,Left);
xeks(X2,Left);
yeks(Y1,Left);
yeks(Y2,Left);


for(int i=0 ;i<4;i++)  // I degeri hangisi ugunsa onu bulup sag ve sol kola ataması için indexi arıyor
{
    if( f[mi]<f[i] )
     mi=i;

}
 if(mi<2)
    xeks(mi,Left);
else
    yeks(mi,Left);
for(int i =0 ;i<19 ; i++)     // temp teki gecici verileri kalıcıya atıyor
{
    LeftL[i][0]=tempL[i][0];
    LeftL[i][1]=tempL[i][1];
    LeftL[i][2]=tempL[i][2];

    LeftRight[i][0]=tempR[i][0];
    LeftRight[i][1]=tempR[i][1];
    LeftRight[i][2]=tempR[i][2];

}



X1 =(rand()%50)/10;   //rand ile sayi uretiyot
X2 =(rand()%50)/10;
Y2 =(rand()%50)/10;
Y1 =(rand()%50)/10;


xeks(X1,Right);
xeks(X2,Right);
yeks(Y1,Right);
yeks(Y2,Right);


for(int i=0 ;i<4;i++)  // I degeri hangisi ugunsa onu bulup sag ve sol kola ataması için indexi arıyor
{
    if( f[mi]<f[i] )
     mi=i;

}
 if(mi<2)
    xeks(mi,Right);
else
    yeks(mi,Right);

for(int i =0 ;i<19 ; i++)
{
    RightLeft[i][0]=tempL[i][0];
    RightLeft[i][1]=tempL[i][1];
    RightLeft[i][2]=tempL[i][2];

    RightS[i][0]=tempR[i][0];
    RightS[i][1]=tempR[i][1];
    RightS[i][2]=tempR[i][2];

}

    return 0;

}

void xeks(double x, double d[][3])
{ int atamaR=0;
  int atamaL=0;
for(int i=0;i<n;i++)
{
    if(d[i][2]!=0)
    {
        if(d[i][0]<x)
          {
              tempL[atamaL][0]=d[i][0];
              tempL[atamaL][1]=d[i][1];
              tempL[atamaL][2]=d[i][2];
              atamaL++;

          }
        else
           {tempR[atamaR][0]=d[i][0];
            tempR[atamaR][1]=d[i][1];
            tempR[atamaR][2]=d[i][2];
               atamaR++;
           }

    }

}
bilgi_kazanimi(d,atamaL,atamaR);
}

void yeks(double y, double d[][3])
{ int atamaR=0;
  int atamaL=0;
for(int i=0;i<n;i++)
{
    if(d[i][2]!=0)
    {
        if(d[i][1]<y)
          {
              tempL[atamaL][0]=d[i][0];
              tempL[atamaL][1]=d[i][1];
              tempL[atamaL][2]=d[i][2];
              atamaL++;

          }
        else
           {tempR[atamaR][0]=d[i][0];
            tempR[atamaR][1]=d[i][1];
            tempR[atamaR][2]=d[i][2];
               atamaR++;
           }

    }

}
bilgi_kazanimi(d,atamaL,atamaR);
}


void bilgi_kazanimi( double u[][3],int L , int R  ) //I fonks tanýmlýyoruz
{

    int p=0;
double y=0,s=0,k=0;
    for(int i=0 ; i<19 ; i++)      //elma adedine ulaşıyoruz
 {
     if(u[i][2]!=0)
        p++;

     if(u[i][2]==1)
        s++;
     else if(u[i][2]==2)
        k++;
     else if(u[i][2]==3)
        y++;

 }
double Py =y/p;   //  hesaplanan olasılıklar
double Ps =s/p;
double Pk =k/p;

double Hs= -( (Py*((log(Py)) / log(2))) +  (Ps*((log(Ps)) / log(2))) + (Pk*((log(Pk)) / log(2)))   ) ; // genel H(s) yi bulduk

   for(int i=0 ; i<19 ; i++)      //kaç adet elma var ona bakýyoruz
 {


     if(tempR[i][2]==1)
        s++;
     else if(tempR[i][2]==2)
        k++;
     else if(tempR[i][2]==3)
        y++;
     if(tempR[i][2]!=0)
        p++;
 }

double Hsr= -( (Py*((log(Py)) / log(2))) +  (Ps*((log(Ps)) / log(2))) + (Pk*((log(Pk)) / log(2)))   ) ;

for(int i=0 ; i<19 ; i++)      //kaç adet elma var ona bakýyoruz
 {


     if(tempL[i][2]==1)
        s++;
     else if(tempL[i][2]==2)
        k++;
     else if(tempL[i][2]==3)
        y++;
    if(tempL[i][2]!=0)
        p++;
 }

double Hsl= -( (Py*((log(Py)) / log(2))) +  (Ps*((log(Ps)) / log(2))) + (Pk*((log(Pk)) / log(2)))   ) ;



double IM= Hs-( (Hsr*(R/(L+R)) ) +  (Hsl*(L/(L+R)) )  );
f.push_back(IM);

}

