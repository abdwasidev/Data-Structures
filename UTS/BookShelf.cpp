#include <iostream>
#include <string>

using namespace std;

//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165


//	BOOKS ==========================================================================================================================
//	================================================================================================================================
class Books {
    public:
	    int ID;
	    string TITLE;
	    string AUTHOR;
	    int YEAR;
};

//	NODE ===========================================================================================================================
//	================================================================================================================================
class Node: public Books {
	public:
		Node *next;
	
		Node() {
			ID = 0;
			TITLE = "";
			AUTHOR = "";
			YEAR = 0;
			next = NULL;
		}
		Node(int id, string title, string author, int year) {
			ID = id;
			TITLE = title;
			AUTHOR = author;
			YEAR = year;
			next = NULL;
		}
};


//	STACK ==========================================================================================================================
//	================================================================================================================================
class Stack {
	public:
		Node *top;
		
		Stack() {
			top = NULL;
		}
		
	    void push(Node *n);
	    Node *pop();
	    bool isEmpty();
	    bool checkNode(Node * n);
	    bool search(int key);
	    void display();
};

bool Stack::checkNode(Node * n){
	Node * temp = top;
	bool exist = false;
	while (temp != NULL) {
		if (temp -> ID == n -> ID) {
			exist = true;
			break;
		}
		temp = temp -> next;
	}
	return exist;
}

void Stack::push(Node * n) {
	if (top == NULL) {
		top = n;
	} else if (checkNode(n)) {
		cout << " Node dengan ID ini sudah ada" <<
		" Masukkan ID yang berbeda" << endl;
	} else {
		Node * temp = top;
		top = n;
		n -> next = temp;
	}
}

Node *Stack::pop(){
	Node * temp = NULL;
	if (isEmpty()) {
		cout << " Tidak Ada Stack" << endl;
		return temp;
	} else {
		temp = top;
		top = top -> next;
		return temp;
	}
}

bool Stack::isEmpty(){
	if (top == NULL) {
		return true;
	} else {
		return false;
	}
}

bool Stack::search(int key){
    Node * temp = top;
    while (temp != NULL) {
        if (temp->ID == key) {
        	cout << "\n ID\t\t: " << temp->ID << endl;
			cout << " Judul Buku\t: " << temp->TITLE << endl;
			cout << " Penulis\t: " << temp->AUTHOR << endl;
			cout << " Tahun Terbit\t: " << temp->YEAR << endl;
		}
        temp = temp->next;
    }
    return false;
}

void Stack::display() {
	if (isEmpty()){
		cout << " Tidak Ada Stack" << endl;
	} else {
		Node * temp = top;
		while (temp != NULL) {
			cout << "\n ID\t\t: " << temp->ID << endl;
			cout << " Judul Buku\t: " << temp->TITLE << endl;
			cout << " Penulis\t: " << temp->AUTHOR << endl;
			cout << " Tahun Terbit\t: " << temp->YEAR << endl;
			temp = temp -> next;
		}
		cout << endl;
	}
}

//	QUEUE ==========================================================================================================================
//	================================================================================================================================
class Queue {
	public:
	  	Node *front;
	  	Node *rear;
	  	
	    Queue(){
			front = NULL;
			rear = NULL;
	    }
		
	    void enqueue(Node *n);
	    Node *dequeue();
	    bool isEmpty();
	    bool checkNode(Node * n);
	    bool search(int key);
	    void display();
};

bool Queue::checkNode(Node * n){
	Node *temp = front;
	bool exist = false;
	while (temp != NULL) {
		if (temp -> ID == n -> ID) {
			exist = true;
			break;
		}
		temp = temp -> next;
	}
	return exist;
}

void Queue::enqueue(Node * n) {
	if (isEmpty()) {
		front = n;
		rear = n;
	} else if (checkNode(n)) {
		cout << " Node dengan ID ini sudah ada" <<
		" Masukkan ID yang berbeda" << endl;
	} else {
		rear->next = n;
		rear = n;
	}

}

