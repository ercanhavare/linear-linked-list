/*
 * linkedlist.h
 *
 *      Author: Ercan Havare
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include <cstdlib>
using namespace std;


struct node{
	int data;
	struct node *next;
};

int is_empty(struct node * header){
	if(header==NULL){
		return 1;
	}else{
		return 0;
	}

}

struct node * new_node(int d){//Created new node
	struct node * temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp -> data = d;
	temp -> next = NULL;
	return temp;
}

struct node * insertFront(struct node * header, int inf){
	struct node * temp;
	temp = new_node(inf);
	temp -> next = header;
	header = temp;
	return header;
}

struct node * insertBack(struct node * header, int d){
	struct node * temp, * headertemp;
	temp = new_node(d);

	if(header==NULL){
		header=temp;
		return header;
	}

	headertemp = header;
	while(headertemp->next!=NULL)
		headertemp = headertemp->next;
	headertemp -> next = temp;
	return header;
}

void insertAfter(struct node * afterNode, int d){
	struct node * temp;
	temp = new_node(d);
	temp->next = afterNode->next;
	afterNode->next=temp;
}

struct node * deleteBack(struct node * header){
	struct node *temp, *headertemp;

	if(header==NULL){
		return header;
	}


	if(header->next==NULL){
		free(header);
		header=NULL;
		return header;
	}

	headertemp=header;
	while(headertemp->next->next!=NULL)
		headertemp=headertemp->next;

	temp=headertemp->next;
	headertemp->next=NULL;
	free(temp);
	return header;
}

struct node * deleteFront(struct node * header){
	struct node * temp;

	if(header==NULL){
		return header;
	}


	temp=header;
	header=header->next;
	free(temp);
	return header;
}

void deleteAfter(struct node * afterNode){
	struct node * temp;

	if((afterNode->next==NULL) || (afterNode==NULL)){
		return;
	}

	temp = afterNode->next;
	afterNode->next = temp->next;
	free(temp);
}


#endif /* LINKEDLIST_H_ */
