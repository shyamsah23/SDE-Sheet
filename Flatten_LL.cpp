
Node* mergeSorted(Node* l1,Node* l2){
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    
    Node* newHead=NULL;
    if(l1->data<l2->data)
    {
        newHead=l1;
        newHead->child=mergeSorted(l1->child,l2);
        
                                   
    }
    else
    {
        newHead=l2;
        newHead->child=mergeSorted(l1,l2->child);
       
    }
    
    return newHead;
}

Node* flattenLinkedList(Node* head) 
{
    if(head==NULL)
    {
        return NULL;
    }
	stack<Node*> st;
    Node* temp=head;
    while(temp!=NULL)
    {
        st.push(temp);
        temp=temp->next;
    }
    
    if(st.size()==1)
    {
        return st.top();
    }
    
   
    while(st.size()!=1)
    {
        Node* l1=st.top();
        st.pop();
        l1->next=NULL;
        Node* l2=st.top();
        l2->next=NULL;
        st.pop();
        
        Node * res=mergeSorted(l1,l2);
        st.push(res);
    }
    
    return st.top();
}
