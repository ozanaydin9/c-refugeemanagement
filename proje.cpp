#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>

//Kullanici

struct Kullanici
{
 int tc;
 char *ad;
 char *soyad;
 char *tel;
 char *adres;
 char *eposta;
 char *kullanici_adi;
 char *sifre;
 char *yetki_turu;
};

Kullanici klavyeden_kullanici_oku(){

	Kullanici u;
	printf("Lutfen bilgileri sirasiyla girip Enter tusuna basiniz.\n");
	printf("TC            :");
	scanf("%d",&u.tc);


	printf("Ad            :");
	scanf("%s",&u.ad);
		
	printf("Soyad         :");
	scanf("%s",&u.soyad);
	
	printf("Telefon       :");
	scanf("%s",&u.tel);
	
	printf("Adres         :");
	scanf("%s",&u.adres);
	
	printf("E-Posta       :");
	scanf("%s",&u.eposta);
	
	printf("Kullanici Adi :");
	scanf("%s",&u.kullanici_adi);
	
	printf("Sifre         :");
	scanf("%s",&u.sifre);
	
	printf("Yetki Turu    :");
	scanf("%s",&u.yetki_turu);
	
	printf("\n");
	
	return u;
}

void kullanici_ekle(Kullanici user){
	FILE *dosya;
	dosya=fopen("kullanicilar.txt","a+");
	if (dosya == NULL){
		printf("Hata : Dosya bulunamadý.\n");		
	}
	else
	{ 
		fprintf(dosya,"\n%d %s %s %s %s %s %s %s %s", user.tc,&user.ad,&user.soyad,&user.tel,&user.adres,&user.eposta,&user.kullanici_adi,&user.sifre,&user.yetki_turu);
		fclose(dosya);
	}
}

void kullanici_listele(){
	FILE *dosya; 
	char *karakter;

	if ((dosya=fopen("kullanicilar.txt","r")) == NULL){
		printf("Hata : Dosya bulunamadý.\n");	
	}  
	else 
	{ 
		int i=1;
		int sira=1;
		while (!feof(dosya)){
			Kullanici user;
			if(i==1){
				printf("############ %d. kayit ########################\n",sira);
				sira++;
			}
			
			printf("%d. ",i);
		
			switch(i){
				case 1:fscanf(dosya, "%d", &user.tc);printf("TC            : %d \n", user.tc);break;
				case 2:fscanf(dosya, "%s", &user.ad);printf("Ad            : %s \n", &user.ad);break;
				case 3:fscanf(dosya, "%s", &user.soyad);printf("Soyad         : %s \n", &user.soyad);break;
				case 4:fscanf(dosya, "%s", &user.tel);printf("Telefon       : %s \n", &user.tel);break;
				case 5:fscanf(dosya, "%s", &user.adres);printf("Adres         : %s \n", &user.adres);break;
				case 6:fscanf(dosya, "%s", &user.eposta);printf("E-Posta       : %s \n", &user.eposta);break;
				case 7:fscanf(dosya, "%s", &user.kullanici_adi);printf("Kullanici Adi : %s \n", &user.kullanici_adi);break;
				case 8:fscanf(dosya, "%s", &user.sifre);printf("Sifre         : %s \n", &user.sifre);break;
				case 9:fscanf(dosya, "%s", &user.yetki_turu);printf("Yetki Turu    : %s \n", &user.yetki_turu);break;
				default:break;
			}
		
			if(i==9){
				printf("############ %d. kayit ########################\n",sira-1);
				printf("\n \n \n");
				i=1;
			}else{
		    	i++;
			}
			
			
			
		}
			 
	    fclose(dosya); 
	}
}

