#include <stdio.h>
#include <stdlib.h>
#pragma argsused
#include <iostream>
#include <conio.h>
void yaz(int, int);
void bilgi(int, int, int *, int *);
void ayarla(int, int);
void ayarla2(int ,int );

int a=0,ogren[100][100],ic[100];

int main()
{
  int i,j,k,l,m,n,p=0,q;

    printf("dedikodu yapan kisi sayisi=");
    scanf("%d",&i);

    for(m=0;m<100;m++)
    ogren[m][0]=m;

if(i<=3){
         printf("olmasi gereken arama sayisi=%d \n",i);
for(l=1;l<i;l++){
yaz(l,l+1);
ayarla(l,l+1);
ayarla(l+1,l);
bilgi(l,l+1,ogren[l],ogren[l+1]);
}
yaz(l,1);
ayarla2(1,l);
bilgi(l,1,ogren[l],ogren[1]);
}

else{
     printf("olmasi gereken arama sayisi=%d \n",2*i-4);
    for(l=1;l<i-3;l++)
    {
    yaz(l,l+1);
    ayarla(l,l+1);
    ayarla(l+1,l);
      bilgi(l,l+1,ogren[l],ogren[l+1]);
    }

    yaz(i-3,i);
    ayarla(i-3,i);
    ayarla(i,i-3);
     bilgi(i-3,i,ogren[i-3],ogren[i]);

    yaz(i-2,i-1);
    ayarla(i-2,i-1);
    ayarla(i-1,i-2);
     bilgi(i-2,i-1,ogren[i-2],ogren[i-1]);

    yaz(i-3,i-2);
    ayarla(i-3,i-2);
    ayarla(i-2,i-3);
     bilgi(i-3,i-2,ogren[i-3],ogren[i-2]);

    yaz(i,i-1);
    ayarla(i,i-1);
    ayarla(i-1,i);
     bilgi(i,i-1,ogren[i],ogren[i-1]);

    for(l=i-4;l>0;l--)
    {
    yaz(l+1,l);

    ayarla2(l,l+1);
     bilgi(l+1,l,ogren[l+1],ogren[l]);
    }
}



  return 0;
}

void yaz(int x, int y)
{
a++;
printf("\n %3d.arama -) %3d.kisi %3d. kisi'yi aradi \n",a,x,y);
}

void bilgi(int x, int y, int *di,int *diz)
{
int i=0,j;

printf("               %2d.kisi ---> ",x);
while(di[i]!=0)
printf("%2d ",di[i++]);

i=0;
printf("               %2d.kisi ---> ",y);

while(diz[i]!=0)
printf("%2d ",diz[i++]);
}

void ayarla(int a, int b)
{
int m,n,p;
    m=0;
    p=0;

       while(ogren[b][m]!=0)
       {
       if(a<b)
        ic[a]++;

          for(n=0;n<ic[a];n++)
          {
            if(ogren[a][n]==ogren[b][m]){
            p=1;
            break;
            }
          }
          if(p==0){
                   if(b<a)
                   ic[a]++;
          ogren[a][ic[a]]=ogren[b][m];
          }
       m++;
       }
}

void ayarla2(int a,int b)
{
int i=0,j;

while(ogren[b][i]!=0)
ogren[a][i]=ogren[b][i++];
}


int bastandedikodu(int ,int ,int *);
 void sondandedikodu(int ,int ,int *);
void yazdir(int *,int ,int );
 void whilea(int ,int ,int *);

int mainfonk(){
int kisi;

int *bilgi;


printf("Kisi sayisini gir:" );
scanf("%d",&kisi);
bilgi=new int[kisi];
for(int i=0;i<kisi;i++)
*(bilgi+i)=0;
bastandedikodu(kisi,kisi,bilgi);

sondandedikodu(kisi,kisi,bilgi);



          getch();
        return 0;
}
//---------------------------------------------------------------------------
int bastandedikodu(int kisi,int kisisay,int *bilgi){
    int a;
    a=kisi;
    bilgi[kisisay]=kisisay;
   if(kisisay!=1){
       if(kisisay==4){
               printf("\n %d -> aradı     ",kisisay,(kisisay-3));
               bilgi[kisisay-3]=kisisay-3;  yazdir(bilgi,kisisay-3,a);
               printf("\n %d -> aradı     ",kisisay-1,(kisisay-2));
               bilgi[kisisay-1]=kisisay-1;
               bilgi[kisisay-2]=kisisay-2;  yazdir(bilgi,kisisay-2,kisisay-1);
               printf("\n %d -> aradı     ",kisisay,(kisisay-1));
               bilgi[kisisay-1]=kisisay-1;  yazdir(bilgi,kisisay-3,a);
               printf("\n %d -> aradı     ",kisisay-3,(kisisay-2));
               bilgi[kisisay-2]=kisisay-2;  yazdir(bilgi,kisisay-3,a);

                kisisay=1;

                }

         else{
               printf("\n %d -> aradı     ",kisisay,(kisisay-1));
             bilgi[kisisay-1]=(kisisay-1);
           yazdir(bilgi,1,a);
           kisisay=kisisay-1;
            }
            }



   if(kisisay!=1)
    bastandedikodu(a,kisisay,bilgi);



}

    //------------------------------------------------------------------

void yazdir(int *p,int c,int b){
     while((b+1)!=c){
                     if(p[c]!=0)
                 printf("%d",p[c]);
                 c++;
                 }

     }
 //------------------------------------------------------------------------
void sondandedikodu(int kisi,int kisisay,int *bilgi){
     int a;
          a=kisi;
          if(kisisay<4){

                        whilea(1,a,bilgi);
                        }

                     else{

          whilea(4,a,bilgi);


                            }
                    }

  //-------------------------------------------------------------
  void whilea(int kisisay,int a,int *bilgi){
       while(a!=kisisay){
              				 printf("\n %d -> aradı     ",kisisay,(kisisay+1));
                            bilgi[kisisay+1]=kisisay+1; yazdir(bilgi,1,a);
                            kisisay++;
                            }
       }

