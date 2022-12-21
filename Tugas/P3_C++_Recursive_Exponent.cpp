#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

int fpangkat(int angka, int pangkat){
	if(pangkat==0){
		return 1;
	}
	else {
		return fpangkat(angka, pangkat -1)*angka; 
	}	
	
}

int main(){
	system("cls");
	int angka, pangkat;
	
	cout<<"Masukkan angka : "; cin>>angka;
	cout<<"Masukkan pangkat : "; cin>>pangkat;
	
	cout<<fpangkat(pangkat, angka);
}
