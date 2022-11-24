/*
SAMED CALIK 4.SORU YANITI

Linux uzerinde derlenmistir.
asagida oldugu gibi derlyebiirsiniz

openMP( paralel programlama ) ve boost kullanilarak yapilmistir.

g++ -o linecounter -fopenmp 4.cpp -lboost_filesystem 

        ./linecounter <txt_path>
ornek : ./linecounter /home/samed/Masaüstü/txt_dosya
*/

#include<iostream>
#include<omp.h>
#include<boost/filesystem.hpp>
#include<vector>

using namespace std;
using namespace boost::filesystem;


int sayac=0;                       // satirlari saymak icin kullanilan sayac degiskeni
vector<string>files;               // .txt dosyalarinin patchleri ile birlikte tutulan yer


void file_check(string file_path)                     
{
    if(!is_directory(file_path))                     // klosor yolu dogrumu ? degilse cikis yapiliyor
    {
        cout<<"Girilen dosya yolu : "<<file_path<<endl;
        cout<<"Verilen path bulunamadi \n"<<"Dosya yolunun dogru oldugundan emin olun"<<endl;
        exit(0);
    }

    directory_iterator b(file_path), e;             // b : file bilgilerini barindirir nesne olarak tutar || e : son nesne verir  
    
    for (auto i=b; i!=e; ++i)                       // ilk dosyadan son dosyaya kadar dongu surer
    {
        path fe = i->path();                        // klosordeki dosyalarin yolu ile beraber ismini buluyor
                                                    //path().filename() > klosor icindeki dosya ismini verir

        files.push_back(fe.string());               // bulunan dosyalar files vektorun icine dosya yollari aktariliyor
    } 
}


int main(int argc, char* argv[])
{
    
    string path;

    if(argc>1)                          // giriste parametre var ise 
        path=argv[1];                   // girilen dosya konumunu path degiskenine atayacak
    else
        {
            cout<< "Giris Hatasi\n";    // egerki bir parametre girilmemis ise gosterilecek hata meseaji
            return 0;
        }

    string satir = "";                  // getline fonksiyonu icin kullanilan satirin datasini tutar

    file_check(path);                   // kullanicidan gelen path degeri icindeki dosyalarin yolunu bulmak icin file_check() yazildi 

    int thread_adet = omp_get_max_threads ();           // sistemdeki toplam cekirdek sayisini buluyor

    omp_set_num_threads(thread_adet);                   // buldugumuz cekirdek adeti kadar thread calistirmasini istiyoruz                                                                                                                 
    #pragma omp parallel for schedule(static,1)                     // openMP parallel programlama baslangici  || schedule(static,1)  > her cekirdege birer programi paralel baslatir
    for(int i=0;i<files.size();i++)                                 // files icindeki her txt dosyasi icin program donguye girer                                        
    {
        boost::filesystem::ifstream dosya_islem(files[i]);          // boost kutuphanesinden yararlanarak files vektroru icindeki patch deki txt dosyasini acar
        
        while ( getline(dosya_islem, satir) )                       // tutulan txt dosyasi var olan her satiri icin dongude kalir
        {
            #pragma omp critical                    //Birden cok is parcaciginin critical bolumdeki koda ayni anda erismesini onlemek icin kullanilir
            {
                sayac++;                // her var olan satirda +1 artiyor
            }
        }
    }                                   // paralel programlama biter

    cout<<sayac<<endl;                  // klasor icindeki tum txt dosyalarinin satir sayisini yazdirir.
    return 0;
}
