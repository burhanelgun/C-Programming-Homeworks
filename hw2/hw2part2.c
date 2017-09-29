#include <stdio.h>

void drawRectangle(int width, int height,int startingPoint,int printLastLine);  /* fonksiyonlarin prototipleri*/
void drawDoubleCircle(int radius, int startingPoint, int whellDistance);
void drawCar();



void drawRectangle(int width, int height,int startingPoint,int printLastLine){    /*fonksiyon tanimlamasi*/
int a;		/* degiskenlerimi tanimladim*/
int b;
int c;
int d;
d=width*2;	/*sonsuz donguyu engellemek icin kullandim. */




 for (a = startingPoint; a != d; a++) {       /*Dikdortgen tabaninin yuksekligini ayarlamak icin bu for dongusunu kullandim.*/
 	for(c=startingPoint; c>0; c--){           /*Dikdortgenin baslangic noktasini ayarlamak icin bu for dongusunu kullandim.*/
 		printf(" ");
 	}

    for (b = startingPoint; b != height; b++ ) {			/*Dikdortgenin heigh ini ayarlamak icin bu for dongusunu kullandim */

        if (a == startingPoint || a== d-printLastLine) {    /*Dikdortgenin alt ve ust tabanlarinin cizgileri icin if kullandim*/
            printf("*");
       }else{
            if(b == startingPoint|| b == height-1){        /*Dikdortgenin sag ve sol koselerinin ne kadar icerde veya disarda oldugunu ayarlamak icin if kullandim.*/
                printf("*");
            }else{
                printf(" ");
            }
       }
    }
    printf("\n");     /*dongunun her satirinda bir satir alta inmek icin kullandim*/
}}



void drawDoubleCircle(int radius, int startingPoint, int whellDistance)   /*fonksiyon tanimlamasi*/
{
  int k;					 /* degiskenlerimi tanimladim*/
  int m;
  int yildizSayisi;      
  int boslukSayisi;
  int i;
  int j;
  
  yildizSayisi=1;
  boslukSayisi=radius-1+startingPoint;

  for (i=1;i<=radius;i++)      /*ust ucgen icin for dongusu*/
  {
        for(j=1;j<=boslukSayisi;j++)     /*sol ust ucgen icin her satir icin bastan birakilan bosluk sayisi icin for dongusu*/
        {
          printf("  ");
        }
        for(j=1; j<=yildizSayisi;j++)   /*sol ust ucgen icin her satir icin bosluktan sonra yazdirilacak yildiz sayisi icin for dongusu*/
        {
          printf(" *");
        }
        boslukSayisi--;
        yildizSayisi+=2;
        for(j=1; j<=boslukSayisi-startingPoint+1+whellDistance/2;j++)    /*sağ ust ucgen icin her satir icin bastan birakilan bosluk sayisi icin for dongusu*/
        {
          printf("    ");
        }
        for(j=1;j<=yildizSayisi-2;j++)    /*sağ ust ucgen icin her satir icin bosluktan sonra yazdirilacak yildiz sayisi icin for dongusu*/
        {
          printf(" *");
        }
        printf("\n");   /*her dongu tekrarinda her satir icin ayni seyi yapmasi amaciyla*/
}
yildizSayisi-=4;



for(i=1;i<radius;i++)   /*alt ucgen for dongusu*/
      {
        for(j=1;j<=i+startingPoint;j++){		/*sol alt ucgen icin her satir icin bastan birakilan bosluk sayisi icin for dongusu*/
              printf("  ");}
        for(j=1;j<=yildizSayisi;j++){				/*sol alt ucgen icin her satir icin bosluktan sonra yazdirilacak yildiz sayisi icin for dongusu*/
              printf(" *");}
       
       for(k=1;k<=i+whellDistance/2;k++){		/*sağ alt ucgen icin her satir icin bastan birakilan bosluk sayisi icin for dongusu*/
              printf("    ");}		
        for(m=1;m<=yildizSayisi;m++){			/*sağ alt ucgen icin her satir icin bosluktan sonra yazdirilacak yildiz sayisi icin for dongusu*/
              printf(" *");}
        yildizSayisi-=2;

        
        printf("\n");      /*her dongu tekrarinda her satir icin ayni seyi yapmasi amaciyla*/
      }

}

void drawCar()       /*fonksiyon tanimlamasi*/
{
drawRectangle(10, 40,11,0);
drawRectangle(5, 50,1,1);
drawDoubleCircle(4,3,7);


}
