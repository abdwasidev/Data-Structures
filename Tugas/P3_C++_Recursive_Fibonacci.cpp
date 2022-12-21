#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

int F(int n){
	if(n==0 || n==1) return n;
	else {
		return F(n-1)+F(n-2);
	}
}

int main(){
	system("cls");
	int n;
	
	cout<<"______________________________"<<endl;
	cout<<"  Program C++ Deret Fibonacci"<<endl;
	cout<<"        Fungsi Rekursiv       "<<endl;
	cout<<"______________________________"<<endl<<endl;
	
	cout<<" Berapa jumlah deret ?"<<endl;
	cin>>n;
	cout<<endl;
	cout<<"Fibonacci "<<n<<" Deret"<<endl<<endl;
	
	for(int i=0; i<n; i++){
		cout<<F(i)<<" ";
	}
	
	cout<<endl<<endl<<endl;
	cout<<"_________________"<<endl<<endl;
	
	return 0;
}
