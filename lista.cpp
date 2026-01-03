#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct Node{
    int data;
    Node*next=nullptr;
};

struct List{
    
    Node* head=nullptr;
    
    void add(int number)
    {
        Node*new_number=new Node;
        new_number->data=number;
        
        if(head==nullptr)
        {
            head=new_number;
        }
        else
        {
            Node* current=head;
            while(current->next!=nullptr)
            {
                current=current->next;
            }
            
            current->next=new_number;
        }
    }
    
    void print(){
        
        for(Node*current=head; current!=nullptr; current=current->next)
        {
            cout<<current->data<<" ";
        }
    }
    
    void reverse_print(Node*temp){
        
        if(temp==nullptr) return;
        reverse_print(temp->next);
        cout<<temp->data<<" ";
        
    }
    
    void print_reverse(){
        reverse_print(head);
       
    }
    
    void clean(){
        
        Node *current=head;
        
        while(current!=nullptr)
        {
            Node*temp=current;
            current=current->next;
            delete temp;
        }
        
        head=nullptr;
    }
    
    void insert(int number, int position){
        Node*new_number=new Node;
        new_number->data=number;
        
        if(position<=0 || head==nullptr)
        {
            new_number->next=head;
            head=new_number;
            return;
        }
        
        Node* current=head;
        int index=0;
        while(current->next !=nullptr && index<position-1)
        {
            current=current->next;
            index++;
        }
        
        new_number->next=current->next;
        current->next=new_number;
    }
    
    void remov_e(int position)
    {
        if(head == nullptr || position < 0)
        return;
        
        
        if(position==0)
        {
            Node*temp=head;
            head=temp->next;
            delete temp;
            return;
        }
        else
        {
            Node*current=head;
            int index=0;
            while(current->next !=nullptr && index<position-1)
            {
                current=current->next;
                index++;
            }
            
            if(current->next!=nullptr)
            {
                Node*temp=current->next;
                current->next=temp->next;
                delete temp;
            }
           
            
        }
        
        
    }
    
    void swap(int position1, int position2){
        
        if(position1==position2) return;
        
        Node*node1=head;
        Node*node2=head;
        int index1=0, index2=0;
        
         while(node1!=nullptr && index1<position1)
        {
            node1=node1->next;
            index1++;
        }
        while(node2!=nullptr && index2<position2)
        {
            node2=node2->next;
            index2++;
        }
        
        if(node1==nullptr || node2==nullptr)
        return;
        
        int temp=node1->data;
        node1->data=node2->data;
        node2->data=temp;
    }
};



int main()
{
    List list;
    
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.print();
    cout<<endl;
    list.swap(1,2);
    list.swap(3,4);
    list.print();
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

struct List {
    Node* head = nullptr;

    void add(int number) {
        Node* new_node = new Node;
        new_node->data = number;
        if(head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while(current->next != nullptr)
                current = current->next;
            current->next = new_node;
        }
    }

    void insert(int number, int position) {
        Node* new_node = new Node;
        new_node->data = number;
        if(position <= 0 || head == nullptr) {
            new_node->next = head;
            head = new_node;
            return;
        }
        Node* current = head;
        int index = 0;
        while(current->next != nullptr && index < position-1) {
            current = current->next;
            index++;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    void remove_at(int position) {
        if(head == nullptr || position < 0) return;
        if(position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        int index = 0;
        while(current->next != nullptr && index < position-1) {
            current = current->next;
            index++;
        }
        if(current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void clear() {
        Node* current = head;
        while(current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void swap_positions(int pos1, int pos2) {
        if(pos1 == pos2) return;
        Node* node1 = head;
        Node* node2 = head;
        int idx1 = 0, idx2 = 0;
        while(node1 != nullptr && idx1 < pos1) { node1 = node1->next; idx1++; }
        while(node2 != nullptr && idx2 < pos2) { node2 = node2->next; idx2++; }
        if(node1 == nullptr || node2 == nullptr) return;
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }

    void print() {
        cout << "[";
        Node* current = head;
        while(current != nullptr) {
            cout << setw(3) << current->data;
            current = current->next;
        }
        cout << "]" << endl;
    }

    void reverse_print(Node* node) {
        if(node == nullptr) return;
        reverse_print(node->next);
        cout << setw(3) << node->data;
    }

    void print_reverse() {
        cout << "[";
        reverse_print(head);
        cout << "]" << endl;
    }
};

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cerr << "Podaj nazwe pliku z komendami!" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if(!file) {
        cerr << "Nie mozna otworzyc pliku!" << endl;
        return 1;
    }

    List list;
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if(command == "dodaj") {
            int num; ss >> num;
            list.add(num);
        }
        else if(command == "wstaw") {
            int num, pos; ss >> num >> pos;
            list.insert(num, pos);
        }
        else if(command == "usun") {
            int pos; ss >> pos;
            list.remove_at(pos);
        }
        else if(command == "wyczysc") {
            list.clear();
        }
        else if(command == "wypisz") {
            list.print();
        }
        else if(command == "wypisz_odwrotnie") {
            list.print_reverse();
        }
        else if(command == "zamien") {
            int pos1, pos2; ss >> pos1 >> pos2;
            list.swap_positions(pos1, pos2);
        }
    }

    return 0;
}