void kullanici_guncelle(){
	printf("Guncelleme menusune hosgeldiniz, lutfen bir tusa basin ve kullanicilari gorun. \nDaha sonra guncellemek istediginiz kaydi secin.");
	printf("\n\n Devam etmek icin bir tusa basin.");
	getchar();
	kullanici_listele();	
	printf("\n Lutfen guncellemek istediginiz kayit numarasini secin: ");
	int guncellemeno;
	scanf("%d",&guncellemeno);
	
	Kullanici yeniuser=klavyeden_kullanici_oku();
	
	FILE *dosya; 
	FILE *dosya2;
	char *karakter;


	if ((dosya=fopen("kullanicilar.txt","r")) == NULL){
		printf("Hata : Dosya bulunamadý.\n");	
	}  
	else 
	{ 
		int i=1;
		int sira=0;
		while (!feof(dosya)){
			
			Kullanici user;
			if(i==1){
				sira++;
			}
	
		
			switch(i){
				case 1:fscanf(dosya, "%d", &user.tc);break;
				case 2:fscanf(dosya, "%s", &user.ad);break;
				case 3:fscanf(dosya, "%s", &user.soyad);break;
				case 4:fscanf(dosya, "%s", &user.tel);break;
				case 5:fscanf(dosya, "%s", &user.adres);break;
				case 6:fscanf(dosya, "%s", &user.eposta);break;
				case 7:fscanf(dosya, "%s", &user.kullanici_adi);break;
				case 8:fscanf(dosya, "%s", &user.sifre);break;
				case 9:fscanf(dosya, "%s", &user.yetki_turu);break;
				default:break;
			}
			
			if(i==9){
				i=1;
				
				if(sira!=guncellemeno){
					dosya2=fopen("kullanicilar2.txt","a+");
					fprintf(dosya2,"\n%d %s %s %s %s %s %s %s %s", user.tc,&user.ad,&user.soyad,&user.tel,&user.adres,&user.eposta,&user.kullanici_adi,&user.sifre,&user.yetki_turu);
					fclose(dosya2);

				}else{
					dosya2=fopen("kullanicilar2.txt","a+");
					fprintf(dosya2,"\n%d %s %s %s %s %s %s %s %s", yeniuser.tc,&yeniuser.ad,&yeniuser.soyad,&yeniuser.tel,&yeniuser.adres,&yeniuser.eposta,&yeniuser.kullanici_adi,&yeniuser.sifre,&yeniuser.yetki_turu);
					fclose(dosya2);
				}
				
			}else{
		    	i++;
			}

		}
			 
	    fclose(dosya); 
	    
	    remove("kullanicilar.txt");
		rename("kullanicilar2.txt","kullanicilar.txt");
	}
}

void kullanici_sil(){
	
	
	printf("Silme menusune hosgeldiniz, lutfen bir tusa basin ve kullanicilari gorun. \nDaha sonra silmek istediginiz kaydi secin.");
	printf("\n\n Devam etmek icin bir tusa basin.");
	getchar();
	kullanici_listele();	
	printf("\n Lutfen silmek istediginiz kayit numarasini secin: ");
	int silmeno;
	scanf("%d",&silmeno);
	
	FILE *dosya; 
	FILE *dosya2;
	char *karakter;


	if ((dosya=fopen("kullanicilar.txt","r")) == NULL){
		printf("Hata : Dosya bulunamadý.\n");	
	}  
	else 
	{ 
		int i=1;
		int sira=0;
		while (!feof(dosya)){
			
			Kullanici user;
			if(i==1){
				sira++;
			}

			switch(i){
				case 1:fscanf(dosya, "%d", &user.tc);break;
				case 2:fscanf(dosya, "%s", &user.ad);break;
				case 3:fscanf(dosya, "%s", &user.soyad);break;
				case 4:fscanf(dosya, "%s", &user.tel);break;
				case 5:fscanf(dosya, "%s", &user.adres);break;
				case 6:fscanf(dosya, "%s", &user.eposta);break;
				case 7:fscanf(dosya, "%s", &user.kullanici_adi);break;
				case 8:fscanf(dosya, "%s", &user.sifre);break;
				case 9:fscanf(dosya, "%s", &user.yetki_turu);break;
				default:break;
			}
			
			if(i==9){
				i=1;
				
				if(sira!=silmeno){
					dosya2=fopen("kullanicilar2.txt","a+");
					fprintf(dosya2,"\n%d %s %s %s %s %s %s %s %s", user.tc,&user.ad,&user.soyad,&user.tel,&user.adres,&user.eposta,&user.kullanici_adi,&user.sifre,&user.yetki_turu);
					fclose(dosya2);

				}
				
			}else{
		    	i++;
			}
			
		}
			 
	    fclose(dosya); 
	    
	    remove("kullanicilar.txt");
		rename("kullanicilar2.txt","kullanicilar.txt");
	}

	
	
}

