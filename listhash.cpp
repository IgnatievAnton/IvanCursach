#include "listhash.hpp"


listHash::listHash()
{
    for( int i = 0; i < 9; i++)
        table[i] = nullptr;
}


void listHash::addElement(Passenger *passanger)
{
    int key = hash_function(passanger->getNumberPassport());
    Node* current = new Node;
    current->key = key;
    current->passanger = passanger;
    current->next = table[key];
    table[key] = current;
//    current->next = table[key];
}


void listHash::print(int key)
{
    cout << "this table has the following passengers:" << endl;
    cout << "------------------------------------------" << endl;
    cout << "|                hash key:" << key << "              |"<< endl;
    cout << "------------------------------------------" << endl;
    if (table[key] != NULL) {
        print(table[key],0);
        nextChein(table[key]->next,1);
    }
    else
    {
        cout <<"this hash key chaein empty" << endl;
    }
}

void listHash::nextChein(listHash::Node *next,int count)
{
    if (next != NULL)
    {
        print(next,count);
        nextChein(next->next,count++);
    }
}

void listHash::print(listHash::Node *node,int number)
{
    cout << "|position this passanger on hash func ="<<number<<"|" <<endl;
    cout << "------------------------------------------" << endl;
    cout <<"firstSecondName: " << node->passanger->getFirstSecondName() << endl;
    cout << "date of birth: " << node->passanger->getDateB() << endl;
    cout << "number passport: " <<node->passanger->getNumberPassport() << endl;
    cout << "field: " <<node->passanger->getpathPassport() << endl;
    cout << "------------------------------------------" << endl;
}

int listHash::hash_function(string key)
{
    int hash = toupper(key[0])-'1';
    return hash;
}

