#include<bits/stdc++.h>

using namespace std;

class bst_node{//declaring the elements of a node

public:

	int data;

	bst_node *right;

	bst_node *left;

};

class bst{

	bst_node* new_node(int d){//creating new node

		bst_node *new_bst_node = new bst_node();

		new_bst_node -> data = d;

		new_bst_node->left = new_bst_node->right = NULL;

		return new_bst_node;

	}

public:

	bst_node* insert(bst_node *root , int d){//insert elements(O(height of tree) = O(n))

		if(root == NULL){//insert first element

			return new_node(d);

		}	

		else if(d < root->data){//if element is less than root left insert

			root->left = insert(root->left , d);

		}	

		else if(d >= root->data){//if element is greater than root right insert

			root->right = insert(root->right , d);

		}
	
		return root;

	}

	bst_node* del(bst_node *root , int d){//O(height of tree) = O(n)

		if(root == NULL){

			return root;

		}

		if(d < root->data){

			root->left = del(root->left , d);

			return root;

		}

		else if(d > root->data){

			root->right = del(root->right , d);

			return root;

		}

		//we have reached the particular node

		//if only one chile exists

		if (root->left == NULL) {

			bst_node* temp = root->right;

			delete root;

			return temp;

		}

		else if (root->right == NULL) {

			bst_node* temp = root->left;

			delete root;

			return temp;

		}

		//if the node contains two children

		//the all first of the right element becomes the root

		//and pushing other elements similarly
	
		else{

			bst_node* succ_parent = root;

			bst_node* succ = root->right;

			while (succ->left != NULL) {

				succ_parent = succ;

				succ = succ->left;

			}

			if (succ_parent != root)

				succ_parent->left = succ->right;

			else
	
				succ_parent->right = succ->right;

			root->data = succ->data;

			delete succ;

			return root;

		}

	}

	bst_node* search(bst_node *root , int d){//O(log n)

		if(root == NULL || root->data == d){//if we have found the element or no element exists

			return root;

		}

		else if(d < root->data){//if element to be searched less that root data go left further

			return search(root->left , d);

		}

		return search(root->right , d);//else go right

	}

	void pre_order(bst_node *root){// root , left , right(O(n))

		if(root != NULL){

			cout<<root->data<<' ';

			pre_order(root->left);//prints left

			pre_order(root->right);//prints right

		}

	}

	void post_order(bst_node *root){// left , right , root (O(n))

		pre_order(root->left);//prints left

		pre_order(root->right);//prints right

		cout<<root->data<<' ';

	}

	void in_order(bst_node *root){// left , root , right (O(n))

		if(root != NULL){

			in_order(root->left);//prints left

			cout<<root->data<<' ';

			in_order(root->right);//prints right

		}

	}

};

int main(){//main with all functionalities

	bst b;

	bst_node *root = NULL;

	int choice ; char ch = 'y';

	while(ch == 'y'){

		cout<<"1.Insert\n2.Delete\n3.Search element\n4.Print\n5.Exit\n";

		cout<<"please enter your choice : ";

		cin>>choice;

		if(choice == 1){

			char ch1 = 'y';

			while(ch1 == 'y'){

				int no;
	
				cout<<"enter the elements to be inserted : ";

				cin>>no;

				root = b.insert(root , no);

				cout<<"do you want to insert more elements : ('y' for yes 'n' for no)";

				cin>>ch1;

			}

		}

		else if(choice == 2){

			int no;char ch1 = 'y';

			while(ch1 == 'y'){

				cout<<"enter the element to be deleted : ";

				cin>>no;

				root = b.del(root , no);

				cout<<"do you want to delete more elements : ('y' for yes 'n' for no)";

				cin>>ch1;
	
			}

		}

		else if(choice == 3){

			int no;

			cout<<"enter the element to be searched : ";

			cin>>no;

			if(b.search(root , no) != NULL){

				cout<<"element exists\n";

			}

			else{
	
				cout<<"element does not exists\n";

			}

		}

		else if(choice == 4){

			int ch1;

			cout<<"enter how to want to display the elements : \n";

			cout<<"1.pre_order\n"<<"2.post_order\n"<<"3.in_order\n";
	
			cout<<"please enter your choice : ";

			cin>>ch1;
	
			if(ch1 == 1){

				cout<<"PRE ORDER : \n";

				b.pre_order(root);

				cout<<'\n';

			}

			else if(ch1 == 2){

				cout<<"POST ORDER : \n";

				b.post_order(root);

				cout<<'\n';

			}

			else if(ch1 == 3){

				cout<<"IN ORDER : \n";

				b.in_order(root);

				cout<<'\n';

			}

			else{

				cout<<"entered a wrong choice for printing value\n";

			}

		}

		else if(choice >= 5){

			exit(EXIT_FAILURE);

		}

		cout<<"do you want to go to the main menu : ('y' for yes 'n' for no)";

		cin>>ch;

	}

	return 0;

}
