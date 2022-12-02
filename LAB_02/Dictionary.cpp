#include<iostream>
#include"Dictionary.h"
#include<cmath>
#include<cstring>
using namespace std;

Dictionary :: Dictionary(){
    N = 1024;
    A = new Entry[N];
}

int Dictionary :: hashValue(char *key){
    int x = 33;
    double b=0;
    double A = (sqrt(5)-1)/2.0;
    int i=0;
    while(key[i]!='\0'){
        int val = (int)key[i];
        b = (b + (A*val))*x ;
        b = b-floor(b);
        i++;
    } 
    int k = N*b;
    cout << "Hash value : " << k << endl;
    return k;
}

int Dictionary :: findFreeIndex(char *key){
    int hV = hashValue(key);
    while((strcmp(A[hV].word, key)!=0)){
        hV++;
        if(A[hV].status==0) break;
    }
    cout << "Free Index : " << hV << endl;
    return hV;
}

struct Entry* Dictionary :: get(char *key){
    int hV = hashValue(key);
    char *local = key;
    while((strcmp(A[hV].word, key)!=0)&&(A[hV].status!=0)){
        hV++;
    }
    if(A[hV].status == 0) return NULL;
    else return &A[hV];
}

bool Dictionary :: put(struct Entry e){
    struct Entry *p = get(e.word);
    if(p==NULL){
        int hV = findFreeIndex(e.word);
        if(hV<N){
            A[hV].word = e.word;
            A[hV].status = 1;
            A[hV].freq += 1;
            cout << "Present frequency of entered key: " << A[hV].freq << endl;
            return true;
        }
        else return false;
    }
    else{
        p->freq = p->freq + 1;
        cout << "Present frequency of entered key: " << p->freq << endl;
        return true;
    }
}
bool Dictionary :: remove(char *key){
    struct Entry *p = get(key);
    if(p==NULL) return false;
    else{
        p->status = 2;
        return true;
    }
}
