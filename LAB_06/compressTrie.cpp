#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int alpha = 26;
struct trie
{
    struct trie *children[alpha];
    bool isend;
};
struct trie *getnode()
{
    struct trie *temp = new trie;
    temp->isend = false;
    for (int i = 0; i < alpha; i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}
void insert(struct trie *root, string s)
{
    struct trie *temp = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!temp->children[index])
            temp->children[index] = getnode();
        temp = temp->children[index];
    }

    temp->isend = true;
}
bool search(struct trie *root, string s)
{
    struct trie *temp = root;
    bool check = false;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!temp->children[index])
        {
            check = false;
            temp = temp->children[index];
            break;
        }
        else
        {
            str += s[i];
            temp = temp->children[index];
        }
    }
    if (temp != NULL && temp->isend)
    {
        check = true;
    }
    cout << str << endl;
    return check;
}
int main()
{
    ifstream fin("test.txt"); //opening text file
    int n = 1;                 //will not count first word so initial value is 1
    char ch;
    fin.seekg(0, ios::beg); //bring position of file pointer to begining of file

    while (fin)
    {
        fin.get(ch);
        if (ch == ' ' || ch == '\n')
            n++;
    }

    fin.close(); //closing the file

    //string s[] = {"burger", "burglar", "joyful",  "burgerman"};
    string s[n];
    ifstream file("test.txt");
    if (file.is_open())
    {

        for (int i = 0; i < n; ++i)
        {
            file >> s[i];
        }
    }
    struct trie *root = getnode();
    for (int i = 0; i < n; i++)
    {
        insert(root, s[i]);
    }
    string a = "ameeya";
    if (search(root, a))
    {
        cout << "YES  -  ";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == a)
                cout << "Index is : " << i << endl;
        }
    }
    else
        cout << "NO" << endl;
    return 0;
}