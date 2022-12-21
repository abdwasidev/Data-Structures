#include <iostream>


//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

using namespace std;

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
		
		Queue();
		bool isEmpty();
		bool isFull(Node *n);
		bool checkIfNodeExist(Node *n);
		void enqueue(Node *n);
		Node* dequeue();
		int count();
		void display();
};

Queue::Queue(){
	front = NULL;
	rear = NULL;
}

bool Queue::isEmpty() {
	if(front == NULL && rear == NULL){
		return true;
	} else {
		return false;
	}
}

bool Queue::isFull(Node *n) {
	Node *temp = rear;
	if(temp == n){
		return true;
	} else {
		return false;
	}
}

bool Queue::checkIfNodeExist(Node * n) {
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

void Queue::enqueue(Node *n) {
	if (isEmpty()){
		front = n;
		rear = n;
		cout << "\n Node berhasil ditambah" << endl;
	} else if(checkIfNodeExist(n)) {
		cout << " Node dengan ID key ini sudah ada" <<
		" Masukkan ID key yang berbeda" << endl;
	} else {
		rear->next=n;
		rear=n;
		cout << "\n Node berhasil ditambah" << endl;
	}
}

Node *Queue::dequeue() {
	Node *temp=NULL;
	if (isEmpty()) {
		cout << " Tidak ada antrian" << endl;
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

int Queue::count() {
	int count=0;
	Node *temp=front;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
void Queue::display() {
	if(isEmpty()){
		cout << " Tidak ada antrian" << endl;
	} else {
		Node *temp=front;
		while(temp!=NULL){
			cout << "\n ID\t: " << temp->key << endl;
			cout << " Data\t: " << temp->data << endl;
			temp=temp->next;
		}
		cout<<endl;
	}
}

void intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                                  Program \"Queue\"                              *************\n");
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
	Queue data_queue;
	int num, key, data;
	
	string back;
	
	do {
		main:
			system("cls");
			intro();
			cout << "\n Pilih Operasi yang ingin dijalankan" << endl;
			cout << " [1]. Insert Data" << endl;
			cout << " [2]. Read Data" << endl;
			cout << " [3]. Delete Data" << endl;
			cout << " [4]. Close Program" << endl;
			cout << " ==========================================" << endl;
			cout << " Masukkan Pilihan (1-4): ";
			cin >> num;
			
			Node * new_node = new Node();
			
			switch (num) {
			    case 1:
			    	do{
						insert_data:
					    	system("cls");
							cout << "\n Insert Data" << endl;
							cout << " ==========================================" << endl;
							cout << " Masukkan ID\t: ";
							cin >> key;
							cout << " Masukkan DATA\t: ";
							cin >> data;
							
							new_node -> key = key;
							new_node -> data = data;
							data_queue.enqueue(new_node);
									
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
                        data_queue.display();
                        cout << " Jumlah Queue Node	: " << data_queue.count() << endl;
                        printf("\n");
				break;
			    case 3:
			    	do{
				    	delete_data:
					    	system("cls");
							cout << "\n Delete Data" << endl;
							cout << " ==========================================" << endl;
							new_node = data_queue.dequeue();
							
							cout << "\nStack teratas adalah " << endl;
							cout << "\n ID\t: " << new_node->key << endl;
							cout << " Data\t: " << new_node->data << endl;
							delete new_node;
									
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
