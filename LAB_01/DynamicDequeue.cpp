#include"DynamicDequeue.h"

#include<iostream>
using namespace std;

DynamicDequeue :: DynamicDequeue(){
    N = INIT_SIZE;
    f = -1;
    r = 0;
    A = new double[N];
}

bool DynamicDequeue :: isEmpty(){
    if(f==-1) return true; //Whenever 1st element is added whether to front or rear, f becomes 0 so f=-1 means its empty
    else return false;
}

bool DynamicDequeue :: isFull(){
    if((f==r+1) || (f==0 && r==N-1)) return true; //basic condition is that f and r remain side by side in circular array
    else return false;
}

void DynamicDequeue :: grow(){
    int oldN = N;
    N = nextSizeLinear();
   // N = nextSizeExponential();
    double B[N];
    if (f==0) {
        for(int i=0;i<oldN;i++){
            B[i] = A[i];
        }
    }
    else if(r==0){
        for(int i=1;i<oldN;i++){
            B[i-1] = A[i];
        }
        B[oldN-1] = A[0];
    }
    else{
        int current = 0;
        for(int i=f;i<oldN;i++){
            B[current] = A[i];
            current++;
        }
        for(int i=0;i<=r;i++){
            B[current] = A[i];
            current++;
        }
    }
    f = 0;
    r = oldN - 1;
    A = B;
}

unsigned int DynamicDequeue :: size(){
    if(isEmpty()) return 0;
    else if(isFull()) return N;
    else if(f==0 && r==0) return 1;
    else if(f==0){
        return (r+1);
    }
    else if(r==0){
        return (N-f+1);
    }
    else {
        return ((N-f)+(r)+1);
    }
}

void DynamicDequeue :: insertFront(double x){
    if (isFull()){
        grow();
    }
    if(f==-1){
        f = 0;
        r = 0;
    }
    else if(f==0){
        f = N-1;
    }
    else {
        f--;
    }
    A[f] = x;
}

void DynamicDequeue :: insertRear(double x){
    if(isFull()){
        grow();
    }
    if(f==-1){
        f = 0;
        r = 0;
    }
    else if (r==N-1){
        r = 0;
    }
    else {
        r++;
    }
    A[r] = x;
}

bool DynamicDequeue :: removeFront(double *x){
    if(isEmpty()){
        return false;
    }
    if(f==r){
        *x = A[f];
        f = -1;
        r = -1;
        return true;
    }
    else if(f==N-1){
        *x = A[f];
        f = 0;
        return true;
    }
    else{
        *x = A[f];
        f++;
        return true;
    }
}

bool DynamicDequeue :: removeRear(double *x){
    if(isEmpty()){
        return false;
    }
    if(f==r){
        *x = A[r];
        f = -1;
        r = -1;
        return true;
    }
    else if(r==0){
        *x = A[r];
        r = N-1;
        return true;
    }
    else{
        *x = A[r];
        r--;
        return true;
    }
}

bool DynamicDequeue :: front(double *x){
    if(isEmpty()){
        return false;
    }
    else {
        *x = A[f];
        return true;
    }
}

bool DynamicDequeue :: rear(double *x){
    if(isEmpty() || r<0){
        return false;
    }
    else {
        *x = A[r];
        return true;
    }
}