//Siginmaci

struct siginmaci
{
 char *ad;
 char *soyad;
 char *dogumtarihi;
 char *dogumyeri;
 char *cinsiyet;
 char *uyruk;
 char *meslek;
 char *egitim_durumu;
 char *telefon;
 char *yerlestrildigi_adres;
 char *geldigi_sehir;
 char *gelis_tarihi;
 char *eposta;
};

siginmaci klavyeden_siginmaci_oku(){

	siginmaci u;
	printf("Lutfen bilgileri sirasiyla girip Enter tusuna basiniz.\n");
	printf("Siginmaci adi  :");
	scanf("%s",&u.ad);
	
	printf("Soyadi        :");
	scanf("%s",&u.soyad);
	
	printf("Dogum tarihi   :");
	scanf("%s",&u.dogumtarihi);
	
	printf("Dogum yeri    :");
	scanf("%s",&u.dogumyeri);
	
	printf("Cinsiyet     :");
	scanf("%s",&u.cinsiyet);
	
	printf("Uyruk       :");
	scanf("%s",&u.uyruk);
	
	printf("Meslek        :");
	scanf("%s",&u.meslek);
	
	printf("Egitim Durumu  :");
	scanf("%s",&u.egitim_durumu);
	
	printf("Telefon    :");
	scanf("%s",&u.telefon);
	
	printf("Yerlestirildigi adres:");
	scanf("%s",&u.yerlestrildigi_adres);

	printf("Gelis tarihi    :");
	scanf("%s",&u.gelis_tarihi);
	
	printf("E-posta    :");
	scanf("%s",&u.eposta);
	
	
	
	printf("\n");
	
	return u;
}

void siginmaci_ekle(siginmaci user){
	FILE *dosya;
	dosya=fopen("siginmacilar.txt","a+");
	if (dosya == NULL){
		printf("Hata : Dosya bulunamadý.\n");		
	}
	else
	{ 
		fprintf(dosya,"\n%s %s %s %s %s %s %s %s %s %s %s %s",&user.ad,&user.soyad,&user.dogumtarihi,&user.dogumyeri,&user.cinsiyet,&user.uyruk,&user.meslek,&user.egitim_durumu,&user.telefon,&user.yerlestrildigi_adres,&user.gelis_tarihi,&user.eposta);
		fclose(dosya);
	}
}

