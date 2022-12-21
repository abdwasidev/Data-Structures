#include <iostream>

int divide(int a, int b){
	if (a < b) {
		return 0;
	} else {
		return 1 + divide(a - b, b);
	}
}
	
void close(){
	exit(0);
}

int main(){
	system("cls");

	char kembali;
	int i, a, b, result;
	
	while(1){
		system("cls");
		printf(" =======================================\n");
		printf(" =======================================\n");
		printf(" == PROGRAM REKURSIF ===================\n");
		printf(" =======================================\n");
		printf(" == ABDUL WASI\' AL-AFIF ================\n");
		printf(" == ( 20081010165 ) ====================\n");
		printf(" =======================================\n");
		printf(" =======================================\n");

		printf("\n MAIN MENU:");
		printf("\n [1]. Pembagian");
		printf("\n [2]. Keluar");
		printf("\n\n Input Pilihan Nomor Menu : ");
		scanf("%d", &i);
		switch(i){
			case 1:
				printf("\n");
				printf(" Bilangan Pertama: ");
				scanf("%d", &a);
				printf(" Bilangan Kedua: ");
				scanf("%d", &b);
				result = divide(a, b);
				printf(" Hasil pembagian %d / %d adalah %d", a, b, result);
				printf("\n\n");
			break;
			case 2:
				printf("\n");
				close();
				printf("\n\n");
			break;
			default:printf("\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!");
			break;		}

		printf(" =====================================\n");
		printf(" Ingin kembali ke menu pilihan? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);

	}

	return 0;
}
