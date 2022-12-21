#include <iostream>
#include<stdio.h>
#include<stdlib.h>

//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} node;

void insert(node *pointer, int data){
    while(pointer->next!=NULL){
        pointer = pointer -> next;
    }
    
    pointer->next = (node *)malloc(sizeof(node));
    (pointer->next)->prev = pointer;
    pointer = pointer->next;
    pointer->data = data;
    pointer->next = NULL;
}
int find(node *pointer, int key){
    pointer =  pointer -> next;
    
    while(pointer!=NULL){
        if(pointer->data == key) {
                return 1;
        }
        pointer = pointer -> next;
    }
    
    return 0;
}

void remove(node *pointer, int data){
	
    while(pointer->next!=NULL && (pointer->next)->data != data){
        pointer = pointer -> next;
    }
    
    if(pointer->next==NULL){
        printf(" Data tidak ditemukan!\n",data);
        return;
    }
    
    node *temp;
    temp = pointer -> next;
    
    pointer->next = temp->next;
    temp->prev =  pointer;
    
    free(temp);
    
    return;
}
void display(node *pointer){
    if(pointer==NULL){
            return;
    }
    
    printf(" %d ",pointer->data);
    display(pointer->next);
}

void intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                           Program \"Double Linked List\"                        *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *************                        Abdul Wasi\' Al-Afif (20081010165)                      *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
}

void close(){
	exit(0);
}

int main() {
    node *start,*temp;
    start = (node *)malloc(sizeof(node)); 
    temp = start;
    temp -> next = NULL;
    
	int num, data, status;
	string back;
	
	do {
		main:
			system("cls");
			intro();
			cout << "\n Pilih Operasi yang ingin dijalankan" << endl;
			cout << " [1]. Insert Data" << endl;
			cout << " [2]. Read Data" << endl;
			cout << " [3]. Delete Data" << endl;
			cout << " [4}. Search Data" << endl;
			cout << " [5]. Close Program" << endl;
			cout << " ==========================================" << endl;
			cout << " Masukkan Pilihan (1-5): ";
			cin >> num;
			
			switch (num) {
			    case 1:
			    	do{
						insert_data:
					    	system("cls");
							cout << "\n Insert Data" << endl;
							cout << " ==========================================" << endl;
							cout << " Insert Data\t: ";
	                        scanf("%d",&data);
	                        insert(start,data);
									
							printf("\n Masukkan data lagi? (Y/T): ");
							cin >> back;
							
							if (back == "t" || back == "T") {
								goto main;
							} else if (back == "y" || back == "T") {
								goto insert_data;
							}
							
					} while (back == "y" || back == "Y");
				break;
			    case 2:
				    	system("cls");
						cout << "\n Read Data" << endl;
						cout << " ==========================================" << endl;
                        display(start->next);
                        printf("\n");
				break;
			    case 3:
			    	do{
				    	delete_data:
					    	system("cls");
							cout << "\n Delete Data" << endl;
							cout << " ==========================================" << endl;
							cout << " Delete Data\t: ";
	                        scanf("%d",&data);
	                        remove(start,data);
									
							printf("\n Hapus data lagi? (Y/T): ");
							cin >> back;
							
							if (back == "t" || back == "T") {
								goto main;
							} else if (back == "y" || back == "T") {
								goto delete_data;
							}
							
					} while (back == "y" || back == "Y");
				break;
			    case 4:
				    	system("cls");
						cout << "\n Search Data" << endl;
						cout << " ==========================================" << endl;
						cout << " Search Data\t: ";
                        scanf("%d",&data);
                        
                        status = find(start, data);
                        
                        if(status){
                            printf(" Data ditemukan\n");
                        } else {
                            printf(" Data tidak ditemukan!\n");
                        }
				break;
			    case 5:
					close();
				break;
				default:
					cout << "\n Mohon maaf, pilihan anda tidak termasuk dalam menu!" << endl;
					goto main;
			    }
			
		printf("\n Ingin kembali ke menu? (Y/T): ");
		cin >> back;

	} while (back == "y" || back == "Y");
	
    return 0;
}
