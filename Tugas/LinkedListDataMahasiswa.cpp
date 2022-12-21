 // LIBRARY
// =====================================================
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

// =====================================================

// PARENT CLASS
// =====================================================
class Kampusku{
    public:
	    int ID;
	    string NPM;
	    string Nama;
	    string Jurusan;
	
};
// =====================================================

// CHILD CLASS
// =====================================================
class DataMahasiswa: public Kampusku {
    
	public:
	    
	    DataMahasiswa(){
	        Nama = "";
	        Jurusan = "";
	        NPM = "";
	        ID = 0;
	    }
	    
	    DataMahasiswa(string name, string program, string NIM, int id){
	        Nama = name;
	        Jurusan = program;
	        NPM = NIM;
	        ID = id;
	    }
	    
	    DataMahasiswa(int id, string name, string program, string NIM){
	        this -> Nama = name;
	        this -> Jurusan = program;
	        this -> NPM = NIM;
	        this -> ID = id;
	    }
	    
	    DataMahasiswa(const DataMahasiswa & obj){
	        this -> ID = obj.ID;
	        this -> Nama = obj.Nama;
	        this -> Jurusan = obj.Jurusan;
	        this -> NPM = obj.NPM;
	    }
	    
	    void print(){
	        cout << " ID Menu\t: " << ID << endl;
	        cout << " Nama\t\t: " << Nama << endl;
	        cout << " NPM\t\t: " << NPM << endl;
	        cout << " Jurusan\t: " << Jurusan << endl;
	        cout << endl << endl;
	        
	    }
	    
	    void setNama(string);
	    string getNama();
	    void setJurusan(string);
	    string getJurusan();
	    void setNPM(string);
	    string getNPM();
	    void setId();
	    int getId();
	    void close();
	    void intro();
};
// =====================================================

// STRUCT && LINKEDLIST
// =====================================================
struct Node {
    DataMahasiswa menu;
    Node *next;
};

Node *head, *tail;

void firstNode(Node *head, Node *tail, DataMahasiswa menu) {
    head->menu = menu;
    head->next = NULL;
    tail = head;
}


