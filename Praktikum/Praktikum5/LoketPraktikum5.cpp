#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <unistd.h>

using namespace std;

//	Nama: Abdul Wasi' Al-Afif
//	NPM	: 20081010165

struct Node {
    int ID;
    string TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET; 
    Node* left;
    Node* right;
};

//	BST START ======================================================================================================================
//	================================================================================================================================
class LoketBST {
    public:
	    Node* root;
	    Node* find(Node*, int, string, string, string, string, string);
	    Node* findMin(Node*);
	    Node* findMax(Node*);
	    Node* remove(Node*, int, string, string, string, string, string);
	    void insert(Node*, int, string, string, string, string, string);
	    void destroyTree(Node*);
	    void inOrder(Node*);
		void display(Node *, int);
	    void preOrder(Node*);
	    void postOrder(Node*);
	    void levelOrder(Node*);
	    bool isLeafNode(Node*);
	    
	    LoketBST();
	    ~LoketBST();
	    void insert(int, string, string, string, string, string);
	    void destroyTree();
	    void display(int);
	    void displayPreOrder();
		void displayInOrder();
		void displayPostOrder();
	    Node* remove(int, string, string, string, string, string);
	    Node* find(int, string, string, string, string, string);
	    Node* getRoot();
	    int maxdepth();
};

LoketBST::LoketBST(){
    root = NULL;
}

LoketBST::~LoketBST(){
    destroyTree();
}

