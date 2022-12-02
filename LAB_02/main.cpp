#include<iostream>
#include"Dictionary.cpp"
#include"Dictionary.h"
#include<cstring>
using namespace std;

int main(){
    Dictionary D;
    int n;
    cout << "Number of words to be entered :" << endl;
    cin >> n;
    struct Entry e[n];
    for(int i=0;i<n;i++){
        string str;
        cout << "Enter word" << endl;
        cin >> str;
        strcpy(e[i].word, str.c_str());
        bool x = D.put(e[i]);
    }
    return 0;
}