void siginmaci_listele(){
	FILE *dosya; 
	char *karakter;

	if ((dosya=fopen("siginmacilar.txt","r")) == NULL){
		printf("Hata : Dosya bulunamadý.\n");	
	}  
	else 
	{ 
		int i=1;
		int sira=1;
		while (!feof(dosya)){
			siginmaci user;
			if(i==1){
				printf("############ %d. kayit ########################\n",sira);
				sira++;
			}
			
			printf("%d. ",i);
		
			switch(i){
				case 1:fscanf(dosya, "%s", &user.ad);printf("Ad            : %s \n", &user.ad);break;
				case 2:fscanf(dosya, "%s", &user.soyad);printf("Soyad            : %s \n", &user.soyad);break;
				case 3:fscanf(dosya, "%s", &user.dogumtarihi);printf("Dogum Tarihi        : %s \n", &user.dogumtarihi);break;
				case 4:fscanf(dosya, "%s", &user.dogumyeri);printf("Dogum Yeri       : %s \n", &user.dogumyeri);break;
				case 5:fscanf(dosya, "%s", &user.cinsiyet);printf("Cinsiyet         : %s \n", &user.cinsiyet);break;
				case 6:fscanf(dosya, "%s", &user.uyruk);printf("Uyruk       : %s \n", &user.uyruk);break;
				case 7:fscanf(dosya, "%s", &user.meslek);printf("Meslek     : %s \n", &user.meslek);break;
				case 8:fscanf(dosya, "%s", &user.egitim_durumu);printf("Egitim Durumu     : %s \n", &user.egitim_durumu);break;
				case 9:fscanf(dosya, "%s", &user.telefon);printf("Telefon    : %s \n", &user.telefon);break;
				case 10:fscanf(dosya, "%s", &user.yerlestrildigi_adres);printf("Yerleþtirildigi Adres  : %s \n", &user.yerlestrildigi_adres);break;
				case 11:fscanf(dosya, "%s", &user.gelis_tarihi);printf("Gelis Tarihi     : %s \n", &user.gelis_tarihi);break;
				case 12:fscanf(dosya, "%s", &user.eposta);printf("Adres    : %s \n", &user.eposta);break;
				default:break;
			
			}
		
			if(i==12){
				printf("############ %d. kayit ########################\n",sira-1);
				printf("\n \n \n");
				i=1;
			}else{
		    	i++;
			}
			
			
			
		}
			 
	    fclose(dosya); 
	}
}

void siginmaci_guncelle(){
	printf("Guncelleme menusune hosgeldiniz, lutfen bir tusa basin ve siginmacilari gorun. \nDaha sonra guncellemek istediginiz kaydi secin.");
	printf("\n\n Devam etmek icin bir tusa basin.");
	getchar();
	siginmaci_listele();	
	printf("\n Lutfen guncellemek istediginiz kayit numarasini secin: ");
	int guncellemeno;
	scanf("%d",&guncellemeno);
	
	siginmaci yeniuser=klavyeden_siginmaci_oku();
	
	FILE *dosya; 
	FILE *dosya2;
	char *karakter;


	if ((dosya=fopen("siginmacilar.txt","r")) == NULL){
		printf("Hata : Dosya bulunamadý.\n");	
	}  
	else 
	{ 
		int i=1;
		int sira=0;
		while (!feof(dosya)){
			
			siginmaci user;
			if(i==1){
				sira++;
			}
	
		
			switch(i){
				case 1:fscanf(dosya, "%s", &user.ad);break;
				case 2:fscanf(dosya, "%s", &user.soyad);break;
				case 3:fscanf(dosya, "%s", &user.dogumtarihi);break;
				case 4:fscanf(dosya, "%s", &user.dogumyeri);break;
				case 5:fscanf(dosya, "%s", &user.cinsiyet);break;
				case 6:fscanf(dosya, "%s", &user.uyruk);break;
				case 7:fscanf(dosya, "%s", &user.meslek);break;
				case 8:fscanf(dosya, "%s", &user.egitim_durumu);break;
				case 9:fscanf(dosya, "%s", &user.telefon);break;
				case 10:fscanf(dosya, "%s", &user.yerlestrildigi_adres);break;
				case 11:fscanf(dosya, "%s", &user.gelis_tarihi);break;
				case 12:fscanf(dosya, "%s", &user.eposta);break;
				default:break;
			}
			
			if(i==12){
				i=1;
				
				if(sira!=guncellemeno){
					dosya2=fopen("siginmacilar2.txt","a+");
					fprintf(dosya2,"\n%s %s %s %s %s %s %s %s %s %s %s %s",&user.ad,&user.soyad,&user.dogumtarihi,&user.dogumyeri,&user.cinsiyet,&user.uyruk,&user.meslek,&user.egitim_durumu,&user.telefon,&user.yerlestrildigi_adres,&user.gelis_tarihi,&user.eposta);
					fclose(dosya2);

				}else{
					dosya2=fopen("siginmacilar2.txt","a+");
					fprintf(dosya2,"\n%s %s %s %s %s %s %s %s %s %s %s %s",&yeniuser.ad,&yeniuser.soyad,&yeniuser.dogumtarihi,&yeniuser.dogumyeri,&yeniuser.cinsiyet,&yeniuser.uyruk,&yeniuser.meslek,&yeniuser.egitim_durumu,&yeniuser.telefon,&yeniuser.yerlestrildigi_adres,&yeniuser.gelis_tarihi,&yeniuser.eposta);
					fclose(dosya2);
				}
				
			}else{
		    	i++;
			}

		}
			 
	    fclose(dosya); 
	    
	    remove("siginmacilar.txt");
		rename("siginmacilar2.txt","siginmacilar.txt");
	}
}
	