/*
	INSERT
	================================================================================================================================
*/
void LoketBST::insert(int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    if (root != NULL) {
        insert(root, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    } else {
        root = new Node;
        root->ID = key;
        root->TIPE_KENDARAAN = type_vehicle;
        root->NO_POLISI = police_number;
        root->WAKTU_MASUK = login_time;
        root->WAKTU_KELUAR = logout_time;
        root->KODE_TIKET = ticket_code;
        root->left = NULL;
        root->right = NULL;
    }
}

void LoketBST::insert(Node* leaf, int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    if (key < leaf->ID){
        if (leaf->left != NULL) {
            insert(leaf->left, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
        } else {
            leaf->left = new Node;
            leaf->left->ID = key;
            leaf->left->TIPE_KENDARAAN = type_vehicle;
            leaf->left->NO_POLISI = police_number;
            leaf->left->WAKTU_MASUK = login_time;
            leaf->left->WAKTU_KELUAR = logout_time;
            leaf->left->KODE_TIKET = ticket_code;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else {
        if (leaf->right != NULL) {
            insert(leaf->right, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
        } else {
            leaf->right = new Node;
            leaf->right->ID = key;
            leaf->right->TIPE_KENDARAAN = type_vehicle;
            leaf->right->NO_POLISI = police_number;
            leaf->right->WAKTU_MASUK = login_time;
            leaf->right->WAKTU_KELUAR = logout_time;
            leaf->right->KODE_TIKET = ticket_code;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
    }
    }
}

/*
	SEARCH
	================================================================================================================================
*/
Node* LoketBST::find(int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    return find(root, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
}

Node* LoketBST::find(Node* leaf, int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    if (leaf == NULL) {
        return NULL;
    } else if (key == leaf->ID) {
        return leaf;
    } else if (key < leaf->ID){
        return find(leaf->left, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    } else {
        return find(leaf->right, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    }
}

bool LoketBST::isLeafNode(Node* t){
    if (t != NULL && t->left == NULL && t->right == NULL){
        return true;
    }
    else {
        return false;
    }
}

Node* LoketBST::findMin(Node* t){
    if (t == NULL){
        return t;
    } else if (t->left == NULL){
        return t;
    } else {
        return findMin(t->left);
    }
}

Node* LoketBST::findMax(Node* t){
    if (t == NULL){
        return t;
    } else if (t->right == NULL){
        return t;
    } else {
        return findMax(t->right);
    }
}

/*
	REMOVE
	================================================================================================================================
*/
Node* LoketBST::remove(int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    return remove(root, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
}

Node* LoketBST::remove(Node* t, int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    Node* temp;

    if (t == NULL)
        return NULL;

    if (key < t->ID) {
        t->left = remove(t->left, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    } else if (key > t->ID) {
        t->right = remove(t->right, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    } 
    else {
        if (isLeafNode(t)){
            delete t;
            t = NULL;
        } else if (t->right && t->left) {
            Node* temp = findMin(t->right);
            t->ID = temp->ID;
            t->TIPE_KENDARAAN = temp->TIPE_KENDARAAN;
            t->NO_POLISI = temp->NO_POLISI;
            t->WAKTU_MASUK = temp->WAKTU_MASUK;
            t->WAKTU_KELUAR = temp->WAKTU_KELUAR;
            t->KODE_TIKET = temp->KODE_TIKET;
            t->right = remove(t->right, t->ID, t->TIPE_KENDARAAN, t->NO_POLISI, t->WAKTU_MASUK, t->WAKTU_KELUAR, t->KODE_TIKET);
        } else {
            temp = t;
            if (t->right == NULL)
                t = t->left;
            else if (t->left == NULL)
                t = t->right;
            delete temp;
        }
    }
    
    return t;
}

void LoketBST::destroyTree(){
    destroyTree(root);
}

void LoketBST::destroyTree(Node* leaf){
    if (leaf != NULL) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
    }

    delete leaf;
}

/*
	DISPLAY
	================================================================================================================================
*/
void LoketBST::display(int level){
	if (root != NULL){
		display(root, level);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

void LoketBST::display(Node *ptr, int level){
	int i;
	if (ptr != NULL){
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << " Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->ID;
		display(ptr->left, level + 1);
	}
}

void LoketBST::preOrder(Node* t){
    if (t != NULL) {
		cout << "\n ID\t\t: " << t->ID << endl;
		cout << " Tipe Kendaraan\t: " << t->TIPE_KENDARAAN << endl;
		cout << " No. Polisi\t: " << t->NO_POLISI << endl;
		cout << " Waktu Masuk\t: " << t->WAKTU_MASUK << endl;
		cout << " Waktu Keluar\t: " << t->WAKTU_KELUAR << endl;
		cout << " Kode Tiket\t: " << t->KODE_TIKET << endl;
        preOrder(t->left);
        preOrder(t->right);
    }
}

void LoketBST::displayPreOrder(){
	if (root != NULL){
		preOrder(root);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

void LoketBST::inOrder(Node* t){
    if (t != NULL) {
        inOrder(t->left);
		cout << "\n ID\t\t: " << t->ID << endl;
		cout << " Tipe Kendaraan\t: " << t->TIPE_KENDARAAN << endl;
		cout << " No. Polisi\t: " << t->NO_POLISI << endl;
		cout << " Waktu Masuk\t: " << t->WAKTU_MASUK << endl;
		cout << " Waktu Keluar\t: " << t->WAKTU_KELUAR << endl;
		cout << " Kode Tiket\t: " << t->KODE_TIKET << endl;
        inOrder(t->right);
    }
}

void LoketBST::displayInOrder(){
	if (root != NULL){
		inOrder(root);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

void LoketBST::postOrder(Node* t){
    if (t != NULL) {
        postOrder(t->left);
        postOrder(t->right);
        
		cout << "\n ID\t\t: " << t->ID << endl;
		cout << " Tipe Kendaraan\t: " << t->TIPE_KENDARAAN << endl;
		cout << " No. Polisi\t: " << t->NO_POLISI << endl;
		cout << " Waktu Masuk\t: " << t->WAKTU_MASUK << endl;
		cout << " Waktu Keluar\t: " << t->WAKTU_KELUAR << endl;
		cout << " Kode Tiket\t: " << t->KODE_TIKET << endl;
    }
}

void LoketBST::displayPostOrder(){
	if (root != NULL){
		postOrder(root);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

int maxDepth(Node* t){
    if (t == NULL) {
        return 0;
    } else {
        int ld = maxDepth(t->left);
        int rd = maxDepth(t->right);

        return (max(ld, rd) + 1);
    }
}

Node* LoketBST::getRoot(){
    return root;
}
//	BST END ========================================================================================================================
//	================================================================================================================================


//	AVL START ======================================================================================================================
//	================================================================================================================================
class LoketAVL{
	public:
		Node* root;
		int height(Node *);
		int diff(Node *);
		Node *rr_rotation(Node *);
		Node *ll_rotation(Node *);
		Node *lr_rotation(Node *);
		Node *rl_rotation(Node *);
		Node* balance(Node *);
	    Node* find(Node*, int, string, string, string, string, string);
	    Node* insert(Node*, int, string, string, string, string, string);
		void display(Node *, int);
		void inOrder(Node *);
		void preOrder(Node *);
		void postOrder(Node *);
	    Node* remove(Node*, int, string, string, string, string, string);
		Node* findMin(Node*);
		Node* findMax(Node*);
		
		LoketAVL();
	    void insert(int, string, string, string, string, string);
	    Node* remove(int, string, string, string, string, string);
	    Node* find(int, string, string, string, string, string);
	    void display(int);
	    void displayPreOrder();
		void displayInOrder();
		void displayPostOrder();
};

LoketAVL::LoketAVL(){
	root = NULL;
}

/*
	HEIGHT
	================================================================================================================================
*/
int LoketAVL::height(Node *temp){
	int h = 0;
	if (temp != NULL){
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int LoketAVL::diff(Node *temp){
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
	ROTATIONS
	================================================================================================================================
*/
Node *LoketAVL::rr_rotation(Node *parent){
	Node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

Node *LoketAVL::ll_rotation(Node *parent){
	Node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

Node *LoketAVL::lr_rotation(Node *parent){
	Node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

Node *LoketAVL::rl_rotation(Node *parent){
	Node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
	BALANCING
	================================================================================================================================
*/
Node *LoketAVL::balance(Node *temp){
	int bal_factor = diff(temp);
	if (bal_factor > 1){
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	} else if (bal_factor < -1) {
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

/*
	INSERT
	================================================================================================================================
*/
void LoketAVL::insert(int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    if (root != NULL) {
        insert(root, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    } else {
        root = new Node;
        root->ID = key;
        root->TIPE_KENDARAAN = type_vehicle;
        root->NO_POLISI = police_number;
        root->WAKTU_MASUK = login_time;
        root->WAKTU_KELUAR = logout_time;
        root->KODE_TIKET = ticket_code;
        root->left = NULL;
        root->right = NULL;
    }
}

Node *LoketAVL::insert(Node *root, int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
	if (key < root->ID) {
		if (root->left != NULL) {
				root->left = insert(root->left, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
		} else {
            root->left = new Node;
            root->left->ID = key;
            root->left->TIPE_KENDARAAN = type_vehicle;
            root->left->NO_POLISI = police_number;
            root->left->WAKTU_MASUK = login_time;
            root->left->WAKTU_KELUAR = logout_time;
            root->left->KODE_TIKET = ticket_code;
            root->left->left = NULL;
            root->left->right = NULL;
		}
		root = balance(root);
	} else if (key >= root->ID) {
		if (root->left != NULL) {
				root->right = insert(root->left, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
		} else {
            root->right = new Node;
            root->right->ID = key;
            root->right->TIPE_KENDARAAN = type_vehicle;
            root->right->NO_POLISI = police_number;
            root->right->WAKTU_MASUK = login_time;
            root->right->WAKTU_KELUAR = logout_time;
            root->right->KODE_TIKET = ticket_code;
            root->right->left = NULL;
            root->right->right = NULL;
		}
		root = balance(root);
	}
	return root;
}

/*
	REMOVE
	================================================================================================================================
*/
Node* LoketAVL::remove(int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    return remove(root, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
}

Node* LoketAVL:: remove(Node* t, int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
	Node* temp;
	
	if (t == NULL) return NULL;
	
	else if (key < t->ID) t->left = remove(t->left, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
	else if (key >t->ID) t->right = remove(t->right, key, type_vehicle, police_number, login_time, logout_time, ticket_code);

	else if (t->left && t->right) {
		temp = findMin(t->right);
		t->ID = temp->ID;
        t->TIPE_KENDARAAN = temp->TIPE_KENDARAAN;
        t->NO_POLISI = temp->NO_POLISI;
        t->WAKTU_MASUK = temp->WAKTU_MASUK;
        t->WAKTU_KELUAR = temp->WAKTU_KELUAR;
        t->KODE_TIKET = temp->KODE_TIKET;
		t->right = remove(t->right, t->ID, t->TIPE_KENDARAAN, t->NO_POLISI, t->WAKTU_MASUK, t->WAKTU_KELUAR, t->KODE_TIKET);
	}
	
	else {
		temp = t;
		if (t->left == NULL) t = t->right;
		else if (t->right == NULL) t = t->left;
		delete temp;
	}
	if (t == NULL) return t;
	
	t = balance(t);
}

/*
	SEARCH
	================================================================================================================================
*/
Node* LoketAVL::find(int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    return find(root, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
}

Node* LoketAVL::find(Node* t, int key, string type_vehicle, string police_number, string login_time, string logout_time, string ticket_code){
    if (t == NULL) {
        return NULL;
    } else if (key == t->ID) {
        return t;
    } else if (key < t->ID){
        return find(t->left, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    } else {
        return find(t->right, key, type_vehicle, police_number, login_time, logout_time, ticket_code);
    }
}

Node* LoketAVL::findMin(Node* t) {
	if (t == NULL) return NULL;
	else if (t->left == NULL) return t;
	else return findMin(t->left);
}
Node* LoketAVL:: findMax(Node* t) {
	if (t == NULL) return NULL;
	else if (t->right == NULL) return t;
	else return findMax(t->right);
}

/*
	DISPLAY
	================================================================================================================================
*/
void LoketAVL::display(int level){
	if (root != NULL){
		display(root, level);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

void LoketAVL::display(Node *ptr, int level){
	int i;
	if (ptr != NULL){
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << " Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->ID;
		display(ptr->left, level + 1);
	}
}

void LoketAVL::preOrder(Node *t){
	if (t != NULL){
		cout << "\n ID\t\t: " << t->ID << endl;
		cout << " Tipe Kendaraan\t: " << t->TIPE_KENDARAAN << endl;
		cout << " No. Polisi\t: " << t->NO_POLISI << endl;
		cout << " Waktu Masuk\t: " << t->WAKTU_MASUK << endl;
		cout << " Waktu Keluar\t: " << t->WAKTU_KELUAR << endl;
		cout << " Kode Tiket\t: " << t->KODE_TIKET << endl;
		preOrder(t->left);
		preOrder(t->right);
	}
}

void LoketAVL::displayPreOrder(){
	if (root != NULL){
		preOrder(root);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

void LoketAVL::inOrder(Node *t) {
	if (t != NULL){
		inOrder(t->left);
		cout << "\n ID\t\t: " << t->ID << endl;
		cout << " Tipe Kendaraan\t: " << t->TIPE_KENDARAAN << endl;
		cout << " No. Polisi\t: " << t->NO_POLISI << endl;
		cout << " Waktu Masuk\t: " << t->WAKTU_MASUK << endl;
		cout << " Waktu Keluar\t: " << t->WAKTU_KELUAR << endl;
		cout << " Kode Tiket\t: " << t->KODE_TIKET << endl;
		inOrder(t->right);
	}
}

void LoketAVL::displayInOrder(){
	if (root != NULL){
		inOrder(root);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

void LoketAVL::postOrder(Node *t){
	if (t != NULL){
		postOrder(t->left);
		postOrder(t->right);
		cout << "\n ID\t\t: " << t->ID << endl;
		cout << " Tipe Kendaraan\t: " << t->TIPE_KENDARAAN << endl;
		cout << " No. Polisi\t: " << t->NO_POLISI << endl;
		cout << " Waktu Masuk\t: " << t->WAKTU_MASUK << endl;
		cout << " Waktu Keluar\t: " << t->WAKTU_KELUAR << endl;
		cout << " Kode Tiket\t: " << t->KODE_TIKET << endl;
	}
}

void LoketAVL::displayPostOrder(){
	if (root != NULL){
		postOrder(root);
	} else {
    	cout << "\n Tidak ada data!" << endl;
	}
}

//	AVL END ========================================================================================================================
//	================================================================================================================================

void intro(){
	printf(" *********************************************************************************************************\n");
	printf(" *********************************************************************************************************\n");
	printf(" *************                                Program \"Loket\"                                *************\n");
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
    LoketBST* bst_tree = new LoketBST();
    LoketAVL* avl_tree = new LoketAVL();
    
	int choice, ID;
	string back, condition, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET; 
	
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
			cin >> choice;
			
			switch (choice) {
			    case 1:
					insert_data:
				    	system("cls");
						cout << "\n Pilih Metode Input Data" << endl;
						cout << " [1]. BST" << endl;
						cout << " [2]. AVL" << endl;
						cout << " ==========================================" << endl;
						cout << " Masukkan Pilihan (1-2): ";
						cin >> choice;
						
					    switch (choice) {
					    case 1:
					    	do {
						    	system("cls");
								cout << "\n #BST: Insert Data" << endl;
								cout << " ==========================================" << endl;
								cout << " ID\t\t: ";
								cin >> ID;
								cout << " Tipe Kendaraan\t: ";
								cin >> TIPE_KENDARAAN;
								cout << " No. Polisi\t: ";
								cin >> NO_POLISI;
								cout << " Waktu Masuk\t: ";
								cin >> WAKTU_MASUK;
								cout << " Waktu Keluar\t: ";
								cin >> WAKTU_KELUAR;
								cout << " Kode Tiket\t: ";
								cin >> KODE_TIKET;
								
								bst_tree->insert(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET);
								
								cout << "\n Insert data berhasil!" << endl;
				
								printf("\n Masukkan data lagi? (Y/T): ");
								cin >> back;
								
								if (back == "t" || back == "T") {
									goto main;
								}
							} while (back == "y" || back == "Y");
							break;
						case 2:
					    	do {
						    	system("cls");
								cout << "\n #AVL: Insert Data" << endl;
								cout << " ==========================================" << endl;
								cout << " ID\t\t: ";
								cin >> ID;
								cout << " Tipe Kendaraan\t: ";
								cin >> TIPE_KENDARAAN;
								cout << " No. Polisi\t: ";
								cin >> NO_POLISI;
								cout << " Waktu Masuk\t: ";
								cin >> WAKTU_MASUK;
								cout << " Waktu Keluar\t: ";
								cin >> WAKTU_KELUAR;
								cout << " Kode Tiket\t: ";
								cin >> KODE_TIKET;
								
								avl_tree->insert(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET);
								
								cout << "\n Insert data berhasil!" << endl;
								
								printf("\n Masukkan data lagi? (Y/T): ");
								cin >> back;
								
								if (back == "t" || back == "T") {
									goto main;
								}
							} while (back == "y" || back == "Y");
							break;
						default:
							cout << "\n Mohon maaf, pilihan anda tidak termasuk dalam menu!" << endl;
							sleep(1);
							goto insert_data;
					    }
				break;
			    case 2:
					read_data:
				    	system("cls");
						cout << "\n Pilih Metode Read Data" << endl;
						cout << " [1]. BST Tree Structure" << endl;
						cout << " [2]. BST - preOrder" << endl;
						cout << " [3]. BST - inOrder" << endl;
						cout << " [4]. BST - postOrder" << endl;
						cout << " [5]. AVL Tree Structure" << endl;
						cout << " [6]. AVL - preOrder" << endl;
						cout << " [7]. AVL - inOrder" << endl;
						cout << " [8]. AVL - postOrder" << endl;
						cout << " ==========================================" << endl;
						cout << " Masukkan Pilihan (1-6): ";
						cin >> choice;
						
					    switch (choice) {
					    case 1:
					    	system("cls");
							cout << "\n #BST Tree Structure Data" << endl;
							cout << " ==========================================" << endl;
							bst_tree->display(1);
							break;
					    case 2:
					    	system("cls");
							cout << "\n #BST - preOrder: Read Data" << endl;
							cout << " ==========================================" << endl;
							bst_tree->displayPreOrder();
							break;
						case 3:
					    	system("cls");
							cout << "\n #BST - inOrder: Read Data" << endl;
							cout << " ==========================================" << endl;
							bst_tree->displayInOrder();
							break;
						case 4:
					    	system("cls");
							cout << "\n #BST - postOrder: Read Data" << endl;
							cout << " ==========================================" << endl;
							bst_tree->displayPostOrder();
							break;
						case 5:
					    	system("cls");
							cout << "\n #AVL Tree Structure Data" << endl;
							cout << " ==========================================" << endl;
							avl_tree->display(1);
							break;
						case 6:
					    	system("cls");
							cout << "\n #AVL - preOrder: Read Data" << endl;
							cout << " ==========================================" << endl;
							avl_tree->displayPreOrder();
							break;
						case 7:
					    	system("cls");
							cout << "\n #AVL - inOrder: Read Data" << endl;
							cout << " ==========================================" << endl;
							avl_tree->displayInOrder();
							break;
						case 8:
					    	system("cls");
							cout << "\n #AVL - postOrder: Read Data" << endl;
							cout << " ==========================================" << endl;
							avl_tree->displayPostOrder();
							break;
						default:
							cout << "\n Mohon maaf, pilihan anda tidak termasuk dalam menu!" << endl;
							sleep(1);
							goto read_data;
					    }
				break;
			    case 3:
					delete_data:
				    	system("cls");
						cout << "\n Pilih Metode Delete Data" << endl;
						cout << " [1]. BST -> destroy" << endl;
						cout << " [2]. BST -> remove" << endl;
						cout << " [3]. AVL -> destroy" << endl;
						cout << " [4]. AVL -> remove" << endl;
						cout << " ==========================================" << endl;
						cout << " Masukkan Pilihan (1-4): ";
						cin >> choice;
						
					    switch (choice) {
					    case 1:
					    	system("cls");
							cout << "\n #BST - destroy" << endl;
							cout << " ==========================================" << endl;
							cout << " Method destroy adalah method yang digunakan untuk menghapus semua data. ";
							
							cout << "\n\n Yakin ingin menghapus semua data di BST_TREE? (Y/T): ";
							cin >> condition;

							if (condition == "y" || condition == "Y") {
								delete bst_tree;
								cout << "\n Berhasil menghapus semua data!" << endl;
							} else {
								cout << "\n Gagal menghapus semua data!" << endl;
							}
							break;
						case 2:
					    	system("cls");
							cout << "\n #BST - remove" << endl;
							cout << " ==========================================" << endl;
							cout << " Method remove adalah method yang digunakan untuk menghapus data tertentu.";
							
							cout << "\n\n Hapus data dengan ID: ";
							cin >> ID;
							
							if (bst_tree->find(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET)) {
								cout << "\n Data dengan ID " << ID << " ditemukan!"<< endl;
								cout << "\n Yakin ingin menghapus data? (Y/T): ";
								cin >> condition;
	
								if (condition == "y" || condition == "Y") {
									bst_tree->remove(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET);
									
									cout << "\n Berhasil menghapus data dengan ID: " << ID << "!" << endl;
								} else {
									cout << "\n Gagal menghapus data dengan ID: " << ID << "!" << endl;
								}
							} else {
								cout << "\n Data dengan ID " << ID << " tidak ditemukan!"<< endl;
							}
							break;
						case 3:
					    	system("cls");
							cout << "\n #AVL - destroy" << endl;
							cout << " ==========================================" << endl;
							cout << " Method destroy adalah method yang digunakan untuk menghapus semua data. ";
							
							cout << "\n\n Yakin ingin menghapus semua data di AVL_TREE? (Y/T): ";
							cin >> condition;

							if (condition == "y" || condition == "Y") {
								delete avl_tree;
								cout << "\n Berhasil menghapus semua data!" << endl;
							} else {
								cout << "\n Gagal menghapus semua data!" << endl;
							}
							break;
						case 4:
					    	system("cls");
							cout << "\n #AVL - remove" << endl;
							cout << " ==========================================" << endl;
							cout << " Method remove adalah method yang digunakan untuk menghapus data tertentu.";
							
							cout << "\n\n Hapus data dengan ID: ";
							cin >> ID;
							
							if (avl_tree->find(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET)) {
								cout << "\n Data dengan ID " << ID << " ditemukan!"<< endl;
								cout << "\n Yakin ingin menghapus data? (Y/T): ";
								cin >> condition;
	
								if (condition == "y" || condition == "Y") {
									avl_tree->remove(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET);
									
									cout << "\n Berhasil menghapus data dengan ID: " << ID << "!" << endl;
								} else {
									cout << "\n Gagal menghapus data dengan ID: " << ID << "!" << endl;
								}
							} else {
								cout << "\n Data dengan ID " << ID << " tidak ditemukan!"<< endl;
							}
							break;
						default:
							cout << "\n Mohon maaf, pilihan anda tidak termasuk dalam menu!" << endl;
							sleep(1);
							goto delete_data;
					    }
				break;
			    case 4:
					search_data:
				    	system("cls");
						cout << "\n Pilih Metode Search Data" << endl;
						cout << " [1]. BST" << endl;
						cout << " [2]. AVL" << endl;
						cout << " ==========================================" << endl;
						cout << " Masukkan Pilihan (1-2): ";
						cin >> choice;
						
					    switch (choice) {
					    case 1:
					    	system("cls");
							cout << "\n #BST" << endl;
							cout << " ==========================================" << endl;
							cout << "\n Masukkan ID data yang dicari: ";
							cin >> ID;
							
							if (bst_tree->find(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET)) {
								cout << "\n Data dengan ID " << ID << " ditemukan!"<< endl;
							} else {
								cout << "\n Data dengan ID " << ID << " tidak ditemukan!"<< endl;
							}
							break;
						case 2:
					    	system("cls");
							cout << "\n #AVL" << endl;
							cout << " ==========================================" << endl;
							cout << "\n Masukkan ID data yang dicari: ";
							cin >> ID;
							
							if (avl_tree->find(ID, TIPE_KENDARAAN, NO_POLISI, WAKTU_MASUK, WAKTU_KELUAR, KODE_TIKET)) {
								cout << "\n Data dengan ID " << ID << " ditemukan!"<< endl;
							} else {
								cout << "\n Data dengan ID " << ID << " tidak ditemukan!"<< endl;
							}
							break;
						default:
							cout << "\n Mohon maaf, pilihan anda tidak termasuk dalam menu!" << endl;
							sleep(1);
							goto search_data;
					    }
				break;
			    case 5:
					close();
				break;
				default:
					cout << "\n Mohon maaf, pilihan anda tidak termasuk dalam menu!" << endl;
					goto main;
			    }
		
		printf("\n Ingin kembali ke menu ? (Y/T): ");
		cin >> back;

	} while (back == "y" || back == "Y");
	
    return 0;
}