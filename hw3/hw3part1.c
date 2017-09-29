#include <stdio.h>
int isPrime(int num);                /*fonksiyon prototipleri*/
int goldbach(int num, int *p1, int *p2);





int goldbach(int num, int *p1, int *p2)  /* goldbach fonksiyon tanimlamasi*/
{
	int k;   /*degisken tanimlamalari*/
	int m;
	int hersayi;
	if(num % 2 == 0 && num !=2 )        /*sayinin goldbach olmasi icin cift olmasi lazim ama 2 olamaz cunku 1 + 1 icin 1 asal degil.*/
	{
		 	for (k = 0 ; k < (num/2); k++){ /*(sayinin ilk yarisi icin) k degiskenimi 0 dan baslatip k/2 ye kadar arttirdim cunku yarisina kadar bakmak yeterli*/
		 		hersayi=isPrime(k);      /*her k sayisini isPrime fonksiyonuna gonderdim ve return degerini hersayi adli degiskende tuttum.*/

		 		if(hersayi==1){    /* isPrime fonksiyonu, sayi asal oldugunda 1 return ediyordu.Ilk asal olan k sayisinda *p1 pointer'ina k sayisini atadim.*/
		 			 *p1=k;}



		 	
		 	for (m = num ; (m/2) >0; m--){ /*(sayinin son yarisi icin) m degiskenine num sayisini atadim ve sayinin yarisina kadar m sayisini azalttim*/
		 		hersayi=isPrime(m); /*her m sayisini isPrime fonksiyonuna gonderdim ve return degerini hersayi adli degiskende tuttum.*/

		 		if(hersayi==1){  /* isPrime fonksiyonu, sayi asal oldugunda 1 return ediyordu.Ilk asal olan m sayisinda *p2 pointer'ina m sayisini atadim.*/
		 			 *p2=m;
		 		}
		 		if(*p1 + *p2 == num){  /*artik *p1 ve *p2 pointerinda asal sayi var ama bunlarin toplamlarinin num'a esit olmasi lazim,bunu konrol ediyorum*/
		 	
		 	return 1;}}}} /*sayi goldbach ise 1 return ediyor  */
return 0;                /*sayi golbach degilse 0 return ediyor.*/
	}
	


int isPrime(int num){   /*isPrime fonksiyon tanimlamasi*/
	int i;         /* degisken tanimlamalari*/
	int counter;
	 counter=0;


if (num>1){   /*asal sayilar 2 den baslar bu yuzden num 1 den buyuk olmali*/
    for(i=2;i<=num/2;i++) /*  2 den baslayarak sayinin yarisina kadar sayinin boleni olup olmadigina bakmamiz yeterli*/
    {
        if(num%i==0) /*num'a tam bolunen  her i sayisi icin counter bir artar*/
            {
            counter++;
            }
    }
    
    if(counter==0) /* eger counter hic artmadiysa num'in tam sayi boleni olmadigi yani sayinin asal sayi oldugu anlamina gelir.*/
    {
        return 1;   /* counter artmadigi icin sayi asaldir bu yuzden 1 return eder.*/
    }
    else
    {
        return 0; /* counter arttiysa sayinin tam boleni var ve bu yuzden sayi asal degil fonksiyon 0 return eder*/
    }
    
}

else{    /* eger sayi 1 ve birden kucukse hic kontrol etmeden direk 0 return ederim yani sayi asal degildir*/

    return 0;

}

}











