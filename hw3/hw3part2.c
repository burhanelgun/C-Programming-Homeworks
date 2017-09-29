#include <stdio.h>
int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, int*krs10, int *krs5, int *krs1); /*fonksiyon prototipi tanimlamasi*/







int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, int /* fonksiyon tanimlamasi*/
*krs10, int *krs5, int *krs1)
{
		double paraustu;  /* degisken tanimlamalari*/
		double birliraharici;
		paid=paid+0.001; /* anlamli rakam sayisindan dogacak sorunu engellemek amaciyla paid'e 0.001 ekledim*/

		
		*tl1 = 0;     /*pointerlar random deger aldigi icin onceden onlara 0 atadim*/
		*krs50 = 0;
		*krs25 = 0;
		*krs10 = 0;
		*krs5 = 0;
		*krs1 = 0;
		

		if (paid>=due) /* eger paid due ya esit yada daha fazlaysa normal sekilde program calisir*/
		{
				paraustu= paid - due; /* paraustunu ogrenmek icin paid den due yi cikardim.*/
				*tl1= paraustu/1; /*paraustunun tam kismini almak icin onu 1 e boldum ve *tl1 pointerina attim*/
				birliraharici= paraustu-*tl1;  /* toplam paraustunden 1tl lik tam kisimlari cikardim cunku bu parayi 50,25,10,5 ve 1 kuruslara dagitmam lazim */

				if (birliraharici>=0.50) /*bir liralik tam kisimlarin haricinde kalan para 0.50 liraya esit yada buyukse donguye gir*/
				{
						 *krs50= (birliraharici)/0.50; /*birliraharici icinde kac tane 0.50 lira oldugunu ogrenmek icin onu 0.50 ye bolup *krs50 pointerina atiyorum*/

						 birliraharici = birliraharici- (*krs50)*0.50 ; /*birliraharicinden 0.50 liralari eksiltmek icin birliraharicinden 0.50 ile *krs50 in carpimini cikaririm*/
				}


				if (birliraharici>=0.25)/*bir liralik tam kisimlarin haricinde kalan para 0.25 liraya esit yada buyukse donguye gir*/
				{
						 *krs25= (birliraharici)/0.25; /*birliraharici icinde kac tane 0.25 lira oldugunu ogrenmek icin onu 0.25 ye bolup *krs25 pointerina atiyorum*/
						
						  birliraharici = (birliraharici- (*krs25)*0.25) ;  /*birliraharicinden 0.25 liralari eksiltmek icin birliraharicinden 0.25 ile *krs25 in carpimini cikaririm*/
				}

				
				if (birliraharici>=0.10)/*bir liralik tam kisimlarin haricinde kalan para 0.10 liraya esit yada buyukse donguye gir*/
				{
						 *krs10= (birliraharici)/0.10; /*birliraharici icinde kac tane 0.10 lira oldugunu ogrenmek icin onu 0.10 ye bolup *krs10 pointerina atiyorum*/
						  birliraharici = birliraharici- (*krs10)*0.10 ; /*birliraharicinden 0.10 liralari eksiltmek icin birliraharicinden 0.10 ile *krs10 nun carpimini cikaririm*/
				}


				
				if (birliraharici>=0.05)/*bir liralik tam kisimlarin haricinde kalan para 0.05 liraya esit yada buyukse donguye gir*/
				{
						 *krs5= (birliraharici)/0.05; /*birliraharici icinde kac tane 0.05 lira oldugunu ogrenmek icin onu 0.05 ye bolup *krs5 pointerina atiyorum*/
						  birliraharici = birliraharici- (*krs5)*0.05 ; /*birliraharicinden 0.05 liralari eksiltmek icin birliraharicinden 0.05 ile *krs5 in carpimini cikaririm*/
				}

										

				if (birliraharici>=0.01)/*bir liralik tam kisimlarin haricinde kalan para 0.01 liraya esit yada buyukse donguye gir*/
				{

						 *krs1= (birliraharici)/0.01; /*birliraharici icinde kac tane 0.01 lira oldugunu ogrenmek icin onu 0.01 ye bolup *krs1 pointerina atiyorum*/
						  birliraharici = birliraharici- (*krs1)*0.01; /*birliraharicinden 0.01 liralari eksiltmek icin birliraharicinden 0.01 ile *krs1 in carpimini cikaririm*/
				}
				return 1; /* paid due ya esit yada daha fazla oldugu icin normal sekilde program calisir ve 1 return eder*/
		}

		else /* eger paid due den daha azsa program calismaz*/
		{
				return 0; /*paid due dan daha az oldugu icin 0 return eder*/
		}
}
