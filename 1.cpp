//LINKED LIST //STACK!!(FOR MORE CHECK MY CATETAN)
#include<stdio.h>
#include<stdlib.h>

int index; int node;

struct data{
	int value;
	struct data *next;		//next aja karena hanya single linked list
} *head,*tail,*curr;		//curr = current


void cls(){
	for(int i=0; i<15; i++){
	printf("\n");
	}				//test
}

//if this works then i now know how to use git

void pushdepan(int x){
	curr = (struct data*)malloc(sizeof(struct data));
	curr ->value=x;
	if(head==NULL){
		head=tail=curr;
		head->next=NULL;
	}else{
		curr->next=head;
		head=curr;
	}
}


void pushbelakang(int x){
	curr = (struct data*)malloc(sizeof(struct data));
	curr ->value=x;
	if(head==NULL){
		head=tail=curr;
		head->next=NULL;
	}else{
		tail->next=curr;
		tail=curr;
		tail->next=NULL;	//Karena paling belakang harus NUUUUUUUUUUUULLLLLLLL
	}
}

void PMafter(int x, int y){
	curr = (struct data*)malloc(sizeof(struct data));
	curr ->value=x;
	if(head==NULL){
		head=tail=curr;
		head->next=NULL;
	}else{
		struct data *node=head;
		while(node->value != y) node = node->next;
		curr->next = node->next;
		node->next = curr;
}
}


void PMbefore(int x, int y){
	curr = (struct data*)malloc(sizeof(struct data));
	curr ->value=x;
	if(head==NULL){
		head=tail=curr;
		head->next=NULL;
	}else{
		struct data *node=head;
		while(node->next->value != y) node = node->next;
		curr->next = node->next;
		node->next = curr;
}
}

void popdepan(){
	if(head!=NULL){
	curr = head;
	head = head->next;
	free(curr);
	}
}

void popbelakang(){
	if(head!=NULL){
	curr = head;
	while(curr->next != tail)curr=curr->next;
	tail = curr;
	free(tail->next);
	tail->next=NULL;
	}
}

void popall(){
while(head!=NULL) popdepan;
}


void popsearch(int x){
	curr=head;
	while(curr->next->value!=x) curr=curr->next;
	struct data *del=curr->next;
	curr->next=del->next;
	free(del);

}

void view(){
	curr=head;
	while(curr != NULL){
	printf("%d ", curr->value);
	curr = curr -> next;
	index++;
	}


}





int main(){
	int input;
	int angka,
	index = 0;
	do{
	cls();
	view();
	printf("\n");
	printf("1. Push Depan\n");
	printf("2. Push Belakang\n");
	printf("3. Push Mid After\n");
	printf("4. Push Mid Before\n");
	printf("5. Pop Depan\n");
	printf("6. Pop belakang\n");
	printf("7. Pop All\n");
	printf("8. Pop xxxxxxxxx\n");
	printf("9. Exit\n");
	printf(">> ");
	scanf("%d", &input); fflush(stdin);

	switch (input){
	case 1: 
		printf("Input Angka\n >>");
		scanf("%d", &angka); fflush(stdin);
		pushdepan(angka);
		break;

	case 2:
		printf("Input Angka\n >>");
		scanf("%d", &angka); fflush(stdin); 
		pushbelakang(angka);
		break;

	case 3:
		printf("Input angka: ");
		scanf("%d", &angka); fflush(stdin); 
		printf("Abis angka berapa: ");
		scanf("%d", &node); fflush(stdin); 
		PMafter(angka, node);
		break;

	case 4:
		printf("Input angka: ");
		scanf("%d", &angka); fflush(stdin); 
		printf("sebelom angka berapa: ");
		scanf("%d", &node); fflush(stdin); 
		PMbefore(angka, node);
		break;

	case 5: popdepan();
		break;

	case 6: popbelakang();
		break;

	case 7: popall();
		break;

	case 8: printf("Input angka: ");
		scanf("%d", &angka); fflush(stdin); 
		popsearch(angka);
		break;
	}



	}while(input!=9);











getchar();
return 0;
}
