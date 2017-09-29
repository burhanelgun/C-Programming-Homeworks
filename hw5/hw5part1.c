#include <stdio.h>
#define gridSize 4 /*gridsize'i 4 e 4 lük tanimladim*/

typedef enum {mined,
empty,
flaggedMined,
flaggedEmpty,
closedEmpty,
closedMined,
}cell;

void printGrid(cell grid[][gridSize]); /*fonksiyon prototipleri*/
int openCell(cell grid[][gridSize], int x, int y);
int isCellEmpty(cell grid[][gridSize], int x, int y);
int isLocationLegal(int x, int y);
void flagCell(cell grid[][gridSize], int x, int y);
void initGrid (cell grid[][gridSize]);
int asMain();

void printGrid(cell grid[][gridSize]) {
	int i,j;
	char front[gridSize][gridSize];
	for (i = 0; i < gridSize; i++) {    /* oyuncuya gosterilecek olan arrayi doldurmak icin loop kurdum*/
		for (j = 0; j < gridSize; j++) {
			front[i][j]='.';
		}
	}
	for (i = 0; i < gridSize; i++) {    /* oyuncuya gosterilecek olan arrayi ekrana yazdirmak icin loop kurdum*/
		for (j = 0; j < gridSize; j++) {
			printf("%c ", front[i][j]);
		}
		printf("\n");
	}
}

