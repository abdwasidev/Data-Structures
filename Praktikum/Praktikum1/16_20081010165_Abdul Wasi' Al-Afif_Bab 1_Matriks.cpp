#include <iostream>
#include <bits/stdc++.h>
#include <string>

//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

using namespace std;

void intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                                 Program \"Matriks\"                             *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *************                        Abdul Wasi\' Al-Afif (20081010165)                      *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
}

int main() {
	int row, column, i, j, matriks[10][10], invers_matriks[10][10], determinan;
	string back;
	
	row = 3;
	column = 3;
	
	do {
		main:
			system("cls");
			intro();
			
			cout << "\n Matriks 3 x 3 dan Invers Matriks" << endl;
			
			cout << "\n Input Matriks" << endl;
			cout << " ==========================================" << endl;
			
			for (i = 0; i < row; i++){
				for (j = 0; j < column; j++){
					cout << " Input Matriks [" << i+1 << "]["<< j+1 << "]: ";
					cin >> matriks[i][j];
				}
			}
			
			cout << "\n Output Matriks" << endl;
			cout << " ==========================================" << endl;
			
			for (i = 0; i < row; i++){
				for (j = 0; j < column; j++){
					cout << " " << matriks[i][j];
			   }
			   cout << endl;
			}
			
			cout << "\n Determinan Matriks" << endl;
			cout << " ==========================================" << endl;
      		determinan = ((matriks[0][0] * matriks[1][1] * matriks[2][2]) + (matriks[0][1] * matriks[1][2] * matriks[2][0]) + (matriks[0][2] * matriks[1][0] * matriks[2][1])) - ((matriks[2][0] * matriks[1][1] * matriks[0][2]) + (matriks[2][1] * matriks[1][2] * matriks[0][0]) + (matriks[2][2] * matriks[1][0] * matriks[0][1]));

			cout << " Determinan Matriks = " << determinan << endl;
			
			if(determinan != 0){
				cout << "\n Invers Matriks" << endl;
				cout << " ==========================================" << endl;
				
				for(i = 0; i < row; i++){
					for(j = 0; j < column; j++){
						cout<< " " << ((matriks[(i+1)%3][(j+1)%3] * matriks[(i+2)%3][(j+2)%3]) - (matriks[(i+1)%3][(j+2)%3]* matriks[(i+2)%3][(j+1)%3])) / determinan << " ";
					}
					cout << endl;
				}
		    } else {
		        cout<<"\n Tidak ada invers karena determinan matriks bernilai 0" << endl;
		    }
		
		printf("\n Input matriks ulang? (Y/T): ");
		cin >> back;

	} while (back == "y" || back == "Y");
	
    return 0;
}
