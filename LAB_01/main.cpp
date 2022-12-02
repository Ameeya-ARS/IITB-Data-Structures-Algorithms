#include<iostream>
#include"DynamicDequeue.cpp"
#include"DynamicDequeue.h"
using namespace std;

int main(){
    DynamicDequeue original;
    original.insertFront(20);
    original.insertRear(10);
    original.insertRear(30);
    original.insertFront(25);
    double value;
    if(original.removeFront(&value))
    cout << "Removed value is " << value << endl;
    else cout << "Empty !!!" << endl;
    if(original.removeRear(&value))
    cout << "Removed value is " << value << endl;
    else cout << "Empty !!!" << endl;
    if(original.front(&value))
    cout << "Value is " << value << endl;
    else cout << "Empty !!!" << endl;
    if(original.rear(&value))
    cout << "Value is " << value << endl;
    else cout << "Empty !!!" << endl;

    return 0;
}