#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data =val;
        next=NULL;
    }
};
void insertAtTail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
       head=n;
       return; 
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void deleteAthead(node* &head){
    head=head->next;
}
void deleteAtend(node* &head){
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
};
void deletekey(node* &head,int key){
    node* temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}


void deleteKeyAtGivenIndex(node* head,int position){
    node* temp=head;    
    for(int i=0;i<position-1;i++){
        temp=temp->next;
        
    }
    temp->next=temp->next->next;
}
int length(node* head ){
    int c=0;
    node* temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
   cout<< c<<endl;
   return 0;
}
void searchForElement(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            cout<<"element Found"<<endl;
            break;
        }
        if(temp->next==NULL) cout<<"Element Not Found"<<endl;
        temp=temp->next;

    }
}
void nthnode(node* head,int n){
    node* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        if(c==n){
            cout<<temp->data<<endl;
        }
        temp=temp->next;

       
    }
}
int forReturninglength(node* head ){
    int c=0;
    node* temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
   return c;
}
void nthnodefromend(node* head,int n){
    node* temp=head;
    int c=0;
    int m=abs(forReturninglength(head)-n);
    while(temp!=NULL){
        c++;
        if(c==m){
            cout<<temp->next->data<<endl;
        }
        temp=temp->next;

       
    }
}
int  count(node* head,int val){
    node* temp=head;
    int c=0;
    while(temp!=NULL){
        if(temp->data==val){
            c++;
            
        }
        temp=temp->next;
    }
    cout<<c<<endl;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,-3);
    insertAtTail(head,8);
    insertAtTail(head,79);
    insertAtTail(head,84);
    insertAtTail(head,0);
    insertAtTail(head,44);
    insertAtTail(head,644);
    length(head);
    display(head);
    deletekey(head,8);
    length(head);
    display(head);
    insertAtTail(head,22);
    length(head);
    display(head);
    deleteKeyAtGivenIndex(head,3);
    length(head);
    display(head);
    searchForElement(head,19);  
    nthnode(head,3);
    nthnodefromend(head,2);
    count(head,22);



};








































