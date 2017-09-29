#include <stdio.h>
#define a_year 365     /* bir yili 365 olarak constant tanimladim*/
#define a_month 30     /* bir ayi 365 olarak constant tanimladim*/
int theAge(int day,int month, int year, int today,int this_month, int this_year );  /*  foksiyonun prototipini tanimladim*/
int daysLeft(int day,int month, int today,int this_month);  /*  foksiyonun prototipini tanimladim*/





int theAge(int day,int month, int year, int today,int this_month, int this_year )  /*fonkiyonumu tanimladim*/
{
	int gunlerfarki;     /*   fonksiyonum icinde kullandigim degiskenleri tanimladim*/
	int aylarfarki;
	int yillarfarki;
	int gunlerintoplami;
	int yas;
	gunlerfarki=today-day;      /*gunlerin farkini bulmak icin bugunden dogumgununu cikardim.*/
	aylarfarki=this_month-month; /*aylar farkini bulmak icin su anki aydan dogdugum ayi cikardim.*/
	yillarfarki=this_year-year; /* yillar farkini bulmak icin bulundugum yildan dogdugum yili cikardim*/
	gunlerintoplami= ((yillarfarki*a_year)+(aylarfarki* a_month)+gunlerfarki); /*toplam yasanan gunu bulmak icin yil farkini 365(a_year) ile, ay farkini 30(a_month) ile carptim ve bu degeleri gun farkiyla topladim.*/
	yas= gunlerintoplami/a_year; /*toplam yasanan gun(gunlerintoplami) sayisini 365(a_year)e boldum ve yasanan yil sayisini buldum bu degeri yas adli degiskene atadim */
	printf("%d",yas); /*yas adli degiskene atanan degeri ekrana yazdirdim.*/
	return(yas); /* yas adli degiskenin degerini dondurdum.*/


}




int daysLeft(int day,int month, int today,int this_month) /*fonkiyonumu tanimladim*/
{

int gunfarki;     /*   fonksiyonum icinde kullandigim degiskenleri tanimladim*/
int ayfarki;
int kalangun;

gunfarki=day-today;      /*gunlerin farkini bulmak icin bugunden dogumgununu cikardim.*/
ayfarki=month-this_month;   /*aylar farkini bulmak icin su anki aydan dogdugum ayi cikardim.*/
kalangun=(a_year+((a_month*ayfarki) + gunfarki))%a_year;/* kalan gunu bulmak icin yil farkini 365(a_year) ile, ay farkini 30(a_month) ile carptim ve bu degeleri gun farkiyla topladim.*/
printf("%d",kalangun);/*kalangun adli degiskenin degerini ekrana yazdirdim*/                     /*negatif deger cikmamasi icin bu taplamida 365 ile topladim ayni zamanada 365 ten fazla deger cikmamasi icinde tum toplamin 365 ile modunu aldim.  */

return(kalangun); /*kalangun adli degiskenin degerini dondurdum*/
}


