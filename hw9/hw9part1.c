void writePeople(People people, char* filename) {
	
	FILE *f ;/*f adinda file pointer olusturuyorum*/
	int i = people.size; /*people size i, i degiskeninde tutuyorum*/	
	people.size=0; /*people size i 0 liyorum*/
	f= fopen(filename, "wb");/* dosyayi write binary modunda aciyorum*/	
	while(people.size<i) {/*people size i den kucukken*/
		fwrite(&people.data[people.size], sizeof(Person),1, f);/*people.data[people->size] indisini ,Person boyutunda,1 defa binary f dosyasina yaziyorum*/
		people.size++;/*people size i arttiriyorum.*/
	}
	fclose(f);/*dosyayi kapatiyorum*/
}

void readPeople(People *people, char* filename) {
	
	FILE *f; /*f adinda file pointer olusturuyorum*/
	int i = 0;/* i yi sifirdan baslatiyorum*/
	f=fopen(filename, "rb");/* dosyayi read binary modunda aciyorum*/
	people->size = 0;/*people size i 0 dan baslatiyorum*/

	while(fread(&people->data[i], sizeof(Person), 1, f)!=0){/*fread return degerine gore f dosyasinin sonuna kadar people->data[i] indisine Person boyutunda, 1 defa veri okunur*/
    	people->size++;/* people size 1 artar*/
    	i++;/*i bir artar*/
	}
	fclose(f); /*dosyayi kapatiyorum*/
}

void imputation(People *people){

    Record *head; /* linked listemin basini gosteren Record yapsinda pointer*/

	int i=0;/* gerekli degiskenleri tanimliyorum*/
	int j=0;
	int k=0;
	int t=0;
	int totalPhone=0;
	double totalEx=0;

	int *arr;/*0.ci indisten itibaren kacinci kisinin expenditure sinin -1 oldugu bilgisini tutar*/
	int *occur;/*expenditure si -1 olan bir kisinin kac tane telefonu oldugu bilgisini tutar*/
	
	arr=(int*)malloc(sizeof(int)*MAXRECORD);/* yukarda tanimladigim arrayler icin malloc ile yer ayirdim*/
	occur=(int*)malloc(sizeof(int)*MAXRECORD);

	for(j=0;j<people->size;j++){/*-1. kisi diye bir sey olamayacagi icin arr adli arrayin icini -1 ile doldurdum bu sekilde kolay kontrol etmis olacagim*/
		arr[j]=-1;
	}
	for(j=0;j<people->size;j++){/* herkezin en azindan bir tane telefonu olacagi icin occur arrayinin icini 0 ile doldurdum kontrolu kolay yapmak icin*/
		occur[j]=0;
	}

	for(i=0;i<people->size;i++){/* i 0 dan kisi sayisina kadar*/
		head = people->data[i].numbers;/*linked listemin basina i. inci kisinin telefon numaralarini atiyorum*/
		while(head != NULL) {/* linked listenin sonuna kadar*/
			if(people->data[i].expenditure!=-1){ /* eger expenditure i -1 degilse toplam telefon no sayisini 1 arttiriyorum*/
				totalPhone++;
			}
			else{ /* eger expenditure i -1 ise */
				arr[t]=i; /* o kisinin kacinci kisi oldugo bilgisini arr adli arrayimde tutuyorum*/
				occur[i]++;/* ve o kisi kacici kisiyse,occur arryindeki o indisin degerini bir attiriyorum ve o kisinin kac tane */
				k++;		/* telefonu oldugu bilgisini tutmus oluyorum*/
				t++;		/*k ve t yi arttiriyorum*/
			}
			head = head->next;/* listenin bir sonraki elemanina gecmek icin head e head in nexti ni atiyorum*/
		}
	    if(people->data[i].expenditure!=-1){ /* eger i inci kisinin expenditure i -1 degilse */
			totalEx=totalEx + people->data[i].expenditure;/* toplam expenditure ye i inci kisinin expenditure ini ekliyorum*/
		}
	}
	for(j=0;j<people->size;j++){ /* j 0 dan kisi sayisina kadar*/
		if(arr[j]!=-1){ /*eger arr arrayinin j inci indisi -1 degilse o indisde degisIklik olmustur demektir yani arr[j]. kisinin expenditure si -1 dir*/
			people->data[arr[j]].expenditure=(totalEx/totalPhone)*occur[arr[j]];/*ve occurun arr[j]. indisinde o kisinin kac tane telefonu oldugu bilgisi vardir*/
		}  /* expendituresi -1 olan kisinin expenditure tahmini yapmak icin yukardaki formulu kullandim*/
	}
	free(arr); /* arr ve occur arrayleriyle isim bitti artik fazla yer tutmamasi icin onlari free ediyorum*/
	free(occur);
}

