#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
int noMhs;
Node *next;

};

class LinkedList
{
    Node *START;
public:
    LinkedList()
    {
    START = NULL;
    }

    void addNode()
    {
    int nim;
    cout << "\nMasukan Nomor Mahasiswa: ";
    cin >> nim;

    Node *newNode = new Node();
    newNode->noMhs = nim;

    


    }
};
