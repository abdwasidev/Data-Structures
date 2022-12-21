#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

void hanoi(int n, char dari, char bantu, char tujuan){
	if(n==1)
	cout<<"Pindah piring dari "<<dari<<" ke "<<tujuan <<endl;
	else{
		hanoi(n-1, dari, tujuan, bantu);
		hanoi(1, dari, bantu, tujuan);
		hanoi(n-1, bantu, dari,  tujuan);
	}

}

int main(){
	system("cls");
	
	int jum_piring;
	
	cout<<"Teknik hanoi pada C++"<<endl<<endl;
	cout<<"Masukkan jumlah piring : ";
	cin>>jum_piring;
	
	hanoi(jum_piring, 'A', 'B', 'C');
}