void siginmaci_sil(){
	
printf("Silme menusune hosgeldiniz, lutfen bir tusa basin ve siginmacilari gorun. \nDaha sonra silmek istediginiz kaydi secin.");
	printf("\n\n Devam etmek icin bir tusa basin.");
	getchar();
	siginmaci_listele();	
	printf("\n Lutfen silmek istediginiz kayit numarasini secin: ");
	int silmeno;
	scanf("%d",&silmeno);
	
	
	FILE *dosya; 
	FILE *dosya2;
	char *karakter;


	if ((dosya=fopen("siginmacilar.txt","r")) == NULL){
		printf("Hata : Dosya bulunamadý.\n");	
	}  
	else 
	{ 
		int i=1;
		int sira=0;
		while (!feof(dosya)){
			
			siginmaci user;
			if(i==1){
				sira++;
			}
	
		
			switch(i){
				case 1:fscanf(dosya, "%s", &user.ad);break;
				case 2:fscanf(dosya, "%s", &user.soyad);break;
				case 3:fscanf(dosya, "%s", &user.dogumtarihi);break;
				case 4:fscanf(dosya, "%s", &user.dogumyeri);break;
				case 5:fscanf(dosya, "%s", &user.cinsiyet);break;
				case 6:fscanf(dosya, "%s", &user.uyruk);break;
				case 7:fscanf(dosya, "%s", &user.meslek);break;
				case 8:fscanf(dosya, "%s", &user.egitim_durumu);break;
				case 9:fscanf(dosya, "%s", &user.telefon);break;
				case 10:fscanf(dosya, "%s", &user.yerlestrildigi_adres);break;
				case 11:fscanf(dosya, "%s", &user.gelis_tarihi);break;
				case 12:fscanf(dosya, "%s", &user.eposta);break;
				default:break;
			}
			
			if(i==12){
				i=1;
				
				if(sira!=silmeno){
					dosya2=fopen("siginmacilar2.txt","a+");
					fprintf(dosya2,"\n%s %s %s %s %s %s %s %s %s %s %s %s",&user.ad,&user.soyad,&user.dogumtarihi,&user.dogumyeri,&user.cinsiyet,&user.uyruk,&user.meslek,&user.egitim_durumu,&user.telefon,&user.yerlestrildigi_adres,&user.gelis_tarihi,&user.eposta);
					fclose(dosya2);

				}
				
			}else{
		    	i++;
			}

		}
			 
	    fclose(dosya); 
	    
	    remove("siginmacilar.txt");
		rename("siginmacilar2.txt","siginmacilar.txt");
	}

	
	
}

