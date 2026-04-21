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

    if (START == NULL || nim <= START->noMhs)
    {
        if (START != NULL && nim == START->noMhs)
        {
            cout << "\nDuplikat noMhs tidak diijinkan\n";
            return;
        }
    }

    


    }
};
