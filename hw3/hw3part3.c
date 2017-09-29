#include <stdio.h>
int charge(int cardType, int* monthlyUse, double* balance); /*fonksiyon prototipini tanimladim*/



int charge(int cardType, int* monthlyUse, double* balance){ /* fonskiyonumu tanimladim*/

	switch (cardType){   /* kart tiplerine gore durumlari belirledim*/
						case 1: /* 1. kart tipi icin */
						if (*monthlyUse<1 && *balance<2.30){ /*monthlyUse 1 den az ve balance da 2.30 dan kucukse -1 return etmeli*/
							return -1;

						}
						else{ /* eger aylik kullanim 1 veya 1 den daha fazla ise yada bakiye 2.30 dan fazla ise duruma gore montlyUse'u yada balance i azaltmaliyiz*/
						if (*monthlyUse>=1){ /* monthlyUse 1 e esit ve buyukse bakiyeye bakmadan direk montlyUse 1 azalir ve 0 return edilir.*/

							*monthlyUse=*monthlyUse-1;
							return 0;
						}
						
						else{/* eger monthlyUse 1 den kucukse bakiyeden 2.30 azalir ve 0 return edilir*/
							*balance= *balance -(2.30);
							return 0;
							
						}	}
						break; /*eger bu case'e girerse digerlerinede girmemesi icin break yaptim*/

						case 2: /* 2. kart tipi icin */
						if (*monthlyUse<1 && *balance<1.15){ /*monthlyUse 1 den az ve balance da 1.15 den kucukse -1 return etmeli*/
							return -1;
						}
						else{  /* eger aylik kullanim 1 veya 1 den daha fazla ise yada bakiye 1.15 den fazla ise duruma gore montlyUse'u yada balance i azaltmaliyiz*/
						if (*monthlyUse>=1){ /* monthlyUse 1 e esit ve buyukse bakiyeye bakmadan direk montlyUse 1 azalir ve 0 return edilir.*/

							*monthlyUse=*monthlyUse-1;
							return 0;
						}
						
						else{/* eger monthlyUse 1 den kucukse bakiyeden 1.15 azalir ve 0 return edilir*/
							*balance= *balance -(1.15);
							return 0;
						}	}
						break;/*eger bu case'e girerse digerlerinede girmemesi icin break yaptim*/

							

						case 3: /* 3. kart tipi icin */
						if (*monthlyUse<1 && *balance<1.65){/*monthlyUse 1 den az ve balance da 1.65 den kucukse -1 return etmeli*/
							return -1;}
						else{/* eger aylik kullanim 1 veya 1 den daha fazla ise yada bakiye 1.65 den fazla ise duruma gore montlyUse'u yada balance i azaltmaliyiz*/
						if (*monthlyUse>=1){ /* monthlyUse 1 e esit ve buyukse bakiyeye bakmadan direk montlyUse 1 azalir ve 0 return edilir.*/

							*monthlyUse=*monthlyUse-1;
							return 0;
						}
						
						else{/* eger monthlyUse 1 den kucukse bakiyeden 1.65 azalir ve 0 return edilir*/
							*balance= *balance -(1.65);
							return 0;
							break;/*eger bu case'e girerse digerlerinede girmemesi icin break yaptim*/
						}	}
						

	
						default: /* eger kullanici bu 3 kart tipinden farkli bir kart tipi girerse -2 return etmeli */
							return -2;

	}
}
