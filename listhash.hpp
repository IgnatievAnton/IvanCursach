#ifndef LISTHASH_H
#define LISTHASH_H
#include <passenger.hpp>

class listHash
{
    struct Node{
        int key;
        Passenger* passanger = NULL;
        Node* next;
    };
public:
    listHash();
    void addElement(Passenger* passanger);
    void print(int key);
    Passenger* searchePassenger();
private:
    void nextChein(Node* next, int count);
    void print(Node* node,int a);
    int hash_function(string key);
    Node* table[9];
    bool shit[9];
};

#endif // LISTHASH_H
