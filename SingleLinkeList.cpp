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

    Node *nodeBaru = new Node();
    nodeBaru->noMhs = nim;

    if (START == NULL || nim <= START->noMhs)
    {
        if (START != NULL && nim == START->noMhs)
        {
            cout << "\nDuplikat noMhs tidak diijinkan\n";
            return;
        }
        nodeBaru->next = START;
        START = nodeBaru;
        return;

    }
    Node *previous = START;
    Node *current = START;

    while (current != NULL && nim >= current->noMhs)
    {
        if (nim == current->noMhs)
        {
            cout << "\nDuplikat noMhs tidak diijinkan\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    nodeBaru->next = current;
    previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, Node *&previous, Node *&current)
        
    {
        previous = NULL;
        current = START;

        while (current != NULL && nim != current->noMhs)
        {
            previous = current;
            current = current->next;
        }
        return (current != NULL);
    }
    bool delNode(int nim)
    {
        Node *previous, *current;
        if (search(nim, previous, current) == false)
            return false;

        if (current == START)
        {
            START = START->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current;
        return true;

    }
    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
                else
        {
            cout << "\nData dalam list: \n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }

    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. menambah Data ke dalam list" << endl;
        cout << "2. menghapus Data dari list" << endl;
        cout << "3. menampilkan semua data  didalam list" << endl;
        cout << "4. mencari Data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << "\nmasukan Pilihan  (1-5): ";
        cin >> ch;

        switch (ch)
        {       
         case '1':
            mhs.addNode();
            break;
        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }
            
            cout << "\nmasukan no mahasiswa yang akan dihapus: ";
            cin >> nim;

            if (mhs.delNode(nim) == false)
                cout << "\nData tidak ditemukan\n";
            else
                cout << "\nData dengan no mahasiswa " << nim << " berhasil dihapus\n";
            break;
        case '3':
            mhs.traverse();
            break;
        case '4':
            {
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }
            Node *previous, *current;
            cout << "\nmasukan no mahasiswa yang akan dicari: ";
            cin >> nim;

            if (mhs.search(nim, previous, current) == false)
                cout << "\nData tidak ditemukan\n";
            else
                cout << "\nData ditemukan\n";
                cout << "NIM Mahasiswa: " << current->noMhs << endl;
            break;
            }
        case '5':
        break;
        default:
            cout << "\nPilihan salah.\n";  
    
        }
    } while (ch != '5');
    return 0;
        
    
};

            
            

            
    
        