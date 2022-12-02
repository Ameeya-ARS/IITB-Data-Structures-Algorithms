#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include <bits/stdc++.h>
#include"BST.h"
using namespace std;

BST :: BST(){
    root = NULL;
}
void BST :: traverse(TraversalType_e tt, Node* ptr){
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

struct Node* BST :: Min(struct Node *p){
    Node* ptr = p;
    while(ptr->left != NULL){
        ptr = ptr->left;
    }
    return ptr;
}

struct Node* BST :: Max(struct Node *p){
    Node* ptr = p;
    while(ptr->right != NULL){
        ptr = ptr->right;
    }
    return ptr;
}

struct Node* BST::successor(struct Node* n){
    if(n->right!=NULL){
        cout << "False" << endl;
        return Min(n->right);
    }
        Node *p = n->parent;
        while(p!=NULL && n == p->right){
            n = p;
            p = p->parent;
        }
        return p;
}

Node* BST::insert(Node* p,struct Node N){
    if (p == NULL)
    {
        Node* ptr = new Node(N.data);

        return ptr ;
    }
    else{
        if((strcmp(N.data,p->data))<0){
            Node* temp = insert(p->left,N);
            p->left = temp;
            temp->parent = p;
        }
        else if((strcmp(N.data,p->data))>0){
            Node* temp = insert(p->right,N);
            p->right = temp;
            temp->parent = p;
        }
        return p;
    }
}

struct Node* BST::search(Node* p,char *c){
    if((strcmp(c,p->data))==0){
        return p;
    }
    else if((strcmp(c,p->data))<0){
        return search(p->left, c);
    }
    else if((strcmp(c,p->data))>0){
        return search(p->right, c);
    }
    return NULL;
}

bool BST::remove(char *c){
    Node *cproot = root;
    Node *p = search(cproot,c);
    bool f;
    if(p==NULL) return false;
    Node *temp = p->parent;
    Node *a = temp;
    if(p->left==NULL && p->right==NULL){
        if(temp->left==p){
            temp->left = NULL;
            temp->height = 1;
        }
        else if(temp->right==p){
            temp->right = NULL;
            temp->height = 1;
        }
        p->parent = NULL;
    }
    else if(p->left==NULL || p->right==NULL){
        if(temp->left == p){
            if(p->left == NULL){
                temp->left = p->right;
                temp->height = 1;
            }
            else{
                temp->left = p->left;
                temp->height = 1;
            }
        }
        else{
            if(p->left == NULL) {
                temp->right = p->right;
                temp->height = 1;
            }
            else {
                temp->right = p->left;
                temp->height = 1;
            }
        }
        p->left = NULL;
        p->right = NULL;
        p->parent = NULL;
    }
    else{
        Node *suc = successor(p);
        char* data = suc->data;
        remove(suc->data);
        p->data = data;
        Node *a = suc->parent;
        while(a!=NULL){
            a->height = 1 + max(a->left->height,a->right->height);
            a = a->parent;
        }
    }

    return true;
}

struct Node * BST::predecessor(struct Node *n)
{   
     if(n->left!=NULL){
        return Max(n->left);
    }
    else{
        Node *p = n->parent;
        while(p!=NULL && n == p->left){
            n = p;
            p = p->parent;
        }
        return p;
    }
}


int main(){
    BST T;
    char *d = new char[32]; string temp = "d"; strcpy(d, temp.c_str()); Node D(d); T.root = T.insert(T.root,D);
    char *b = new char[32]; temp = "b"; strcpy(b, temp.c_str()); Node B(b); T.root = T.insert(T.root,B);
    char *f = new char[32]; temp = "f"; strcpy(f, temp.c_str()); Node F(f); T.root = T.insert(T.root,F);
    char *a = new char[32]; temp = "a"; strcpy(a, temp.c_str()); Node A(a); T.root = T.insert(T.root,A);
    char *c = new char[32]; temp = "c"; strcpy(c, temp.c_str()); Node C(c); T.root = T.insert(T.root,C);
    char *e = new char[32]; temp = "e"; strcpy(e, temp.c_str()); Node E(e); T.root = T.insert(T.root,E);
    char *g = new char[32]; temp = "g"; strcpy(g, temp.c_str()); Node G(g); T.root = T.insert(T.root,G);
                                                                                                                                                                                                                                                                                                D.left = &B; D.right = &F; B.parent = &D; F.parent = &D;
                                                                                                                                                                                                                                                                                                B.left = &A; B.right = &C; F.left = &E; F.right = &G;
                                                                                                                                                                                                                                                                                                A.parent = &B; C.parent = &B; E.parent = &F; G.parent = &F;


    
    T.traverse(IN_ORDER,T.root); cout << endl;
    
    Node* minimum = T.Min(T.root);
    cout <<"Minimum data in the tree is : " << minimum->data << endl;

    Node* maximum = T.Max(T.root);
    cout << "Maximum data in the tree is : " << maximum->data << endl;

    Node* ptr1 = T.successor(&C);
    cout << "Successor of c is : " << ptr1->data << endl;

    Node* ptr2 = T.predecessor(&C);
    cout << "Predecessor of c is : " << ptr2->data << endl;

    T.remove(c);
    T.traverse(IN_ORDER,T.root);

    return 0;
}