int openCell(cell grid[][gridSize], int x, int y){
	int result;
    int i,j,k,m,l,sifirsayisi,secim,moves;
    	char front[gridSize][gridSize];

	for (i = 0; i < gridSize; i++) {    /* oyuncuya gosterilecek olan arrayi doldurmak icin loop kurdum*/
		for (j = 0; j < gridSize; j++) {
			front[i][j]='.';
		}
	}
		result = -2;



	

	sifirsayisi=0; 	/*closedEmpty cell sayisini temsil eden bir degisken olusturdum*/
	moves = 0;		/* move sayisini temsil eden bir degisken olusturdum.*/

	
	for (m = 0; m < gridSize; m++) {  /*initGrid foksiyonunda keyfi olarak icini doldurdugum matrixin icinde ne kadar closedEmpty cell oldugunu ogrenmek icin loop kurdum*/
	    for (l = 0; l < gridSize; l++) {
	            if(grid[m][l]==closedEmpty){
	            	sifirsayisi++;
	            }
	
	    }
	}
	
	for (k=0;k<gridSize*gridSize;k++){ /* hucre icinde acilacak veya flag koyulacak islemleri bir donguye koydum bu dongu en fazla hucre sayisi kadar devam edebilir*/
	    printf("Open Icin = 1\nFlag Icin = 2\n");
	    scanf("%d",&secim);  /* kullanicidan alinan degere gore open yada flag yapilacaktir*/
		if (secim==1){  /* eger secim 1 ise open yapilacaktir*/
		
			printf("x giriniz\n");/*acilacak hucrenin x ve y degerlerini kullanicidan aldim*/
			scanf("%d",&y);
			printf("y giriniz\n");
			scanf("%d",&x);

			if(grid[x][y]==closedEmpty && isLocationLegal(x,y)==1 && isCellEmpty(grid,x,y)== 0){  /* eger hucre closedEmpty ve legal ise ve zaten acilmis bos bir hucre(empty cell) degilse iceri gir*/
					moves++;/* hareket sayisini 1 arttir*/

					front[x][y]= 'e';  /* kullaniciya gorunen arrayin indisini e yaptim*/
					grid[x][y]=empty; /* ayni indisi grid arrayinda empty cell e donusturdum*/
					sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					if(grid[x-1][y]==closedEmpty && gridSize>x-1 && x-1>=0 && gridSize>y && y>=0 && isCellEmpty(grid,(x-1),y)== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse  iceri girer)*/
						front[x-1][y]= 'e';  /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x-1][y]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}
					if(grid[x+1][y]==closedEmpty && gridSize>x+1 && x+1>=0 && gridSize>y && y>=0 && isCellEmpty(grid,(x+1),y)== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse iceri girer)*/
						front[x+1][y]= 'e';   /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x+1][y]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}
					if(grid[x][y-1]==closedEmpty && gridSize>x && x>=0 && gridSize>y-1 && y-1>=0 && isCellEmpty(grid,x,(y-1))== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse iceri girer)*/
						front[x][y-1]= 'e';  /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x][y-1]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;   /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}
					if(grid[x][y+1]==closedEmpty && gridSize>x && x>=0 && gridSize>y+1 && y+1>=0 && isCellEmpty(grid,x,(y+1))== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse iceri girer)*/
						front[x][y+1]= 'e';  /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x][y+1]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}
					if(grid[x+1][y+1]==closedEmpty && gridSize>x+1 && x+1>=0 && gridSize>y+1 && y+1>=0 && isCellEmpty(grid,(x+1),(y+1))== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse iceri girer)*/
						front[x+1][y+1]= 'e'; /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x+1][y+1]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}
					if(grid[x-1][y-1]==closedEmpty && gridSize>x-1 && x-1>=0 && gridSize>y-1 && y-1>=0 && isCellEmpty(grid,(x-1),(y-1))== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse iceri girer)*/
						front[x-1][y-1]= 'e'; /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x-1][y-1]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}
					if(grid[x+1][y-1]==closedEmpty && gridSize>x+1 && x-1>=0 && gridSize>y-1 && y-1>=0 && isCellEmpty(grid,(x+1),(y-1))== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse iceri girer)*/
						front[x+1][y-1]= 'e'; /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x+1][y-1]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}
					if(grid[x-1][y+1]==closedEmpty && gridSize>x-1 && x-1>=0 && gridSize>y+1 && y+1>=0 && isCellEmpty(grid,(x-1),(y+1))== 0){ /*secilen hucrenin etrafindaki 8 liye bakmak icin condition (eger closedEmpty ve legal hucre ise ve hucre empty degilse iceri girer)*/
						front[x-1][y+1]= 'e'; /*secilen hucrenin etrafindaki 8 liye gore oyuncuya gorunen arrayin hucresinin etrafindaki bos indilere "e" yazmak icin*/
						grid[x-1][y+1]=empty;  /* artik grid arrayindaki acilan cell'in etrafindaki bos olan yerleri empty yaptim*/
						sifirsayisi--;  /* eger bu donguye girdiyse closedEmpty sayisini bir azalt*/
					}



					for (i = 0; i < gridSize; i++) {    /*her islemde oyuncuya gorunen mayin tarlasini yazdirmak icin dongu*/
	        			for (j = 0; j < gridSize; j++) {
	        				
	           				printf("%c ", front[i][j]);
	                    }
	        			printf("\n");
	        		}

	    	       	if (sifirsayisi<=0){    /* closedEmpty sayisi 0 a esit yada daha az oldugunda tebrik mesaji yayinla*/

	    	        	printf("Congratulations! You win the game with %d moves\n",moves);
	    	        	return moves;
	    	        }

		}
	
			else if(isCellEmpty(grid,x,y)== 1){ /*eger oyuncu empty cell(zaten acik olan cell) i acmaya calisirsa kullaniciyi uyar ve mayintarlasini tekrar bastir*/
				
				
				printf("Zaten Acilmis Bir Hucre Sectiniz\n");
				for (i = 0; i < gridSize; i++) { /* nokta konulmus haliyle kullaniciya mayin tarlasini gostermek icin loop*/
		        	for (j = 0; j < gridSize; j++) {
		            	printf("%c ", front[i][j]);
		        	}
		        	printf("\n");
				}


			}
			else if(isLocationLegal(x,y)==0){ /*eger oyuncu tarla disinda(illegal yer) acmaya calisirsa kullaniciyi uyar ve mayintarlasini tekrar bastir*/
				
				for (i = 0; i < gridSize; i++) { /* nokta konulmus haliyle kullaniciya mayin tarlasini gostermek icin loop*/
		        	for (j = 0; j < gridSize; j++) {
		            printf("%c ", front[i][j]);
		        	}
		       		printf("\n");
				}
				printf("Mayin Tarlasinin Disina Ciktiniz\n");
				return result;

			}
			else if(grid[x][y]==flaggedEmpty || grid[x][y]==flaggedMined){ /*eger oyuncu flagged cell i acmaya calisirsa kullanici uyariyorum*/
				for (i = 0; i < gridSize; i++) { /* nokta konulmus haliyle kullaniciya mayin tarlasini gostermek icin loop*/
		        	for (j = 0; j < gridSize; j++) {
		            	printf("%c ", front[i][j]);
		        	}
		        	printf("\n");
				}
				printf("Flagli Hucreyi Acamazsiniz\n");
				return result;
			}			
			else if(grid[x][y]==closedMined){ /*eger oyuncu closedMined cell i acmaya calisirsa oyunu bitir*/
				printf("Mayina Bastiniz => GAME OVER\n");
				return result;
			}
		}

		if(secim==2){ /* eger 2 secilirse flag koymak icin condition*/
			moves++;  /* bu conditiona girerse hareket sayisini 1 arttir*/
			printf("x giriniz\n");/*flag koyulacak hucrenin x ve y degerlerini kullanicidan aldim*/
			scanf("%d",&y);
			printf("y giriniz\n");
			scanf("%d",&x);

			flagCell(grid,x,y);  /*ve bu x,y degerleri ile grid arrayini flag koyma arrayine yolla ve fonksiyonu cagir*/
			if(grid[x][y]==flaggedEmpty || grid[x][y]==flaggedMined){ /* eger hucreye flag koyulduysa*/
				front[x][y]='f';/* kullanciya gorulen arrayda flag konulan yere f yaz*/
				for (i = 0; i < gridSize; i++) {/* flag konulmus haliyle kullaniciya mayin tarlasini gostermek icin loop*/
			        for (j = 0; j < gridSize; j++) {
			            printf("%c ", front[i][j]);
			        }
			        printf("\n");
				}
			}
			else if(isCellEmpty(grid,x,y)!= 1) { /*flag konulmak istenen hucre empty olmayan bir hucreyse ve eger o hucreye flag konulamadiysa(zaten flagliyse)*/
		   		front[x][y]='.'; /* o hucreyi unflag et ve edilen yere oyuncuya gorunen arrayde nokta koy*/
				for (i = 0; i < gridSize; i++) { /* nokta konulmus haliyle kullaniciya mayin tarlasini gostermek icin loop*/
			        for (j = 0; j < gridSize; j++) {
			            printf("%c ", front[i][j]);
			        }
			        printf("\n");
				}
			}
			else if(isCellEmpty(grid,x,y)== 1){/*eger flag konulmak istenen hucre zaten acilmis bos bir hucreyse(empty cell) */
				for (i = 0; i < gridSize; i++) { /* nokta konulmus haliyle kullaniciya mayin tarlasini gostermek icin loop*/
			        for (j = 0; j < gridSize; j++) {
			            printf("%c ", front[i][j]);
			        }
			        printf("\n");
				}

			}
		}
	}
	return moves;
}

