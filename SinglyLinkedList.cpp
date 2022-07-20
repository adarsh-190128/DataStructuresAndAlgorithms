#include<bits/stdc++.h>
using namespace std;
// ****************************************Create a new class which holds data,next node address*************************************
class node{
    public:
    int data;
    node* next;
    node(int val){
        data =val;
        next=NULL;
    }
};

// ****************************************Insert At Tail*************************************


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

// ****************************************Delete At Head*************************************


void deleteAthead(node* &head){
    head=head->next;
}

// ****************************************Delete At end *************************************


void deleteAtend(node* &head){
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
};

// ****************************************Delete Specified Key*************************************


void deletekey(node* &head,int key){
    node* temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

// ****************************************Delete Give At specific Index*************************************



void deleteKeyAtGivenIndex(node* head,int position){
    node* temp=head;    
    for(int i=0;i<position-1;i++){
        temp=temp->next;
        
    }
    temp->next=temp->next->next;
}

// ****************************************Length*************************************


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

// ****************************************Searching Of Element*************************************


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

// ****************************************Nth node*************************************


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

// ****************************************Nth node From end*************************************


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

// ****************************************COunt*************************************


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
    return 0;
}

// ****************************************Reverse*************************************


node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

// ****************************************Reverseknodes*************************************


node* reverseknodes(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reverseknodes(nextptr,k);
    }

    return prevptr;
}

// ****************************************Detect Cycle*************************************


bool detectCycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
           return true;
        }
    }
    return false;
}

// ****************************************Make_Cycle*************************************


void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp; 
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

// ****************************************Delete_CyCle*************************************


void deleteCycle(node* head){
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    
}

// ****************************************Appending Last K nOdes to start of Linked List*************************************


void AppendLastKNodesToStartOfLinkedList(node* &head,int k){
    int l=forReturninglength(head);
    int pos=l-k;
    node* temp=head;
    node* newhead;
    int count=1;
    while(temp!=NULL){
        if(count==pos){
            newhead=temp;
        }
        temp=temp->next;
        count++;


    }
    temp->next=head;
}
// ****************************************Display*************************************



void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,-1);
    insertAtTail(head,0);
    insertAtTail(head,1);
    insertAtTail(head,0);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    length(head);
    display(head);
    deletekey(head,4);
    length(head);
    display(head);
    insertAtTail(head,8);
    length(head);
    display(head);
    deleteKeyAtGivenIndex(head,3);
    length(head);
    display(head);
    searchForElement(head,6);  
    nthnode(head,3);
    nthnodefromend(head,2);
    count(head,1);
    node* newhead=reverse(head);
    display(newhead);
    int k=2;
    node* newhead1=reverseknodes(newhead,k );
    display(newhead1);
    cout<<detectCycle(newhead1)<<endl;
    makeCycle(newhead1,2);
    cout<<detectCycle(newhead1)<<endl;
    deleteCycle(newhead);
    cout<<detectCycle(newhead1)<<endl;
    AppendLastKNodesToStartOfLinkedList(newhead1,2);
    display(newhead1);


};