void appendNode(Node *head, DataMahasiswa _menu) {
    Node *newNode = new Node;
    newNode->menu = _menu;
    newNode->next = NULL;
    
    Node *current = head;   
    while (current){
        if (current->next == NULL){
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void displayList(struct Node *head){
	Node *linkedlist = head;
	
	while(linkedlist){
		linkedlist->menu.print();
		linkedlist=linkedlist->next;
	}
}
// =====================================================

// SET && GET METHOD
// =====================================================
void DataMahasiswa::setNama(string name) {
    Nama = name;
}

string DataMahasiswa::getNama() {
    return Nama;
}


void DataMahasiswa::setJurusan(string program) {
    Jurusan = program;
}


string DataMahasiswa::getJurusan() {
    return Jurusan;
}


void DataMahasiswa::setNPM(string NIM){
    NPM = NIM;
}

string DataMahasiswa::getNPM(){
    return NPM;
}


void DataMahasiswa::setId() {
    int MIN_VALUE = 0000;
    int MAX_VALUE = 9999;
    ID = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
}

int DataMahasiswa::getId(){
    return ID;
}
// =====================================================

// OTHER
// =====================================================
void DataMahasiswa::close(){
	exit(0);
}

void DataMahasiswa::intro(){
	
	printf("*********************************************************************************************************\n");
	printf("*********************************************************************************************************\n");
	printf("*************                                                                               *************\n");
	printf("*************                          Author: Abdul Wasi\' Al-Afif                          *************\n");
	printf("*************                                                                               *************\n");
	printf("*********************************************************************************************************\n");
	printf("*********************************************************************************************************\n");
}
// =====================================================

// MAIN FUNCTION
// =====================================================
int main(){
	system("cls");

	char kembali;
	int i = 0, select;
	
    DataMahasiswa mahasiswa[10];
    
    mahasiswa[0].setNama("ELSA AULIA ADISTI");
	mahasiswa[1].setNama("ANIESA INDRIYANA EKA ZAFIRA");
	mahasiswa[2].setNama("JELITA SEPTYA SALSABILLA");
	mahasiswa[3].setNama("SYAKIRA AUFA ZAHRANAH");
	mahasiswa[4].setNama("NABILA LAILATUL FAUZIAH");
	mahasiswa[5].setNama("NABILA HAURA AZALIA");
	mahasiswa[6].setNama("RIZAL ALI RAHMANDA");
	mahasiswa[7].setNama("NOVALDI RIZKY SAPUTRA");
	mahasiswa[8].setNama("TIARA DWI RAMANDITA");
	mahasiswa[9].setNama("MERLINDA SAYIDATINA AISYAH PUTRI");
    
    mahasiswa[0].setJurusan("AKUNTANSI");
    mahasiswa[1].setJurusan("AKUNTANSI");
    mahasiswa[2].setJurusan("TEKNOLOGI PANGAN");
    mahasiswa[3].setJurusan("TEKNOLOGI PANGAN");
    mahasiswa[4].setJurusan("TEKNOLOGI PANGAN");
    mahasiswa[5].setJurusan("TEKNIK SIPIL");
    mahasiswa[6].setJurusan("TEKNIK SIPIL");
    mahasiswa[7].setJurusan("TEKNIK SIPIL");
    mahasiswa[8].setJurusan("ADMINISTRASI PUBLIK");
    mahasiswa[9].setJurusan("ILMU KOMUNIKASI");
    
    mahasiswa[0].setNPM("22013010086");
    mahasiswa[1].setNPM("22013010118");
    mahasiswa[2].setNPM("22033010084");
    mahasiswa[3].setNPM("22033010090");
    mahasiswa[4].setNPM("22033010093");
    mahasiswa[5].setNPM("22035010062");
    mahasiswa[6].setNPM("22035010089");
    mahasiswa[7].setNPM("22035010100");
    mahasiswa[8].setNPM("22041010214");
    mahasiswa[9].setNPM("22043010190");
    
    for (int i = 0; i < 15; i++) {
        mahasiswa[i].setId();
    }
    
    struct Node *head = new Node;
    
    for (int i = 0; i < 15; i++){
        if (i == 0){
		    firstNode(head, tail, DataMahasiswa(mahasiswa[i].getId(), mahasiswa[i].getNama(), 
		    mahasiswa[i].getJurusan(), mahasiswa[i].getNPM()));
		}
		if ( i > 0) {
		    appendNode(head, DataMahasiswa(mahasiswa[i].getId(), mahasiswa[i].getNama(), 
		    mahasiswa[i].getJurusan(), mahasiswa[i].getNPM()));
		}
	}
	
	while(1){
		system("cls");
		mahasiswa[i].intro();
		printf("\n\n MAIN MENU:");
		printf("\n [1]. Display Data");
		printf("\n [2]. Delete Data");
		printf("\n [3]. Search Data");
		printf("\n [4]. Sorting Data");
		printf("\n [5]. Close");
		printf("\n Input Pilihan Nomor Menu : ");
		scanf("%d", &select);
		switch(select){
			case 1:
				system("cls");
				cout << " Menampilkan Data Menu Restoran\n" << endl << endl;
				displayList(head);
				printf("\n");
			break;
			case 2:
				mahasiswa[i].close();
				printf("\n");
			break;
			default:printf("\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!");
			break;		}

		printf("\n =====================================\n");
		printf(" Ingin kembali ke menu pilihan? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);

	}
    
    return 0;
}
// =====================================================
//	https://ilmu.upnjatim.ac.id/pluginfile.php/377671/mod_resource/content/1/4.%20Konsep%20linked%20list.pdf
//	https://ilmu.upnjatim.ac.id/pluginfile.php/381292/mod_resource/content/1/5.%20Konsep%20Stack.pdf
//	https://ilmu.upnjatim.ac.id/pluginfile.php/383751/mod_resource/content/2/6.%20Konsep%20Queue.pdf
	
	
//	https://www.bogotobogo.com/cplusplus/linkedlist.php

