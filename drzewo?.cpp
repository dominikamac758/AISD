void dodaj(string slowo){
    
    int index=0;
    if(!root){
        Node*temp=new Node();
        temp->litera=slowo[0];
        root=temp;
        index=1;
    }
    
    Node*current=root;

    
    while(current->brat!=nullptr){
        
        if(current->litera==slowo[index])
        {
            index++;
            current=current->dziecko;
        }
    }
    
    if(current->brat==nullptr && current!=slowo[index]){
        
        Node*nowy=new Node();
        nowy->litera=slowo[index];
        
        current->brat=nowy;
    
        
    }else if(current->brat==nullptr && current==slowo[index]){
        
        current=current->dziecko;
    }
    
} 

