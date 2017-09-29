void writeRecords(Records records, char* filename) {

	FILE *f ; /*f adinda file pointer olusturuyorum*/
	f= fopen(filename, "wb"); /* dosyayi write binary modunda aciyorum*/
	fwrite(&records, sizeof(records), 1, f);/*records yapisini ,records boyutunda,1 defa binary f dosyasina yaziyorum*/
	fclose(f);/*dosyayi kapatiyorum*/
}

void readRecords(Records *records, char* filename) {

    FILE *f; /*f adinda file pointer olusturuyorum*/
    f=fopen(filename, "rb");/* dosyayi read binary modunda aciyorum*/
    while(feof(f)!=1){/*dosya sonuna gelene kadar*/
		fread(&records->data, sizeof(Record), sizeof(records->data), f);/*f dosyasindan records->data arrayine Record boyutunda, records->data kadar veri okunur*/
	}	
	fclose(f); /*dosyayi kapatiyorum*/
}

void writePeople(People people, char* filename) {
	
	FILE *f ; /*f adinda file pointer olusturuyorum*/
	f= fopen(filename, "wb");/* dosyayi write binary modunda aciyorum*/
	fwrite(&people.data, sizeof(People),1, f);/*people.data arrayini ,People boyutunda,1 defa binary f dosyasina yaziyorum*/
	fclose(f);/*dosyayi kapatiyorum*/
}

void readPeople(People *people, char* filename) {

    FILE *f; /*f adinda file pointer olusturuyorum*/
    f=fopen(filename, "rb");/* dosyayi read binary modunda aciyorum*/
    while(feof(f)!=1){/*dosya sonuna gelene kadar*/
		fread(&people->data, sizeof(People), sizeof(people->data), f);/*f dosyasindan people->data arrayine People boyutunda, people->data kadar veri okunur*/
	}
    fclose(f); /*dosyayi kapatiyorum*/
}

void read(char* filename, People *people, Records *records) {


	FILE* f; /* f adinda file pointer olusturuyorum*/
	char name[NAMELEN];/*fscanfle kisinin adini tutatacak sonrasinda cat ile kendisine newssurname eklenecek,50 uzunlugunda olabilir*/
	char surname[NAMELEN];/*fscanfle kisinin soy adini tutacak ama basinda bosluk olmayacak,50 uzunlugunda olabilir*/
	char newsurname[NAMELEN];/* kisinin soyadini basinda bosluk olarak tutacak,50 uzunlugunda olabilir*/
	int id,kactel,i,k; /*id kisinin id sini, kactel kisinin kac tane telfon no su oldugunu tutacak*/
	char phones[MAXRECORD][NAMELEN];/*telefon numaralarini tutacak,bir kisinin en fazla 50 basamakli 500 tane numarasi olabilir*/


	f = fopen(filename, "r");  /*input.txt dosyasini read modunda aciyorum*/
		while(!feof(f)){ /* f dosyasinin sonuna kadar bak*/
		   	
		   	fscanf(f,"%d %s %s %d",&id,name,surname,&kactel);/*aralarinda bosluk oldugu icin fscanfle f dosyasindan id ye integer, name ve surname'e*/
		   													 /*string, kactel'e integer deger okudum*/			
			
			for(i=0;kactel>0;kactel--,i++){ /*her kisinin numara sayisi degiskenlik gosterdigi icin numarayi*/
											/*yukarda okumadim, burda kactel 0 olana kadar okudum*/
	   		   	fscanf(f,"%s",phones[i]); /*telefon no yu kac tel sayisi kadar okudum*/
	   		   	strcpy(records->data[records->size].number,phones[i]);/*struct yapisindaki number a telefon noyu kopyaladim*/
	   		   	records->data[records->size].id=id;/*struct yapisindaki id ye id yi atadim*/
				records->size++; /*her bir telefon numarasinda records size 1 artmali*/
	/*bu donguye giren kisinin 1 den fazla telefonu olursa , number ve id sinnin data indisleri ayni yani records->size olmali*/
			}

			newsurname[0]=' '; /*yukarda surname degiskenine soyadini okumustum*/
								/* newsurname degiskenin basina bosluk koyuyorum */

			for(k=1;k<=strlen(surname);k++){ /* bosluk koyduktan sonra surnamenin her bir elemanini*/
											 /*newsurname e bosluktan sonra sirayla atiyorum*/	
				newsurname[k]=surname[k-1];
			}

			newsurname[k]='\0';/*newsurname nin sonuna null karakteri koyuyorum*/

			strcat(name,newsurname);/*basinda bosluk olan soyadini adin sonuna ekliyorum*/
									/*artik ad ile soyad name adli degiskende birlesti*/

			strcpy(people->data[people->size].name,name); /*struct yapisinindaki name e ad ve soyadi kopyaliyorum*/
														/* her yeni bir kiside isim ve soyisim degistigi icin*/
														/*data arrayinin people->size inci indisine kopyaliyorum*/
				
			people->data[people->size].id=id; /*struct yapisinindaki id ye fscanfle aldigim id yi atiyorum*/
											/* her yeni bir kiside id degistigi icin*/
											/*data arrayinin people->size inci indisine kopyaliyorum*/
			people->size++; /*bu dongu bittiginde kisi sayisi artmis demektir bu yuzden people->size i arttiriyorum*/

		}	 	

	fclose(f); /*dosyayi kapatiyorum*/

}


