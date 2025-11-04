#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;

};

void insert_at_beg(struct Node* *head, int d){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=d;

    temp->next=*head;
    *head=temp;

}


void insert_at_end(struct Node* *head, int d){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node*));
    newnode->data=d;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
        return;
    }

    struct Node* current=*head;

    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newnode;

}


void insert_pos(struct Node* *head, int d,int pos){
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node*));
         newnode->data=d;
    newnode->next=NULL;

    if(pos==1){
        newnode->next=*head;
        *head=newnode;
        return;
    }
    struct Node* current=*head;
    int c=1;
    while(c<pos-1 && current!=NULL){
        c++;
        current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;

}

void del_beg(struct Node* *head){
    struct Node* temp=*head;
    *head=(*head)->next;
    free(temp);

}





void print(struct Node*head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}



int main(){
    struct Node* n1=NULL;

insert_at_beg(&n1,10);
insert_at_beg(&n1,20);
insert_at_beg(&n1,30);
insert_at_beg(&n1,40);
print(n1);
del_beg(&n1);
print(n1);
}
