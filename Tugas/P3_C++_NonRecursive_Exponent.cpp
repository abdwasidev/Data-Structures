#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

int fpangkat(int pangkat, int angka){
	int i, hasil=1;
	for(i=1; i<=pangkat; i++){
			hasil=hasil*angka;
	}
	return hasil;	
	
}

int main(){
	system("cls");
	int angka, pangkat;
	
	cout<<"Masukkan angka : "; cin>>angka;
	cout<<"Masukkan pangkat : "; cin>>pangkat;
	
	cout << fpangkat(pangkat, angka);
}
