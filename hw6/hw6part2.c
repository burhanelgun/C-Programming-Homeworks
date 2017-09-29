#include <stdio.h>   /*kutuphaneler*/
#include <string.h>

#define MAX_NUM_WORDS 500    /*constant tanimlamalari*/
#define WORD_LENGTH 50

int getAndFilterWord(char * w);               /*fonksiyon prototipleri*/
void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],int occur[MAX_NUM_WORDS], int *word_count);
void myTest();
void sortWords(char words[MAX_NUM_WORDS][WORD_LENGTH], int occur[MAX_NUM_WORDS],int word_count);



void myTest(){
	char text[30000];
	char w[WORD_LENGTH];
	char words[MAX_NUM_WORDS][WORD_LENGTH];
	int occur[MAX_NUM_WORDS];
	int i,j,k,word_count,flag1,t,flag2;
	flag1=0;  /* flag1 i 0 dan baslattim*/
	word_count=0;
	for(j=0;j<MAX_NUM_WORDS;j++){     /*occur un icini 1'le doldurdum, en fazla max num words olabilir*/
		occur[j]=1;
	}


	printf("bir cumle giriniz:\n");
	fgets(text,30000,stdin);         /*kullanicidan standartinput(klavye) ile en fazla 30000 uzunlugunda bir string aldim ve bunu text arrayine attim*/
	for (k = 0; k < strlen(text); k++)
	{
		flag2=0;           /*flag2 yi 0 dan baslattim*/

		if(k==0){     /*ilk kelime icin w doldurma*/
			for(i=0;text[i]!=' ';i++){  /*ilk kelimeden sonra bosluga gelene kadar text arrayini taradim*/
				w[i]=text[i];     /*taradigim yerleri w arrayine attim.yani ilk kelimeyi aatim*/
			}
			w[i]='\0';   /* en sona null karakteri ekledim*/

			if(strcmp(w,"end")==0){    /*eger w kelimesi end ise kelime almayi birakmak icin break yaptim*/
				break;
			}
		
		
			if(getAndFilterWord(w)==1){   /* ilk kelimeyi getAndFilterWord fonksiyonuna yolladim ordan 1 degeri return olursa adimlara devam ediyorum*/
				for(t=0;t<MAX_NUM_WORDS;t++){   /* t=0 dan max num words e kadar words[t] kelimesi ile w kelimesini karsilastirdim*/
					if(strcmp(words[t],w)==0){  /*w kelimesi words arrayinda varmi diye bakiyorum*/
			
						occur[t]++;  /* eger ayni kelimeden varsa occur arrayinda o kelimenin ilk oldugu indisi 1 arttiriyorum*/
						flag1=1;  /* bir tane bile ayni kelime oldugunda flag1 i 1 yapiorum*/
					}
			    }
			}


				if (flag1==0){   /* ayni kelimeden yoksa flag1 0 olarak kalmistir*/
					addWord(w, words,occur,&word_count);   /* kelime ayni olmadigi icin yani farkli bir kelime oldugu icin. kelimemi addword fonksiyonuna yolluyorum(words arrayine eklemis oluyorum)*/
					word_count=word_count+1;   /* kelime words arryine gittiginden word count i 1 arttiriyorum.*/
				}
		}
				
		
		else{	/*ilk kelimeden sonraki kelimeler icin w doldurma*/
				
			for(i=i+1,j=0;text[i]!=' ';i++,j++){   /* w nin icini dolduruyorum*/
					w[j]=text[i];
				}
				w[j]='\0';  /* sununa null karakter ekliyorum*/
				    if(strcmp(w,"end")==0){   /* eger w kelimesi end ise break yapiyorum*/
				    	break;
				    }



				if(getAndFilterWord(w)==1){  /*kelimeyi getAndFilterWord fonksiyonuna yolladim ordan 1 degeri return olursa adimlara devam ediyorum*/
					for(t=0;t<MAX_NUM_WORDS;t++){ /* t=0 dan max num words e kadar words[t] kelimesi ile w kelimesini karsilastirdim*/
						if(strcmp(words[t],w)==0){  /*w kelimesi words arrayinda varmi diye bakiyorum*/
							occur[t]++; /* eger ayni kelimeden varsa occur arrayinda o kelimenin ilk oldugu indisi 1 arttiriyorum*/
							flag2=1;  /* bir tane bile ayni kelime oldugunda flag2 yi 1 yapiorum*/
						}
				    }
				}


				if (flag2==0){/* ayni kelimeden yoksa flag2 0 olarak kalmistir*/
					addWord(w, words,occur,&word_count); /* kelime ayni olmadigi icin yani farkli bir kelime oldugu icin. kelimemi addword fonksiyonuna yolluyorum(words arrayine eklemis oluyorum)*/
					word_count=word_count+1;/* kelime words arryine gittiginden word count i 1 arttiriyorum.*/
				}
		}
				
	}

	sortWords(words, occur,word_count);    /*words arrayim gelen farkli w ler ile doldu.occur imda ayni kelime oldugunda o kelimenin words de ilk gorundugu indisi ile ayni indisini 1 attrirdi, artik words u siralayabiliriz*/
/*words arrayini siralamak icin sortWord fonksiyonunu cagirdim*/
}
		


