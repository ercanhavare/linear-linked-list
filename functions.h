/*
 * LinkedList.h
 *
 *      Author: Ercan Havare
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include "linkedlist.h"
using namespace std;

int countlist(struct node * header){//completed

	struct node * headertemp;
	int count = 0;

	for(headertemp=header;headertemp!=NULL;headertemp=headertemp->next){
		//cout<<headertemp->data<<" ";
		count++;//count nodes
	}
	cout<<endl;
	return count;
}//////////////////////////////////////////////////////////////////////////////////////////////////


struct node * array2list (struct node * header, int a[], int size){//completed
//completed
	for(int i=0;i<size;i++){
		if(countlist(header)==0 || (header==NULL)){
			//cout<<"size 0"<<endl;
			//if size of linked list zero it will work
			header=insertFront(header,a[i]);
		}else{
			//cout<<"size 1"<<endl;
				header=insertBack(header,a[i]);
		}

		//cout<<a[i]<<" ";
	}

}//////////////////////////////////////////////////////////////////////////////////////////////////

struct node * insertn (struct node * header,int n,int x){//i have a problem about middle node, it does not add
	struct node * temp=header;
	if(n==1){
		header = insertFront(header,x);

	}else if((n>1) && (n<countlist(header))){
		//cout<<x<<endl;
		for(int i=0;i<n-2;i++){
			header=header->next;
		}
		temp=(struct node *) malloc(sizeof(struct node));
		temp->next=header->next;
		header->next=temp;
		temp->data=x;
		//return temp;

	}else{
		header = insertBack(header,x);
	}


}//////////////////////////////////////////////////////////////////////////////////////////////////

int multlist (struct node * header){//completed
	int m=1;

	struct node * headertemp;
	headertemp=header;

	while(headertemp!=NULL){
		m*=headertemp->data;
		headertemp=headertemp->next;
	}

	return m;
}/////////////////////////////////////////////////////////////////////////////////////////////

int multLL (struct node *header){//completed
	struct node * headertemp;
	headertemp=header;

	if(headertemp==NULL){
		return 1;//empty
	}

	return headertemp->data*multLL(headertemp->next);
}///////////////////////////////////////////////////////////////////////////////////////////////

void updatenth (struct node * header, int n){//completed
	struct node * headertemp;
	headertemp=header;
	//cout<<"middle1";
         if(headertemp==NULL){
					  cout<<"==================================\n";
            cout<<"Empty!"<<endl;
						cout<<"==================================\n";
         }//empty

	int i;
	for(i=0;i<=n-2;i++){
      headertemp=headertemp->next;
      //cout<<"middle2";
    }
     headertemp->data*=5;//update
    //cout<<"stop";
}//////////////////////////////////////////////////////////////////////////////////////////////////

struct node * deleteList (struct node * header){//completed
//i changed type of function void to struct
//because does not work
	struct node * temp1=header;
	struct node * temp2;

	while(temp1!=NULL){
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
	}
	header=NULL;
}////////////////////////////////////////////////////////////////////////////////////////////////

void printLL(struct node * header){//this function does not list in menu structure
	struct node * temp = header;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}




#endif /* FUNCTIONS_H_ */
