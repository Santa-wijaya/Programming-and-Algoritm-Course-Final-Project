#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipe UI
void display();
void dashboardAdmin();
void userdisplay();

// Prototipe fungsi menu utama
void admin();
void pembeli();

// Prototipe fungsi admin Ticket
void scanTicket(int);
void lihatTicket();
int cekData_Pembeli();

// Prototipe fungsi pembeli ticket
int hitungTiketReguler();
int hitungTiketPremium();
void hapusReguler();
void hapusPremium();

// Prototipe Clear Screen
void clear();

//---------------
// Fungsi Utama
//---------------
int main() 
{
	int menu, status = 1, ulang;

	while (status) {
		clear();
    display();
		printf("-------------------- Main Menu --------------------\n");
		printf("[1] Masuk Admin | \033[0;32m[2] Beli Tiket \033[0m | "
			   "\033[0;31m[3] keluar \033[0m\n");
		printf("---------------------------------------------------\n");
		puts("");
		printf("Pilih Menu\t: ");
		scanf("%d", &menu);
		getchar();

		switch (menu) {
		case 1:
			admin();
			break;

		case 2:
			pembeli();
			break;

		case 3:
    printf("\nTERIMA KASIH.\n");
			return 0;
			break;
		}
		printf("\n\nApakah ingin kembali ke menu utama ? [1/0]: ");
		scanf("%d", &ulang);
		getchar();

		if (ulang == 1)
			status = 1;
		else
			status = 0;
	}
  printf("\nTERIMA KASIH.\n");
}

void admin() {
	int menu, status = 1, ulang, total;
	int hasil1, hasil2;
	char namaAdmin[20];
	char passwordAdmin[20];
	char admin[] = "123";
	char pass[] = "123";

	// Variabel Untuk Scan
	int cek;

	printf("\nMasukan Username : ");
	scanf("%[^\n]", namaAdmin);
	getchar();

	printf("Masukan Password : ");
	scanf("%[^\n]", passwordAdmin);
	getchar();

	hasil1 = strcmp(namaAdmin, admin);
	hasil2 = strcmp(passwordAdmin, pass);

	total = hasil1 + hasil2;

	if (total == 0) {
		while (status) {
			clear();
      dashboardAdmin();
			printf("(1). Scan Tiket\n");
			printf("(2). Lihat Data Ticket\n");
			printf("(3). Kembali ke menu utama\n");
			printf("\nPilih Menu\t: ");
			scanf("%d", &menu);
			getchar();

			switch (menu) {
			case 1:
				printf("\nCek Ke-Validan Tiket\n");
				printf("[1] Cek Premium\n");
				printf("[2] Cek Reguler\n");
        printf("\nPilihan : ");
				scanf("%d", &cek);
        getchar();

				scanTicket(cek);
				break;

			case 2:
				lihatTicket();
				break;

			case 3:
				return;
				break;

			default:
				printf("\nTidak ada pilihan...\n");
				break;
			}

			printf("\nApakah ingin mengulang ?");
			printf("\nTekan 1 jika iya, tekan 0 jika tidak");
			printf("\npilihan : ");
			scanf("%d", &ulang);
			getchar();

			if (ulang == 1)
				status = 1;
			else
				status = 0;
		}

	} else {
		printf("Usename dan Password tidak valid...");
	}
}

void pembeli() {
	int menu, tiket, harga1, harga2, total, umur,
		reguler = -1, premium = -1, status = 1, lagi, a = 0, a1 = 0, b = 0,
		b1 = 0;
	char nama[50];
	char pil;

	// Pointer File Data Pembeli
	FILE *tunjuk;

	// Pointer File, Variabel Reguler dan Premium
	// Reguler
	FILE *rgl;
	char tempR[20];
	// Premium
	FILE *prm;
	char tempP[20];

	tunjuk = fopen("Data Pembeli.txt", "a+");

	system("cls");
	printf("Masukkan Nama : ");
	scanf("%[^\n]", nama);
	printf("Masukkan Umur : ");
	scanf("%d", &umur);

	fprintf(tunjuk, "#-----#\n");
	fprintf(tunjuk, "Nama Pembeli  : %s\n", nama);
	fprintf(tunjuk, "Umur Pembeli  : %d\n", umur);
  fprintf(tunjuk, "\nDAFTAR TIKET\n");

	fclose(tunjuk);

	while (status) {
		clear();
    userdisplay();
		printf("\nDaftar Harga Tiket\n");
		printf(
			"[1] \033[0;34m Reguler - 50k Tersisa %d lembar \033[0m\n",
			hitungTiketReguler());
		printf(
			"[2] \033[0;36m Premium - 100k Tersisa %d lembar \033[0m\n\n", hitungTiketPremium());
		printf("Masukkan Kelas tiket yang ingin dibeli : ");
		scanf("%d", &tiket);
		getchar();

		if (tiket == 1) {
			if (hitungTiketReguler() == 0)
				printf("\nmohon maaf tiket sudah habis...\n");
			else {
				harga1 = 50000;
				a++;
				a1++;

				rgl = fopen("reguler.txt", "r");
				tunjuk = fopen("Data Pembeli.txt", "a");

				fgets(tempR, sizeof(tempR), rgl);

				printf("\nTIKET REGULER");
				printf("\nNama : %s", nama);
				printf("\nNomer Tiket : %s",tempR);
        printf("\nMasa Berlaku : 26/05/2021 [21:00]");

				fprintf(tunjuk,"Nomer Tiket   : %s",tempR);
        fprintf(tunjuk,"Masa Berlaku  : 26/05/2021 [21:00]");
        fprintf(tunjuk,"\n\n");

				fclose(rgl);
				fclose(tunjuk);

				if (a1++)
					hapusReguler();
			}
		}
		if (tiket == 2) {
			if (hitungTiketPremium() == 0)
				printf("\nmohon maaf tiket sudah habis\n");
			else {
				harga2 = 100000;
				b++;
				b1++;

				prm = fopen("premium.txt", "r");
				tunjuk = fopen("Data Pembeli.txt", "a");

				fgets(tempP, sizeof(tempP), prm);

				printf("\nTIKET PREMIUM\n");
				printf("\nNama: %s", nama);
				printf("\nNomer Tiket: %s", tempP);
        printf("\nMasa Berlaku : 26/05/2021 [21:00]");

				fprintf(tunjuk,"Nomer Tiket   : %s",tempP);
        fprintf(tunjuk,"Masa Berlaku  : 26/05/2021 [21:00]");
        fprintf(tunjuk,"\n\n");

				fclose(prm);
				fclose(tunjuk);

				if (b1++)
					hapusPremium();
			}
		}

		printf("\n\nApakah ada Transaksi lain [1/0] ? : ");
		scanf("%d", &lagi);
		if (lagi == 1)
			status = 1;
		if (lagi == 0)
			status = 0;
	}

	total = (a * harga1) + (b * harga2);
	printf("\n\nTotal harga harus dibayar sebanyak : Rp %d ", total);
}

