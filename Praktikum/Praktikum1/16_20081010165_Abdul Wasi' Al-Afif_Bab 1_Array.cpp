#include <iostream>
#include <bits/stdc++.h>
#include <string>

//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

using namespace std;

void intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                                Program \"Array\"                                *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *************                        Abdul Wasi\' Al-Afif (20081010165)                      *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
}

int main() {
	int i, j, k, n, x, num, mean, median, modus, sum, arrayData[10], total[10];
	string back;
	
	k = 1;
	n = 10;
	x = 0;
	
	do {
		main:
			system("cls");
			intro();
			cout << "\n Operasi Array [Mean, Medianm, Modus]" << endl;
			
			cout << "\n Input array" << endl;
			cout << " ==========================================" << endl;
			
			for (i = 0; i < n; i++){
				cout << " Input array ke-" << i+1 << ": ";
				cin >> arrayData[i];
			}
			
			cout << "\n Output Array" << endl;
			cout << " ==========================================" << endl;
			
			for (i = 0; i < 10; i++){
				cout << " " << arrayData[i] << ",";
			}
			
			cout << "\n\n Mean Array" << endl;
			cout << " ==========================================" << endl;
			for(int i=0; i < n;i++){
				sum = sum + arrayData[i];
			}
			
			mean = sum / n;
			cout<<" Mean = " << mean << endl;
			
			cout << "\n Median Array" << endl;
			cout << " ==========================================" << endl;
			if(n % 2 == 0){
		    	median = (arrayData[(n/2)] + arrayData[(n/2)-1]) / 2;
			}
			else{
			    median = arrayData[(n/2)];
			}
			
			cout<<" Median = " << median << endl;
			
			cout << "\n Modus Array" << endl;
			cout << " ==========================================" << endl;
		    int max = * max_element(arrayData, arrayData + n);
		    
		    int t = max + 1;
		    int count[t];
		    for (i = 0; i < t; i++){
		        count[i] = 0;
			}

		    for (i = 0; i < n; i++){
		        count[arrayData[i]]++;
			}
		        
		    modus = 0;
		    int k = count[0];
		    for (int i = 1; i < t; i++) {
		        if (count[i] > k) {
		            k = count[i];
		            modus = i;
		        }
		    }
		    
			cout<<" Modus = " << modus << endl;
		
		printf("\n Input array ulang? (Y/T): ");
		cin >> back;

	} while (back == "y" || back == "Y");
	
    return 0;
}
