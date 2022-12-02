#include<iostream>
#include<string>
#include<cstring>
#include "TreeTraversal.h"
using namespace std;

Tree :: Tree(){
    root = NULL;
}

int search(char arr[], int start, int end, char value)
{
	int i;
	for (i = start; i <= end; i++)
	{
		if (arr[i] == value)
			return i;
	}
    return -1;
}

int checkPreorder(Node* node, char preOrder[], int index)
{
    if (node == NULL)
        return index;
    
    if (node->data == preOrder[index])
        index++;
    else
        return -1;
    index = checkPreorder(node->left,preOrder,index);
    index = checkPreorder(node->right,preOrder,index);   
    return index;
}

int checkInorder(Node* node, char inOrder[], int index)
{
    if (node == NULL)
        return index;
    index = checkInorder(node->left,inOrder,index);
    if (node->data == inOrder[index])
        index++;
    else
        return -1;
    
    index = checkInorder(node->right,inOrder,index);   
    return index;
}

struct Node * Tree :: deduce_tree(char *pre_order, char *in_order, int start, int end){
    static int preIndex = 0;
    if(start > end) return NULL;
    Node* ptr = new Node();
    ptr->data = pre_order[preIndex++];
    ptr->left = NULL;
    ptr->right = NULL;
    if(start==end) return ptr;
    int inIndex = search(in_order, start, end, ptr->data);
    if(inIndex==-1) return NULL;
    ptr->left = deduce_tree(pre_order, in_order, start, inIndex-1);
    ptr->right = deduce_tree(pre_order, in_order, inIndex+1, end);

    return ptr;
}


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

int main(){
    string s_in, s_pre;
    cout << "Enter in Order Traveral :" << endl;
    cin >> s_in;
    cout << "Enter Pre Order Traversal :" << endl;
    cin >> s_pre;
    char in[s_in.size()+1];
    char pre[s_pre.size()+1];
    strcpy(in, s_in.c_str());
    strcpy(pre, s_pre.c_str());
    Tree T(pre, in, s_in.size());
    int index1 = checkInorder(T.root,in,0);
    int index2 = checkPreorder(T.root,pre,0);
    if((s_in.size()==s_pre.size())&&(index1==s_in.size())&&(index2==s_pre.size())){
        cout << "Inorder Traversal : ";
        T.traverse(IN_ORDER, T.root);
        cout << endl;
        cout << "PreOrder Traversal : ";
        T.traverse(PRE_ORDER, T.root);
        cout << endl;
        cout << "PostOrder Traversal :";
        T.traverse(POST_ORDER,T.root);
        cout << endl;
    }
    else{
        cout << "Binary Tree is not possible " << endl;
    }
    return 0;
}