void read(char* filename, People *people) {
	
	Record* head; /* linked listemin basini gosteren Record yapisindaki pointer*/
	FILE* f; /* file pointer*/

	int id,i,k,kactel,j,n;/* gerekli degiskenler*/
	double harcama;
	
	char *name; /* ad tutan array*/
	char *surname;/* soyad tutan array*/
	char *newsurname;/* basinda bosluk olan surname*/
	char *buffer;/* input dosyasindan cumle cumle okuma yapip o cumleyi buffer arrayine atmak icin*/
	int *kactelarr;/* bir kisinin kac tane telefonu oldugu bilgisini tutan array*/
	
	n=0;/* satir sayisini tutan degisken(kisi sayisi)*/
	kactel=0;/* bir kisinin kac tane telefonu oldugu bilgisini tutan degisken*/
	people->size=0;/* kisi sayisi*/

	f = fopen(filename, "r");/* dosyayi read modunda aciyorum*/

	buffer=(char*)malloc(sizeof(char)*(NAMELEN+MAXRECORD));/* buffer ve kactelarr icin her aliyorum*/

	kactelarr=(int*)malloc(sizeof(int)*MAXRECORD);

	while(fgets(buffer , MAXRECORD+NAMELEN , f)!=NULL){ /* dosya sonuna kadar input dosyasindan satir satir okuma yapip buffer a atiyorum*/
		for(j=0;buffer[j]!='\0';j++){/*buffer in icinde satir sonuna kadar bakiyorum*/
	   		if(buffer[j]==' '){/* her boslukta kactel adli variable imi 1 arttiriyorum*/
	   			kactel++;
	   		}
	   	}
	   	kactel=kactel -3; /* satirdaki ilk 3 bosuk numaralarla ilgili olmadigi icin toplam bosluk sayisindan 3 cikararak bir kisinin kac tane telefonu oldugunu buluyorum*/
		kactelarr[n]=kactel;/* n. kisinin kac tane telefonu oldugu bilgisini kactelarr adli arrayin n. indisinde tutuyorum*/
		kactel=0;/* kactel degiskenimi sifirliyorum*/
		n++;/* n i arttiriyorum(satir sayisi,kisi sayisi)*/
	}
	fseek(f,0,SEEK_SET);/*tekrar dosyanin basina gidiyorum*/
	name=(char*)malloc(sizeof(char)*NAMELEN);/* name ve surname arraylerim icin yer ayiriyorum*/
	surname=(char*)malloc(sizeof(char)*NAMELEN);

	while(fscanf(f,"%d %s %s %lf",&id,name,surname,&harcama) !=EOF){ /* dosya sonuna kadar id name surname ve harcama(expenditure) bilgilerini okuyoruz*/
		head=(Record*)malloc(sizeof(Record));/* numberlar icin linked list yapmaliyim bunun icin listenin basini gosteren head icin yer aldim*/
		fscanf(f,"%s",head->number);/* aldigim bu yerin numberina kisinin ilk numarasini attim*/
		head->id = id;/* aldigim bu yerin id sine okudugum id yi atadim*/
		people->data[people->size].numbers=head;/* head i people datasinin people size indisinin numberina atadim(yani kopyaladim) head i kaybetmemek icin*/
	
		for(i=0;kactelarr[people->size]-1>0;kactelarr[people->size]--,i++){  /* ilk numarayi yukarda aldigim icin kactelarrayinin icindeki kisinin numara sayisindan 1 cikardim, bu dongu tel. sayisi kadar donecek*/
			head->next = (Record*)malloc(sizeof(Record));/*once head in nexti icin yer aliyorum*/
			head->next->id = id;/* head in nextinin id sine okudugum id yi atiyorum*/
			fscanf(f,"%s",head ->next->number);/* sonrada head in nextinin numberina dosyadan okuma yapiyorum*/
			head ->next->next = NULL; /* headin nextinin nexti su anda olurmu olmazmi bilmedigim icin oraya NULL atadim*/
			head=head->next; /* listenin diger bolumlerine gidebilmek icin heade head in nexti ni atiyorum*/
		}

		people->data[people->size].expenditure=harcama; /* dosyadan okudugum harcama degiskenini people yapisinin datasinin people size inci indeksinin expenditure ina atiyorum*/

		newsurname=(char*)malloc(sizeof(char)*NAMELEN); /* newsurname adli array im icin malloc ile yer aliyorum*/

		newsurname[0]=' '; /* newsurname inin ilk indisine bosluk koyuyorum*/

		for(k=1;k<=strlen(surname);k++){ /* sonra surname adli arrayimi newsurname arrayimin bosluktan sonrasina atiyorum*/
			newsurname[k]=surname[k-1];
		}
		newsurname[k]='\0';/* newsurname arrayimin sonuna null atiyorum*/
		strcat(name,newsurname);/* ad ile basinda bosluk olan soyadini birlestiriyorum*/
		strcpy(people->data[people->size].name,name);  /* sonrasinda onu people in datasinin people size inci indisinin name ine kopyaliyorum*/
		people->data[people->size].id=id; /* id yi people in datasinin people size inci indisinin id sine atiyorum*/
		people->size++;
	}
	fclose(f); /* dosyayi kapatiyorum*/
	free(name);/* name, surname, kactelarr, buffer, newsurname adli arrayler ile isim bittigi icin onlari free ediyorum*/
	free(surname);
	free(kactelarr);
	free(buffer);
	free(newsurname);
}

