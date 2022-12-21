#include<iostream>
#include <conio.h>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

int main(){
	system("cls");
	struct mahasiswa {
		char nim[10];
		char nama[10];
		int nilai;
	} mhs[10];
	
	int i = 0;
	int n = 0;
	
	cout <<" Masukan jumlah data : ";
	cin >> n;
	
	for(i = 1; i <= n; i++){
		cout <<"\n Input Data"<< endl;
		cout<<" NIM = ";
		cin>>mhs[i].nim;
		cout<<" Nama = ";
		cin>>mhs[i].nama;
		cout<<" Nilai = ";
		cin>>mhs[i].nilai;
	}
	
	for(i=1;i<=n;i++){
		cout <<"\n Show Data"<< endl;
		cout<<" NIM = "<<mhs[i].nim;
		cout<<"\n Nama = "<<mhs[i].nama;
		cout<<"\n Nilai = "<<mhs[i].nilai;
		cout<<"\n";
	}
}
