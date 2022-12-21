#include<iostream>
#include <conio.h>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

typedef int angka;
typedef float pecahan;
typedef char huruf;

int main(){
	system("cls");
	
	angka umur;
	pecahan pecah;
	huruf h, nama[50];
	
	cout<<" Masukkan umur anda : "; cin>>umur;
	cout<<" Umur anda adalah : "<< umur <<endl;
	cout<<" Masukkan bilangan pecahan : "; cin>>pecah;
	cout<<" Bilangan pecahan : "<< pecah <<endl;
	cout<<" Masukkan huruf : "; cin >> h ;
	cout<<" Huruf anda : "<< h <<endl;
	cout<<" Masukkan nama : "; cin >> h;
	cout<<" Nama anda : "<< nama << endl ;
}
