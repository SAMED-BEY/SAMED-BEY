
#include <stdio.h>
int main()
{
   FILE *fptr;
   FILE *fptr1;
   fptr = fopen("dosya.txt", "w");      /** cekilen verilerin aktarildigi dosya*/
   fptr1= fopen("d1.txt", "r");         /** veri cekilecek dosya */
   printf("dosyalar acildi\n");
   if(fptr1 == NULL)                    /** okunacak dosya bos ise program calismasin */
   {   printf("Hata!");
        return 0;
    }
char c;

 printf("char c olusturuldu\n");
int x=20;

while(1)
     {
        c = fgetc(fptr1);
        if(c==EOF)              /** dosya sonunda ise donguden ciksin */
            break;

        else if(c == '\n')
            fprintf(fptr,", "); /** her alt satirda , karakteri konuluyo ve tarafýndan devam ediyor*/
        else
         fprintf(fptr,"%c",c);

      //  printf("%c\n",c);    // dosyalardan cekilen verileri gozlemlemek istenirse
            x--;
        if(x==0) /** belli bir dizinden sonra asagý satýra geçmesi icin kullanildi **/
            {
                x=20;
                fprintf(fptr,"\n");
            }

     }

      fclose(fptr);
      printf("fptr kapandi");

     fptr= fopen ("dosya.txt", "r");        /** islenen dosyanin cmd ekranina gosterimi icin yazýlmýstir */
     printf("fptr acildi");

     while(1)
     {
        c = fgetc(fptr);
        if(c==EOF)
            break;
        else
            printf("%c", c);
     }


   fclose(fptr);
         printf("fptr kapandi");

   fclose(fptr1);
         printf("fptr1 kapandi");


return 0 ;
}
