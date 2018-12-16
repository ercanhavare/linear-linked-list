//============================================================================
// Name        : Homework2.cpp
// Author      : Ercan Havare
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>

#include "functions.h"

using namespace std;

int main() {

	struct node * header=NULL;
	header=insertFront(header, 5);
	header=insertFront(header, 7);
	header=insertFront(header, 9);
	header=insertFront(header, 11);
	header=insertFront(header, 13);

	//insertAfter(header, 7);
	//insertBack(header, 9);

	int a[] = {9,1,4,7,3,6,8,2,1,5};
	int size=sizeof(a)/4;// number_of_item/value_of_integer
	int x,n;

	int key,keyn,key3;
	do{
		cout<<"\nMenu Structure\n-------------------------------------------\n";
		cout<<"1) Counts number of nodes"<<endl;
		cout<<"2) List of values stored in an array"<<endl;
		cout<<"3) Inserts a node with data x to n th"<<endl;
		cout<<"4) Product of elements"<<endl;
		cout<<"\ta) Conventional function with loop \tb) Recursive function"<<endl;
		cout<<"5) Multiplies the n th node(by 5)"<<endl;
		cout<<"6) Deletes all nodes"<<endl;
		cout<<"7) Exit"<<endl;
		cout<<"-------------------------------------------\n";
		cout<<"Please, enter your choose : ";
		cin>>key;

			switch (key) {
				case 1:
					cout<<"==================================";
					cout<<"It has "<< countlist(header)<<" nodes in Linear Linked List"<<endl;
					cout<<"==================================\n";
					break;

				case 2:
							array2list(header, a, size);
					break;

				case 3:
					cout<<"Please, enter data : ";
					cin>>x;

					cout<<"Please, enter the position : ";
					cin>>n;
						if(countlist(header)==0 || (n==1)){
							//if header is equal to null, does not add any number
							//this is solve problem
							//if n is equal to 1, it means root will change
								header=insertn(header, n, x);
						}else{
							insertn(header, n, x);
						}

					break;

				case 4:
					char key2;
				    do{ // we check the key , user what will enter
				  cout<<"a) Conventional function with loop\t\t";
				  cout<<"b) Recursive function\n\n";
				  cout<<"Please, enter your choose : ";
				  cin>>key2;
				    	//choose which one you want search type
				      if(key2=='A' || key2=='a'){
								cout<<"==================================\n";
				        cout<<multlist(header)<<endl; // for exit from loop we need write breake
								cout<<"==================================\n";
					break;
				      }else if(key2=='B' || key2=='b'){
								cout<<"==================================\n";
				        cout<<multLL(header)<<endl; // if we do not write break, we going to continue loop, it will not exit from loop
								cout<<"==================================\n";
					break;
				      }else{
						cout<<"\nPlease enter just [a-A or b-B]\n\n";
					  }// choose key --> finished

					}while((key!='A') || (key!='a') || (key!='B') || (key!='b'));

					//cout<<"Please, enter your choose (a or b): ";
					//cin>>key3;
					break;

				case 5:
            cout<<"Please, enter n th place : ";
            cin>>keyn;
            updatenth(header, keyn);
            //cout<<"start";
					break;

				case 6:
					//header=deleteFront(header);
					header=deleteList(header);
					if (header==NULL) {
						cout<<"==================================\n";
						cout<<"Deleted all of nodes"<<endl;
						cout<<"==================================\n";
					}else{
						cout<<"==================================\n";
						cout<<"Something wrong! Could not deleted!"<<endl;
						cout<<"==================================\n";
					}
					break;

				case 7:
					cout<<"==================================\n";
					cout<<"Goodbye :)\n";
					cout<<"==================================\n";
					break;

				case 8:
					cout<<"==================================\n";
					printLL(header);
						if(header==NULL){
							cout<<"Linked List is Empty!"<<endl;
						}
					cout<<"==================================\n";
					 break;

				default:
					cout<<"==================================\n";
					cout<<"Try again(1-7)\n";
					cout<<"==================================\n";
					break;
			}

	}while(key!=7);


    system("PAUSE");
	return 0;

}