//----------------------------
void menu(){
	
	int secim;
	int secim2;
	int tekrar;
	int tekrar2;
	int sifre;
	do{
		tekrar=0;
		printf("\nYetkinizi seciniz \n 1-Admin \n 2-Kullanici Memuru \n 3-Kullanici \n 0-Cikis\n:");
		scanf("%d", &secim);
		
		if(secim==1){
			printf("Sifre giriniz: ");
			scanf("%d" ,&sifre);
			if(sifre==1){
				printf("Giris basarili!\n");
				
				int tekrar2=0;
				do{
					tekrar2=1;
					printf("1.Kullanici Ekle\n2.Kullanici Listele\n3.Kullanici Guncelle \n4.Kullanici Sil\n5.Siginmaci Ekle\n6.Siginmaci Listele\n7.Siginmaci Guncelle\n8.Siginmaci Sil\n0.Cikis");
					printf("\nSeciminiz: ");
					scanf("%d" ,&secim2);
					if(secim2==0){
						break;
					}else if(secim2<0){
						tekrar2=1;
					}else if(secim2>8){
						tekrar2=1;
					}else{
						

						switch(secim2){
							case 1: {
								system("cls");
								Kullanici user=klavyeden_kullanici_oku();
								kullanici_ekle(user);
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 2: 
							{
								system("cls");
								kullanici_listele();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 3: 
							{
								system("cls");
								kullanici_guncelle();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							
							break;
							
							case 4: 
							{
								system("cls");
								kullanici_sil();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 5: 
							{
								system("cls");
								siginmaci user=klavyeden_siginmaci_oku();
								siginmaci_ekle(user);
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 6: 
							{
								system("cls");
								siginmaci_listele();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 7: 
							{
								system("cls");
								siginmaci_guncelle();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 8: 
							{
							system("cls");
							siginmaci_sil();
							printf("\nDevam etmek icin bir tusa basin.");
							getch();
							system("cls");
							}
							break;
							
					
						}
						
					}
					
				}while(tekrar2==1);
				

				
				
			}else{
				printf("Yanlis sifre! Program sonlandiriliyor! \n");
				break;
			}
			
		}else if(secim==2){
			
			printf("Sifre giriniz: ");
			scanf("%d" ,&sifre);
			if(sifre==1){
				printf("Giris basarili!\n");
				
				int tekrar2=0;
				do{
					tekrar2=1;
					printf("\n1.Siginmaci Ekle\n2.Siginmaci Listele\n3.Siginmaci Guncelle\n4.Siginmaci Sil\n0.Cikis");
					printf("\nSeciminiz: ");
					scanf("%d" ,&secim2);
					if(secim2==0){
						break;
					}else if(secim2<0){
						tekrar2=1;
					}else if(secim2>4){
						tekrar2=1;
					}else{
						

						switch(secim2){
							case 1: 
							{
								system("cls");
								siginmaci user=klavyeden_siginmaci_oku();
								siginmaci_ekle(user);
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 2: 
							{
								system("cls");
								siginmaci_listele();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 3: 
							{
								system("cls");
								siginmaci_guncelle();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
							case 4: 
							{
								system("cls");
								siginmaci_sil();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
						
						
						}
						
					}
					
				}while(tekrar2==1);
				

				
				
			}else{
				printf("Yanlis sifre! Program sonlandiriliyor! \n");
				break;
			}
			
			
			
		}else if(secim==3){


				int tekrar2=0;
				do{
					tekrar2=1;
					printf("\n1.Siginmaci Listele\n2.Kullanici Listele\n0.Cikis");
					printf("\nSeciminiz: ");
					scanf("%d" ,&secim2);
					if(secim2==0){
						break;
					}else if(secim2<0){
						tekrar2=1;
					}else if(secim2>2){
						tekrar2=1;
					}else{
						

						switch(secim2){	
							case 1: 
							{
								system("cls");
								siginmaci_listele();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							case 2: 
							{
								system("cls");
								kullanici_listele();
								printf("\nDevam etmek icin bir tusa basin.");
								getch();
								system("cls");
							}
							break;
							
						
						
						}
						
					}
					
				}while(tekrar2==1);
				

				
				
			
			
			
		}else if(secim==0){
			break;
		}else{
			printf("\nHatali girdi!\n");
			tekrar=1;
		}
		
		
	}while(tekrar==1);
	
	
	
	
}



int main()
{ 
menu();

//Kullanici u=klavyeden_kullanici_oku();

//kullanici_ekle(u);
//kullanici_listele();

//kullanici_guncelle();
//kullanici_sil();
//kullanici_arama("deneme");


//siginmaci u=klavyeden_siginmaci_oku();

//siginmaci_ekle(u);
//siginmaci_listele();
//siginmaci_guncelle();
//siginmaci_sil();

getchar();

return 0;
}



