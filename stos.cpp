#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct Node{
    string data;
    Node*next=nullptr;
};

void odloz(Node*&head, string data){
    
    if(head==nullptr){
        Node*head=new Node;
        head->next=nullptr;
        head->data=data;
    }
    
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    
    Node*new1=new Node;
    new1->data=data;
    new1->next=nullptr;
    temp->next=new1;
}

void zdejmij(Node*&head){
    if(!head){
        cout<<"Stos jest pusty";
    }
    Node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    
}

void wypisz(Node*&head){
    if(!head){
        cout<<"Stos jest pusty";
    }
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main(){
    
    Node*head=new Node;
    head->next=nullptr;
    head->data="Ala";
    
    odloz(head, "ma");
    odloz(head, "kota");
    wypisz(head);
    return 0;
}