Node *Queue::dequeue(){
	Node * temp = NULL;
	if (isEmpty()) {
		cout << " Tidak Ada Antrian" << endl;
		return temp;
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

bool Queue::isEmpty(){
	if (front==NULL && rear==NULL){
		return true;
	} else {
		return false;
	}
}

bool Queue::search(int key){
    Node * temp = front;
    while (temp != NULL) {
        if (temp->ID == key) {
        	cout << "\n ID\t\t: " << temp->ID << endl;
			cout << " Judul Buku\t: " << temp->TITLE << endl;
			cout << " Penulis\t: " << temp->AUTHOR << endl;
			cout << " Tahun Terbit\t: " << temp->YEAR << endl;
		}
        temp = temp->next;
    }
    return false;
}

void Queue::display() {
	if (isEmpty()){
		cout << " Tidak Ada Antrian" << endl;
	} else {
		Node *temp=front;
		while(temp!=NULL){
			cout << "\n ID\t\t: " << temp->ID << endl;
			cout << " Judul Buku\t: " << temp->TITLE << endl;
			cout << " Penulis\t: " << temp->AUTHOR << endl;
			cout << " Tahun Terbit\t: " << temp->YEAR << endl;
			temp=temp->next;
		}
		cout<<endl;
	}
}

void intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                             Program \"Bookshelf\"                               *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *************                   [1]. Abdul Wasi\' Al-Afif (20081010165)                      *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
}

void close(){
	exit(0);
}

int main() {
//	Stack stackBooks;
//	Queue queueBooks;
	int pilihan, ID, YEAR, key;
	string back, TITLE, AUTHOR;
	
	do {
		main:
			system("cls");
			intro();
			cout << "\n Pilih Operasi yang ingin dijalankan" << endl;
			cout << " [1]. Create Buku" << endl;
			cout << " [2]. Read Buku" << endl;
			cout << " [3]. Delete Buku" << endl;
			cout << " [4}. Search Buku" << endl;
			cout << " [5]. Close Program" << endl;
			cout << " ==========================================" << endl;
			cout << " Masukkan Pilihan (1-5): ";
			cin >>pilihan;
		
		    Node *new_node = new Node();
		
		    switch (pilihan) {
			    case 1:
			    	system("cls");
					cout << "\n Pilih Metode Input Buku" << endl;
					cout << " [1]. Stack (push)" << endl;
					cout << " [2]. Queue (enqueue)" << endl;
					cout << " [3]. Close Program" << endl;
					cout << " ==========================================" << endl;
					cout << " Masukkan Pilihan (1-3): ";
					cin >>pilihan;
				
				    switch (pilihan) {
				    case 1:
			    		system("cls");
						cout << "\n Stack::Input Buku" << endl;
						cout << " ================================" << endl;
						
						cout << "\n Masukkan ID Buku\t\t: ";
						cin >> ID;
						new_node -> ID = ID;
						cout << " Masukkan Judul Buku\t\t: ";
						cin >> TITLE;
						new_node -> TITLE = TITLE;
						cout << " Masukkan Penulis Buku\t\t: ";
						cin >> AUTHOR;
						new_node -> AUTHOR = AUTHOR;
						cout << " Masukkan Tahun Terbit Buku\t: ";
						cin >> YEAR;
						new_node -> YEAR = YEAR;
						
				    	stackBooks.push(new_node);
				    	break;
				    case 2:
			    		system("cls");
						cout << "\n Queue::Input Buku" << endl;
						cout << " ================================" << endl;
						
						cout << "\n Masukkan ID Buku\t\t: ";
						cin >> ID;
						new_node -> ID = ID;
						cout << " Masukkan Judul Buku\t\t: ";
						cin >> TITLE;
						new_node -> TITLE = TITLE;
						cout << " Masukkan Penulis Buku\t\t: ";
						cin >> AUTHOR;
						new_node -> AUTHOR = AUTHOR;
						cout << " Masukkan Tahun Terbit Buku\t: ";
						cin >> YEAR;
						new_node -> YEAR = YEAR;
						
				    	queueBooks.enqueue(new_node);
				    	break;
				    case 3:
				    	close();
				    	break;
					default:
						cout << "\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!" << endl;
						goto main;
				    }
					break;
			    case 2:
			    	system("cls");
					cout << "\n Pilih Metode Menampilkan Buku" << endl;
					cout << " [1]. Stack" << endl;
					cout << " [2]. Queue" << endl;
					cout << " [3]. Close Program" << endl;
					cout << " ==========================================" << endl;
					cout << " Masukkan Pilihan (1-3): ";
					cin >>pilihan;
				
				    switch (pilihan) {
				    case 1:
			    		system("cls");
						cout << "\n Stack::Daftar Buku Stack" << endl;
						cout << " ================================" << endl;
						
				    	stackBooks.display();
				    	break;
				    case 2:
			    		system("cls");
						cout << "\n Queue::Daftar Buku Queue" << endl;
						cout << " ================================" << endl;
						
				    	queueBooks.display();
				    	break;
				    case 3:
				    	close();
				    	break;
					default:
						cout << "\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!" << endl;
						goto main;
				    }
					break;
			    case 3:
			    	system("cls");
					cout << "\n Pilih Metode Menghapus Buku" << endl;
					cout << " [1]. Stack (pop)" << endl;
					cout << " [2]. Queue (dequeue)" << endl;
					cout << " [3]. Close Program" << endl;
					cout << " ==========================================" << endl;
					cout << " Masukkan Pilihan (1-3): ";
					cin >>pilihan;
				
				    switch (pilihan) {
				    case 1:
			    		system("cls");
						cout << "\n Stack::Hapus Buku" << endl;
						cout << " ================================" << endl;
						new_node = stackBooks.pop();
						
						cout << "\n ID\t\t: " << new_node->ID << endl;
						cout << " Judul Buku\t: " << new_node->TITLE << endl;
						cout << " Penulis\t: " << new_node->AUTHOR << endl;
						cout << " Tahun Terbit\t: " << new_node->YEAR << endl;
						
						delete new_node;
				    	break;
				    case 2:
			    		system("cls");
						cout << "\n Queue::Hapus Buku" << endl;
						cout << " ================================" << endl;
						new_node = queueBooks.dequeue();
						
						cout << "\n ID\t\t: " << new_node->ID << endl;
						cout << " Judul Buku\t: " << new_node->TITLE << endl;
						cout << " Penulis\t: " << new_node->AUTHOR << endl;
						cout << " Tahun Terbit\t: " << new_node->YEAR << endl;
						
						delete new_node;
				    	break;
				    case 3:
				    	close();
				    	break;
					default:
						cout << "\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!" << endl;
						goto main;
				    }
					break;
			    case 4:
			    	system("cls");
					cout << "\n Pilih Area Pencarian Buku" << endl;
					cout << " [1]. Stack" << endl;
					cout << " [2]. Queue" << endl;
					cout << " [3]. Close Program" << endl;
					cout << " ==========================================" << endl;
					cout << " Masukkan Pilihan (1-3): ";
					cin >>pilihan;
				
				    switch (pilihan) {
				    case 1:
			    		system("cls");
						cout << "\n Stack::Cari Buku di Stack" << endl;
						cout << " ================================" << endl;
						
						cout << "\n Masukkan ID Buku yang dicari\t: ";
						cin >> key;
						
						stackBooks.search(key) == true ? true : cout << "\n Buku dengan ID " << key << " tidak ada." << endl;
						
				    	break;
				    case 2:
			    		system("cls");
						cout << "\n Queue::Cari Buku di Queue" << endl;
						cout << " ================================" << endl;
						
				    	cout << "\n Masukkan ID Buku yang dicari\t: ";
						cin >> key;
						
						queueBooks.search(key) == true ? true : cout << "\n Buku dengan ID " << key << " tidak ada." << endl;
						
				    	break;
				    case 3:
				    	close();
				    	break;
					default:
						cout << "\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!" << endl;
						goto main;
				    }
					break;
			    case 5:
					close();
				default:
					cout << "\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!" << endl;
					goto main;
			    }
		
		printf("\n Ingin kembali ke menu pilihan? (Y/T): ");
		cin >> back;

	} while (back == "y" || back == "Y");

	return 0;
}