void flagCell(cell grid[][gridSize], int x, int y){


	
	if (grid[x][y]==flaggedEmpty){  /* eger flagEmpty konulmus bir hucreyse*/
		grid[x][y]=closedEmpty;  /*flagi kaldir closedEmpty yap*/
	}
	else if (grid[x][y]==flaggedMined){  /* eger flagmined konulmus bir hucreyse*/
		grid[x][y]=closedMined;  /*flagi kaldir closedMined yap*/
	}
	else if (grid[x][y]==closedEmpty){  /* eger hucre closedEmpty ise */
		grid[x][y]=flaggedEmpty; /* o hucreye flagEmpty koy*/
	}
	else if (grid[x][y]==closedMined){/* eger hucre closedMined ise */
		grid[x][y]=flaggedMined; /* o hucreye flageMined koy*/
	}
	else if(isCellEmpty(grid,x,y)== 1){ /*eger oyuncu zaten acilmis bos bir hucreye (empty cell) flag koymaya caliyorsa kullanciyi uyardim*/
		printf("Zaten Acilmis Bir Hucreye Flag Koyamazsiniz\n");
	}
	else if((isLocationLegal(x,y)==0)){ /* eger hucre legal degilse kullaniciyi uyardim ve -2 return ettim*/
			printf("Tarlanin Disina Flag Koyamazsiniz\n");
	}

}


	

int isCellEmpty(cell grid[][gridSize], int x, int y){
	int result;
	if (grid[x][y]==empty){  /* eger hucre empty ise */
		result=1;
		return result;  /* 1 return et*/
	}
	else { /* eger hucre empty degilse*/
		result=0;
		return result;  /* 0 return et*/
	}
}	


int isLocationLegal(int x, int y){
	int result;
	if (x<gridSize && y<gridSize && x>=0 && y>=0){ /* hucrenin legal olmasi icin indislerin gridesizedan kucuk  ve 0 a esit veya buyuk olmasi gerek*/
		result=1;
		return result; /* eger legalse 1 return et*/
	}

	else{ /* eger legal degilse 0 return et*/
		result=0;
		return result;
	}
}


void initGrid (cell grid[][gridSize]){
	cell grid2[gridSize][gridSize] = {  /* kendi matriximi keyfi olarak doldurdum*/
		{closedEmpty,closedEmpty,closedMined,closedEmpty},
		{closedEmpty,closedEmpty,closedMined,closedEmpty},
		{closedEmpty,closedEmpty,closedMined,closedEmpty},
		{closedEmpty,closedEmpty,closedMined,closedEmpty},
		
	};
	int i,j;
	

	for (i = 0; i < gridSize; i++) {  /* yukarda keyfi olarak doldurdugum grid2 arrayimin her elmanini grid arrayine atmak icin loop*/
	    for (j = 0; j < gridSize; j++) {
	        grid[i][j]=grid2[i][j];
	    }
	}
	
}
int asMain(){
	cell grid[gridSize][gridSize];
	int x,y;
	x=0; /* init hatasi almamak icin onceden 0 atadim ama zaten degerleri degisecek*/
	y=0;
	initGrid (grid);
	printGrid(grid);/* print grid fonksiyonumu cagirdim*/
	openCell(grid, x, y); /* opencell fonksiyonumu cagirdim*/
	return 0;
}


int main(){
	asMain();
}
		

		
