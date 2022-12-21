#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

class Node {
	public:
		int key;
		int data;
		Node * next;

		Node() {
			key = 0;
			data = 0;
			next = NULL;
		}
		Node(int k, int d) {
			key = k;
			data = d;
			next = NULL;
		}
};

class Queue {
	public:
	  	Node *front;
	  	Node *rear;
	  	
	    Queue(){
			front = NULL;
			rear = NULL;
	    }
	    
	    bool isEmpty(){
	    	if(front==NULL && rear==NULL){
	    		return true;
			} else {
				return false;
			}
		}
		 
		bool checkIfNodeExist(Node *n){
			Node *temp = front;
			bool exist=false;
			while(temp!=NULL){
			if(temp->key==n->key){
				exist=true;
				break;
			}
			temp=temp->next;
			}
			return exist;
		}
		
		void enqueue(Node *n) {
			if (isEmpty()){
				front = n;
				rear = n;
				cout<<" Node sukses ENQUEUE"<<endl;
			} else if(checkIfNodeExist(n)) {
				cout << " Node dengan ID key ini sudah ada" <<
				" Masukkan ID key yang berbeda" << endl;
			}
			else {
				rear->next=n;
				rear=n;
				cout<<" Node sukses ENQUEUE"<<endl;
			}
		}
		
		Node* dequeue() {
			Node *temp=NULL;
			if (isEmpty()) {
				cout << " Tidak Ada Antrian" << endl;
				return NULL;
			} else {
				if(front==rear) {
					temp=front;
					front = NULL;
					rear = NULL;  
					return temp;
				} else {
					temp=front;
					front = front->next;  
					return temp;
				}
			}
		}
		
		int count() {
			int count=0;
			Node *temp=front;
			while(temp!=NULL){
				count++;
				temp=temp->next;
			}
			return count;
		}
			
		void display() {
			if(isEmpty()){
				cout << " Tidak Ada Antrian" << endl;
			} else {
				cout << " View All Queue" << endl;
				Node *temp=front;
				while(temp!=NULL){
					cout << "\n ID\t: " << temp->key << endl;
					cout << " Data\t: " << temp->data << endl;
					temp=temp->next;
				}
			cout<<endl;
			}
	    }
};

void intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                                                                               *************\n");
	printf(" *************                          Author: Abdul Wasi\' Al-Afif                          *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
}
 
int main() {
	Queue q;
	int option,key, data;
	
	do {
		intro();
		cout << "\n Pilih Operasi Stack yang ingin dijalankan" << endl;
		cout << " 1. .Enqueue()" << endl;
		cout << " 2. .Dequeue()" << endl;
		cout << " 3. .isEmpty()" << endl;
		cout << " 4. .count()" << endl;
		cout << " 5. .display()" << endl;
		cout << " 6. .Clear Screen" << endl << endl;
		cin >> option;
		
		Node * new_node = new Node();
		
		switch (option) {
		case 0:
			break;
		case 1:
			cout << "\n Memanggil fungsi ENQUEUE" << endl;
			cout << "\n Input key dan value ke ENQUEUE di Queue" << endl;
			cin >> key;
			cin >> data;
			new_node->key = key;
			new_node->data = data;
			q.enqueue(new_node);
			break;
		case 2:
			cout << "\n Memanggil fungsi DEQUEUE" << endl;
			new_node = q.dequeue();
			cout << "\n Nilai Dequeued adalah " << endl;
			cout << "\n ID\t: " << new_node->key << endl;
			cout << " Data\t: " << new_node->data << endl;
			delete new_node;
			cout<<endl;
			break;
		case 3:
			cout << "\n Memanggil fungsi isEMPTY" << endl;
			if (q.isEmpty())
				cout << " Tidak Ada Antrian" << endl;
			else
				cout << " Terdapat Antrian" << endl;
			break;
		case 4:
			cout << "\n Memanggil fungsi COUNT" << endl;
			cout << " Jumlah Node in Antiran: " <<q.count()
			<<endl;
			break;
		case 5:
			cout << "\n Memanggil fungsi DISPLAY" << endl;
			q.display();
			cout << endl;
			break;
		case 6:
			system("cls");
			break;
		default:
			cout << "\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!" << endl;
		}
	} while (option != 0);
	
	return 0;
}
