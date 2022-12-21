#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

long int faktorial (int A);

int main(){
	system("cls");
	
	int r, hasil;
	
	cout<<"Menghitung nilai faktorial dengan Rekursiv"<<endl;
	cout<<"Masukkan nila :";
	cin>>r;
	
	hasil=faktorial(r);
	cout<<"Faktorial "<<r<<" != "<<hasil<<endl;
}

long int faktorial (int A){
	if(A==1)
	return(A);
	else
	return(A*faktorial(A-1));
}
