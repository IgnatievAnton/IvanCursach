#ifndef HASHTABLEOPEN_HPP
#define HASHTABLEOPEN_HPP
#include "passenger.hpp"
#include <string>
#include <vector>

using namespace std;

class hashTableOpen
{
public:
    hashTableOpen();
    ~hashTableOpen();
    void insert(Passenger* passanger);
    void remove(int key, Passenger* passanger);
    int hash_function(string key,int a);
    Passenger search(int key, Passenger* passanger);
private:
    int hash_function(string key);
    struct hashNode
    {
        int key;
        Passenger* passanger;
        hashNode *Node = nullptr;
    };

    void cheinRemove(Passenger* passanger, struct hashNode node, int pos);
    void chain(struct hashNode node, hashNode *nodeTree);
    hashNode* next(hashNode *node);
    hashNode* prev(hashNode *node);
    hashNode table[9];
    bool shit[9];

};

#endif // HASHTABLEOPEN_HPP
