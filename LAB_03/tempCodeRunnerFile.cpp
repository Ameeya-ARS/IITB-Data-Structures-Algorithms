void Tree :: traverse(TraversalType_e tt, Node* ptr){
    if(tt==PRE_ORDER){
        if (ptr==NULL) return;
        cout << ptr->data << " ";
        traverse(PRE_ORDER, ptr->left);
        traverse(PRE_ORDER, ptr->right);
    }
    else if(tt==IN_ORDER){
        if (ptr==NULL) return;
        traverse(IN_ORDER, ptr->left);
        cout << ptr->data << " ";
        traverse(IN_ORDER, ptr->right);
    }
    else if(tt==POST_ORDER){
        if (ptr==NULL) return;
        traverse(POST_ORDER, ptr->left);
        traverse(POST_ORDER, ptr->right);
        cout << ptr->data << " ";
    }
}