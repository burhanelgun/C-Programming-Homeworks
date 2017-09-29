#include <stdio.h>    /* bu parti yapamadim ama yapabildigim kadarini yazip gondermek istedim */
void drawFunction(int xAxis,int yAxis,int functionNumber);    /*fonsiyon prototipi*/
  

void drawFunction(int xAxis,int yAxis,int functionNumber){   /*fonskiyon tanimlama*/
	int i;
	while (yAxis>0){       /*fonksiyonun önce y ekseni yazdirilmali, y ekseni kadar asağiya inecek*/
		yAxis--;
		printf("|");
		for (i = 0; i < xAxis; ++i)     /*ilk yildiz x ekseni uzunlugu kadar bosluktan sonra olacak ve y ekseni kadar asagi devam edecek*/
		{
		printf(" ");
		}
		printf("*\n");
	}
	while (xAxis>0){   /* en son x ekseni cizgisi x ekseni kadar cizdirilecek*/
		xAxis--;
		printf("-");
	}
}
