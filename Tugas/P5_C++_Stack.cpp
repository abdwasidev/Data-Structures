#include<iostream>
using namespace std;
//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165
//https://github.com/murtraja/stack-linked-list
//https://lookcos.cn/archives/1120.html
//https://github.com/hasancse91/data-structures
//https://github.com/tpatil2/C-Programs
//https://github.com/Abdulsayedd/Data-Structure

https://gist.github.com/hyperion0201/69480d34d31df49fb9fc50e463d37107

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

class Stack {
	public:
		Node * top;
		
		Stack() {
			top = NULL;
		}
		
		bool isEmpty() {
			if (top == NULL) {
				return true;
			} else {
				return false;
			}
		}
		bool checkIfNodeExist(Node * n) {
			Node * temp = top;
			bool exist = false;
			while (temp != NULL) {
				if (temp -> key == n -> key) {
					exist = true;
					break;
				}
				temp = temp -> next;
			}
			return exist;
		}
		
		void push(Node * n) {
			if (top == NULL) {
				top = n;
				cout << " Node sukses diPUSH" << endl;
			} else if (checkIfNodeExist(n)) {
				cout << " Node dengan ID key ini sudah ada" <<
				" Masukkan ID key yang berbeda" << endl;
			} else {
				Node * temp = top;
				top = n;
				n -> next = temp;
				cout << " Node sukses diPUSH" << endl;
			}
		
		}
		
		Node * pop() {
			Node * temp = NULL;
			if (isEmpty()) {
				cout << " Stack underflow" << endl;
				return temp;
			} else {
				temp = top;
				top = top -> next;
				return temp;
			}
		}
		Node * peek() {
			if (isEmpty()) {
				cout << " Stack underflow" << endl;
				return NULL;
			} else {
				return top;
			}
		}
		int count() {
			int count = 0;
			Node * temp = top;
			while (temp != NULL) {
				count++;
				temp = temp -> next;
			}
			return count;
		}
		void display() {
			cout << " View All Stack:" << endl;
			Node * temp = top;
			while (temp != NULL) {
				cout << "\n ID\t: " << temp->key << endl;
    			cout << " Data\t: " << temp->data << endl;
				temp = temp -> next;
			}
		cout << endl;
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
	Stack s1;
	int option, key, data;
	
	do {
		intro();
		cout << "\n Pilih Operasi Stack yang ingin dijalankan" << endl;
		cout << " 1. .push()" << endl;
		cout << " 2. .pop()" << endl;
		cout << " 3. .isEmpty()" << endl;
		cout << " 4. .peek()" << endl;
		cout << " 5. .count()" << endl;
		cout << " 6. .display()" << endl;
		cout << " 7. .clearScreeen()" << endl << endl;
		cin >> option;
	
	    Node * new_node = new Node();
	
	    switch (option) {
	    case 0:
	    	break;
	    case 1:
			cout << "\n Input key dan value dari stack" << endl;
			cin >> key;
			cin >> data;
			new_node -> key = key;
			new_node -> data = data;
			s1.push(new_node);
			break;
	    case 2:
			cout << "\n Memanggil fungsi POP" << endl;
			new_node = s1.pop();
			cout << "\nStack teratas adalah " << endl;
			cout << "\n ID\t: " << new_node->key << endl;
			cout << " Data\t: " << new_node->data << endl;
			delete new_node;
			cout << endl;
			
			break;
	    case 3:
			if (s1.isEmpty())
				cout << " Tidak ada Stack" << endl;
			else
				cout << " Terdapat Stack" << endl;
			break;
	    case 4:
			if (s1.isEmpty()) {
				cout << " Tidak ada Stack" << endl;
			} else {
				cout << "\n Memanggil fungsi PEEK" << endl;
				new_node = s1.peek();
				cout << "\nStack teratas adalah " << endl;
				cout << "\n ID\t: " << new_node->key << endl;
				cout << " Data\t: " << new_node->data << endl;
			}
		break;
	    case 5:
			cout << "\n Memanggil fungsi COUNT" << endl;
			cout << " No of nodes in the Stack: " << s1.count() << endl;
			break;
	
	    case 6:
			cout << "\n Memanggil fungsi DISPLAY" << endl;
			s1.display();
			cout << endl;
			break;
	    case 7:
			system("cls");
			break;
		default:
		cout << "\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!" << endl;
	    }

	} while (option != 0);

  return 0;
}
