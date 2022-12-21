#include <iostream>
#include <string>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

class list {
	public:
		struct node {
			int id;
			string name;
			string jurusan;
			string npm;
			struct node *next;
		} *head, *tail, *ptr;	
	
		list():head(NULL), tail(NULL){}
		~list();
	
		struct list::node* searchName(struct list::node*, string);	
		struct list::node* searchId(struct list::node*, int);
		struct list::node* initNode(string, int, string, string);
	
		void reverse();
		void addNode( struct list::node*);
		void insertNode( struct list::node*);
		void deleteNode( struct list::node*);
		void deleteList( struct list::node*);
		void displayList( struct list::node*) const ;
	 	void displayNode( struct list::node*) const;
	 	void close();
		void intro();	
};

list::~list() {
	node *current,*temp;
	current = head;
	temp = head;
	while(current != NULL) {
		current = current->next;
		delete temp;
		temp = current;
	}
}

struct list::node* list::initNode(string s, int i, string j, string n) {
	struct node *ptr = new node;

	if(ptr == NULL){
		return static_cast<struct node *>(NULL);  
	} else {  
		ptr->name = s ;  
		ptr->id = i;
		ptr->jurusan = j;
		ptr->npm = n;                    
		return ptr;                         
	}
}

void list::addNode(struct node *newNode)  {
	if(head == NULL) {
		head = newNode;  
		tail = newNode;
	}

	tail->next = newNode;       
	newNode->next = NULL;       
	tail = newNode;               
}

void list::insertNode(struct node *newnode) {
	struct node *temp, *prev;                

	if(head == NULL) {                      
       head = newnode;
       tail = newnode;
       head->next = NULL;  
       return;                                             
	}

	temp = head;
   
	while(temp->name < newnode->name) {
		temp = temp->next; 
		if(temp == NULL) {
			break;
		}
	}							 
          
	if(temp == head) {
		newnode->next = head;  
		head = newnode;
	} else {
		prev = head;
		while(prev->next != temp){
		  	prev = prev->next;
		}
		
		prev->next = newnode;
		newnode->next = temp;
		
		if(tail == prev){
			tail = newnode;
		}
	}
}

struct list::node* list::searchName(struct node* ptr, string name){
    while(name != ptr->name){    
		ptr = ptr->next;                          
		if(ptr == NULL){
			break;
		}                         
    }
    return ptr; 	
}

struct list::node* list::searchId(struct node* ptr, int id) {
    while(id != ptr->id){    
		ptr = ptr->next;                          
		if(ptr == NULL){
			break;
		}                          
    }
    return ptr; 	
}

void list::reverse() {
	if(head == NULL || head->next == NULL) return;
	node *parent = head;
	node *me = head->next;
	node *child = me->next;
	
	head->next = NULL;
	
	me->next = head;
	
	while(child != NULL){
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	
	head = me;
	
	head->next = parent;
}
 

void list::deleteNode(struct list::node *ptr){
  struct node *temp, *prev;
   temp = ptr;
   prev = head;   

   if(temp == prev) {
		head = head->next; 
		if(tail == temp){
			tail = tail->next; 
		}     
		delete temp ;
   }
   else {
		while(prev->next != temp){
			prev = prev->next;  
		}
		
		prev->next = temp->next;
		
		if(tail == temp){
			tail = prev;
		}
      	delete temp;
   }
}

void list::deleteList(struct node *ptr){
   struct node *temp;

   if(head == NULL) return;     

   if(ptr == head ){ 
       head = NULL; 
       tail = NULL;                                  
   }
   else {
       temp = head; 
       while( temp->next != ptr ) 
           temp = temp->next;
       tail = temp;
   }

   while(ptr != NULL) { 
      temp = ptr->next;              
      delete ptr;                       
      ptr = temp;    
   }
}

void list::displayNode(struct list::node *ptr) const {
    cout << " ID\t: " << ptr->id << endl;
    cout << " Nama\t: " << ptr->name << endl;
    cout << " Jurusan: " << ptr->jurusan << endl;
    cout << " NPM\t: " << ptr->npm << endl;
    cout << endl;
}

void list::displayList( struct list::node *ptr) const
{
	if(!ptr) cout << "\nTidak ada data yang bisa ditampilkan\n" << endl;
	while(ptr) {
		displayNode(ptr);
		ptr = ptr->next;
	}
}

void list::close(){
	exit(0);
}


void list::intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                                                                               *************\n");
	printf(" *************                          Author: Abdul Wasi\' Al-Afif                          *************\n");
	printf(" *************                                                                               *************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
}

int main(){
	char kembali;
	int id, select;
	string name, jurusan, npm;
 	list myList;
	list::node* ptr;

	ptr = myList.initNode("ELSA AULIA ADISTI", 1, "AKUNTANSI", "22013010086");
	myList.addNode(ptr);
	ptr = myList.initNode("JELITA SEPTYA SALSABILLA", 2, "TEKNOLOGI PANGAN", "22033010084");
	myList.addNode(ptr);
	ptr = myList.initNode("NABILA HAURA AZALIA", 3, "TEKNIK SIPIL", "22035010062");
	myList.addNode(ptr);
	ptr = myList.initNode("TIARA DWI RAMANDITA", 4, "ADMINISTRASI PUBLIK", "22041010214");
	myList.addNode(ptr);
	ptr = myList.initNode("MERLINDA SAYIDATINA AISYAH PUTRI", 5, "ILMU KOMUNIKASI", "22043010190");
	myList.addNode(ptr); 

	while(1){
		system("cls");
		myList.intro();
		printf("\n\n MAIN MENU:");
		printf("\n [1]. Display Data");
		printf("\n [2]. Delete Data");
		printf("\n [3]. Insert Data");
		printf("\n [4]. Reverse Data");
		printf("\n [5]. Close");
		printf("\n\n Input Pilihan Nomor Menu : ");
		scanf("%d", &select);
		switch(select){
			case 1:
				system("cls");
				cout << " Menampilkan Data Awal Mahasiswa\n" << endl << endl;
				myList.displayList(myList.head);
				printf("\n");
			break;
			case 2:
				system("cls");
				cout << " Menampilkan Hasil Delete Data Mahasiswa\n" << endl << endl;
				name = "NABILA HAURA AZALIA";
				ptr = myList.searchName( myList.head, name );
				if( ptr == NULL ) {
					cout << "\n Nama\t: " << name << " tidak ditemukan" << endl;
				}
				else {
					myList.deleteNode(ptr);
				}
				myList.displayList(myList.head);
				printf("\n");
			break;
			case 3:
				system("cls");
				cout << " Menampilkan Hasil Insert Data Mahasiswa\n" << endl << endl;
				name = "NOVALDI RIZKY SAPUTRA";
				id = 6;
				jurusan = "TEKNIK SIPIL";
				npm = "22035010100";
				ptr = myList.initNode(name, id, jurusan, npm);
				myList.insertNode( ptr );
				
				myList.displayList(myList.head);
				printf("\n");
			break;
			case 4:
				system("cls");
				cout << " Menampilkan Hasil Reverse Data Mahasiswa\n" << endl << endl;	
				myList.reverse();
				myList.displayList(myList.head);
				printf("\n");
			break;
			case 5:
				myList.close();
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

