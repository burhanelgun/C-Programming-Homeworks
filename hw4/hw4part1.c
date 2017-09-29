#include <stdio.h>

void addPadding(double inputArr[], int inputArraySize, double outputArr[], int*outputArraySize, int paddingWidth,void paddingMethod(double[], int, int));
void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth);
void samePadding(double outputArr[], int outputArraySize, int paddingWidth);
void halfPadding(double outputArr[], int outputArraySize, int paddingWidth);



void addPadding(double inputArr[], int inputArraySize, double outputArr[], int*outputArraySize, int paddingWidth,void paddingMethod(double[], int, int)){
		
		int a,b,c,d,e,f,k,l,m;/*degisken tanimlamalarimi yaptim*/
		
		
		*outputArraySize = inputArraySize + 2*paddingWidth;/*bosluk sayisiyla inputarraysize i toplayarak outputarraysize i belirledim.*/
		
		printf("Input Array = {");
		
		for(a=0; a<inputArraySize; a++){/*ilk arrayi yazdirmak icin*/
				if (a!=inputArraySize-1){  /*eger son elemana gelinmediyse elemani yaz ve yanina bir virgul koy*/
						printf("%.0f,",inputArr[a] );
				}
				else { /* eger son elemana gelindiyse sayiyi yaz ve yanina  curly brace koy*/
						printf("%.0f}\n",inputArr[a] );


		}
		}
		for(b=0; b<inputArraySize ;b++){  /* inputarray in herbir degerini paddingwidht kadar saga kaydirmak icin*/
				outputArr[b+paddingWidth]= inputArr[b];
		}
		for(c=0; c<inputArraySize ;c++){	/*inputarrayi kaydirdiktan sonra yanina paddingWidht kadar bosluk birakmak icin*/
				outputArr[c+paddingWidth]= inputArr[c];
		}
		paddingMethod(outputArr,*outputArraySize,paddingWidth);/*fonksiyona parametre olarak gonderdigim fonksiyonu burda cagirdim*/
		printf("Output Array = ");
		if (outputArr[0]-(int)outputArr[0]==0){ /*eger outputarrayin double elmaniyla onun int ile cast edilmis hali arasindaki fark 0 ise  halfPadding cagirilmamistir*/
					printf("[");
					for (d =0; d<paddingWidth;d++){ /*outputarrayin ilk kismini yazdirmak icin*/
				
						printf("%.0f,",outputArr[d] );
					
					}
					for (e=paddingWidth;e<paddingWidth+inputArraySize;e++){ /*input arrayi yazdirmak icin(tam sayi)*/
									
							printf("%.0f,",outputArr[e] );
						}
					for (f=paddingWidth+inputArraySize;f<*outputArraySize;f++){/* outputarrayin son kismini yazdirmak icin(tam sayi)*/
							if (f!=*outputArraySize-1){/*eger son elemana gelinmediyse elemani yaz ve yanina bir virgul koy(tam sayi)*/
							printf("%.0f,",outputArr[f] );
						}
						else {    /* eger son elemana gelindiyse sayiyi yaz ve yanina  koseli parantez koy*/
							printf("%.0f]",outputArr[f] );}
					}
					
		}
		else{	/*eger outputarrayin double elmaniyla onun int ile cast edilmis hali arasindaki fark 0 dan farkli ise  halfPadding cagirilmistir*/

					printf("[");
					for (k =0; k<paddingWidth;k++){ /*outputarrayin ilk kismini yazdirmak icin(ondalikli)*/
					
								printf("%.1f,",outputArr[k] );
						};
					
					for (l=paddingWidth;l<paddingWidth+inputArraySize;l++){ /*input arrayi yazdirmak icin(tam sayi)*/
									
								printf("%.0f,",outputArr[l] );
						
					}
					for (m=paddingWidth+inputArraySize;m<*outputArraySize;m++){/* outputarrayin son kismini yazdirmak icin(ondalikli)*/
						if (m!=*outputArraySize-1){ /*eger son elemana gelinmediyse elemani yaz ve yanina bir virgul koy*/
								printf("%.1f,",outputArr[m] );
						}
						else {          /* eger son elemana gelindiyse sayiyi yaz ve yanina  koseli parantez koy*/
								printf("%.1f]",outputArr[m] );
					}		
					}
		}
		printf("\n");
}

void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth){
	
int i;
	int j;


	for(i=0; i<paddingWidth; i++){/*outputarrayin solundaki bosluk bolumunu 0 lamak icin dongu kurdum*/
		outputArr[i]=0;
	}

	for(j=outputArraySize-paddingWidth; j<outputArraySize; j++) /*outputarrayin sagindaki bosluk bolumunu 0 lamak icin dongu kurdum*/
		outputArr[j]=0;
	
	}


void samePadding(double outputArr[], int outputArraySize, int paddingWidth){
	int k;
	int l;
		for(k=0; k<paddingWidth ; k++){  /*inputarrayin ilk elemanini kullanarak outputarrayin solundaki bosluk bolumunu dolurmak icin dongu kurdum*/
			outputArr[k]=outputArr[paddingWidth];
		}
		for(l=outputArraySize-paddingWidth; l<outputArraySize; l++)/*inputarrayin son elemanini kullanarak outputarrayin sagindaki bosluk bolumunu dolurmak icin dongu kurdum*/
			outputArr[l]=outputArr[outputArraySize-paddingWidth-1];


}


void halfPadding(double outputArr[], int outputArraySize, int paddingWidth){
	int m;
	int n;
for(m=0; m<paddingWidth ; m++){  /*inputarrayin ilk elemaninin yarisini kullanarak outputarrayin solundaki bosluk bolumunu dolurmak icin dongu kurdum*/
			outputArr[m]=outputArr[paddingWidth]/2;
		}
for(n=outputArraySize-paddingWidth; n<outputArraySize; n++){ /*inputarrayin son elemaninin yarisini kullanarak outputarrayin sagindaki bosluk bolumunu dolurmak icin dongu kurdum*/
	outputArr[n]=outputArr[outputArraySize-paddingWidth-1]/2;}
}