// ---------------------
// Fungsi sebagai admin
// ---------------------
void scanTicket(int x)
{
	char kode[100];
	char buffer[100];
	printf("\nInput Kode : ");
	scanf("%s",kode);
  getchar();

  FILE *scn;

	if (x == 1) {
		scn = fopen("premiumAdmin.txt","r");

	} else {
		scn = fopen("regulerAdmin.txt","r");
	}

int comp = 1;

	while (!feof(scn))
  {
    fscanf(scn,"%s\n",&buffer);
    comp = comp * strcmp(kode,buffer);
  }

  if (comp == 0){
    printf("\n\nTicket [ %s ] Valid sampai 26/05/2021 [21:00]\n",kode);
  } else {
    printf("\n\nTicket Tidak Valid\n");
  }

  fclose(scn);
}

void lihatTicket() 
{

	FILE *bantu;
	bantu = fopen("Data Pembeli.txt","r");

	char buffer[100];

  if(fgets(buffer,sizeof(buffer),bantu)==NULL)
  {
    printf("Data Pembeli Kosong\n");

  }else{

    printf("\n%s",buffer);
    while(!feof(bantu))
    {
      fgets(buffer,sizeof(buffer),bantu);
      printf("%s",buffer);
    }
  }

	fclose(bantu);
}

// ----------------------
// Fungsi sebagai pembeli
// ----------------------

int hitungTiketReguler() {
	// Variabel
	int baris = 1;
	char buff[50];
	FILE *tunjuk1;

	tunjuk1 = fopen("reguler.txt", "r");

	while (fgets(buff, sizeof(buff), tunjuk1) != NULL) {
		baris++;
	}
	fclose(tunjuk1);

	return baris - 1;
}

int hitungTiketPremium() {
	// Variabel
	int baris = 1;
	char buff[50];
	FILE *tunjuk1;

	tunjuk1 = fopen("premium.txt", "r");

	while (fgets(buff, sizeof(buff), tunjuk1) != NULL) {
		baris++;
	}
	fclose(tunjuk1);

	return baris - 1;
}

void hapusReguler() {
	char filename[] = "reguler.txt";
	char temp[20];

	FILE *rgl1;
	FILE *rgl2;

	int del = 1;
	int line = 0;

	rgl1 = fopen(filename, "r");
	rgl2 = fopen("dum.txt", "w");

	while (fgets(temp, sizeof(temp), rgl1) != NULL) {
		line++;

		if (line != del)
			fputs(temp, rgl2);
	}
	fclose(rgl1);
	fclose(rgl2);

	remove(filename);
	rename("dum.txt", filename);
}

void hapusPremium() {
	char filename[] = "premium.txt";
	char temp[20];

	FILE *prm1;
	FILE *prm2;

	int del = 1;
	int line = 0;

	prm1 = fopen(filename, "r");
	prm2 = fopen("dum.txt", "w");

	while (fgets(temp, sizeof(temp), prm1) != NULL) {
		line++;

		if (line != del)
			fputs(temp, prm2);
	}
	fclose(prm1);
	fclose(prm2);

	remove(filename);
	rename("dum.txt", filename);
}

//-------------
// Fungsi Lain
//-------------

void clear()
{
    #ifdef _WIN32
        std : system("cls");
    #else
        std : system("clear");
    #endif
}

void display() {
	puts("");
	printf("===================================================\n");
	printf("=                                                 =\n");
	printf("=      \033[0;33m       Program Tiket Pengunjung \033[0m           "
		   "=\n");
	printf("=                                                 =\n");
	printf("===================================================\n");
	puts("");
}

void dashboardAdmin() {
	puts("");
	printf("===================================================\n");
	printf("=                                                 =\n");
	printf("=               \033[0;33m Dashboard Admin \033[0m""                 =\n");
	printf("=                                                 =\n");
	printf("===================================================\n");
	puts("");
}
void userdisplay(){
  puts("");
	printf("===================================================\n");
	printf("=                                                 =\n");
	printf("=               \033[0;33m Dashboard User \033[0m""                  =\n");
	printf("=                                                 =\n");
	printf("===================================================\n");
	puts("");
}