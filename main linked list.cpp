#include <iostream>
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node*next;
}Lnode, *List;

Lnode L;
List initList(){
	//initialization list
	List Ptrl;
	Ptrl = (List) malloc(sizeof(L));
	Ptrl->next=NULL;
	return Ptrl;
}
List createfromhead(List Ptrl,int x){
	List s;
	s=(List)malloc(sizeof(L));
	s->data=x;
	s->next=Ptrl->next;
	Ptrl->next=s;
	return Ptrl;
}

    int length(List Ptrl){
    	int length=0;
    	List p;
    	for (p=Ptrl->next;p!=NULL;p=p->next){
    		length++;
		}
    	//
    	return length;
	}
	List FindKth(List Ptrl,int i){
		int count=1;
		while ( count<= i){
			Ptrl=Ptrl->next;
			count++;
		}
		//
		return Ptrl;
	}
	List insert(List Ptrl,int i,int x){
		int j;
		List p;
        List newnode;
		p = FindKth(Ptrl, i-1);		
		
		p=Ptrl;
		for(j=0;j<i-1;j++)
		{
		p = p->next;	
			
		}
		
		
		newnode->next=(List)malloc(sizeof(L));
		newnode->data=x;
     	newnode->next=p->next;
     	p->next=newnode;
         
	}
	List Delete(List Ptrl,int i){
		int j;
		Ptrl = FindKth(Ptrl,i-1);
		Ptrl->next=Ptrl->next->next;

		return (Ptrl);
	}
	
	
	void print(List ptrl){//print the list
	  List start;
	  for(start=ptrl->next;start !=NULL;start=start->next)
	    printf("%d",start->data);
	}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List list, s;
	int m;
	list=initList();
	for(int i=1;i<5;i++){
		list=createfromhead(list,i);
	}
	printf("list data :");
	print(list);
	printf("\n");
	m=length(list);
	printf("length of the list:%d",m);
	printf("\n");
	Delete(list,2);
	printf("delete the second node :");
	print (list);
	printf("\n");
	m=length(list);
	printf("length of the list:%d",m);
	printf("\n");
	s=FindKth(list,3);
	printf("the third node is %d",s->data);
	
	return 0;
}
