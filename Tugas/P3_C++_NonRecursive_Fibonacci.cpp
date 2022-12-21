a#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

int main(){
	system("cls");
	int n, Fn,  Fn_min_1, Fn_min_2;
	
	cout<<"______________________________"<<endl;
	cout<<"  Program C++ Deret Fibonacci"<<endl;
	cout<<"______________________________"<<endl<<endl;
	
	cout<<" Berapa jumlah deret ?"<<endl;
	cin>>n;
	cout<<endl;
	cout<<"Fibonacci "<<n<<" Deret"<<endl<<endl<<" ";
	
	Fn_min_1=1;
	Fn_min_2=0;
	
	for(int i =1; i<n; i++){
		if(i==1) cout<<Fn_min_2<<" ";
		if(i==2) cout<<Fn_min_1<<" ";
		else{
			Fn=Fn_min_1+Fn_min_2;
			Fn_min_2=Fn_min_1;
			Fn_min_1=Fn;
			cout<<Fn<<" ";
		}
	}
	
	cout<<endl<<endl<<endl;
	cout<<"_____________________"<<endl<<endl;
	return 0;
}