int getAndFilterWord(char * w){
	int i,result;
	char onlyletter[WORD_LENGTH];

	result=0;  /* resulti 0 olarak baslattim*/

	for(i=0;w[i]!='\0';i++){     /*gelen farkli w kelimelerini eger buyukse ,harf harf kucultmek icin olan bir for dongusu*/
		if(w[i]>= 'A' && w[i]<= 'Z'){  /* eger buyukse*/
			w[i]=w[i]+'a'-'A';  /* buyuk olan harfi 'a' ile toplayip 'A' cikarttigimda o harfi kucultmus oluyorum*/
			result=1;
		}
	}

	for(i=0;w[i]!='\0'&& !((w[i]>= 'a' && w[i]<= 'z')==0);i++){ /*letter olmayanlari elemek icin w icinde harf harf dolasan for dongusu*/
		if(w[i]>= 'a' && w[i]<= 'z'){    /* eger w nin icinde sadece kucuk harfler varsa */
			onlyletter[i]=w[i];   /* w yi onlyletter arryime attim*/
			result=1;  /* tum harfler kucuk harf oldugu icin result i 1 yaptim*/
		}
	}
	onlyletter[i]='\0';  /* onlyletter arrayimin sonuna null karakteri ekledim*/
    strcpy(w,onlyletter);  /* en son olarak onlyletter arrayimi w arrayine kopyaladim*/

	return result;  /* ve result i returnledim*/
}
void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],int occur[MAX_NUM_WORDS], int *word_count){
	int i;


	for(i=0;w[i]!='\0';i++){  /* gelen her farkli w yi words arrayine atmak icin for dongusu*/
			words[*word_count][i]=w[i];  /* harf harf w nin elemanlarini words un wordcount'inci kelimesinin indislerine atiyorum*/
	}


}


void sortWords(char words[MAX_NUM_WORDS][WORD_LENGTH], int occur[MAX_NUM_WORDS],int word_count){  /*selection sort yaptim*/
	

	int max,temp;
	int i,j;
	char temparray[WORD_LENGTH]; /* words arrayinde swap yapmak icin bir temparray tuttum*/


	for (i=0; i < word_count-1; i++){  /*occur arrayinin icini son eleman e kadar tarayacak*/
	    max = i;  /* en buyuk i olsun dedim*/
		for (j=i+1; j <  word_count; j++){   /* j yi i den 1 sonraki degerden baslattim ve son elemana kadar(son eleman dahil) occur icinde tarama yapacak*/
			if (occur[j] > occur[max]) /* eger occur arrayinin j inci indisi occur arrayinin max inci indisinden buyukse */
				max=j; /*max degeri degisir ve artik j olur*/
			}
		
	if (max != i){   /* eger max degeri i den farkliysa degisIklik yapilmasi(swap edilmesi gerekir)*/
	
	 temp = occur[i];   /*temp degiskenine occurun i inci elemanini atadim*/
     occur[i] = occur[max];  /* occurun i inci elemaninina occurun max inci elemanini atadim*/
     occur[max] = temp;  /* occurun max inci elemanina temp degiskenini atadim*/
					/* occur icin swap yaptim ama amac wordsu siralamak oldugu icin ayni zamanda words arrayinin indilerinide occurun indislerine paralel olarak swap edebiliriz*/
				 strcpy(temparray,words[i]);   /*temparrayine words un i inci kelimesini kopyaladim */
	 strcpy(words[i],words[max]);  /* words un i inci kelimesine words un max inci kelimesini kopyaladim*/
	 strcpy(words[max],temparray);  /* words un max inci kelimesine temparrayi kopyaladim*/



}
	}


	

	for(i=0; i<word_count;i++){  /* kullaniciya words arraynin siralanmis halini ve hangi kelimeden kac tane oldugunu gostermesi icin for dongusu*/
		if(words[i][0]!='\0'){  /* en son null karakterinide kelime olarak saymamasi icin kosul koydum*/
			printf("%s ",words[i] );
			printf(" ===>  ");
		}
		if(words[i][0]!='\0'){    /* en son null karakterinide kelime olarak saymamasi icin kosul koydum*/
			printf("%d\n",occur[i]);
		}
	}


}









