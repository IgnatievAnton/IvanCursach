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
    Passenger search(int key, Passenger* passanger);
    void printHashNode(int key);
    void printHashNode();

private:
    int hash_function(string key);
    struct hashNode
    {
        int key;
        Passenger* passanger;
        hashNode *Node = nullptr;
    };

    bool printH(hashNode *node);

    void cheinRemove(Passenger* passanger, struct hashNode node, int pos);
    void chain(struct hashNode node, hashNode *nodeTree);
    hashNode* next(hashNode *node);
    hashNode* prev(hashNode *node);
    hashNode table[9];
    bool shit[9];

};

#endif // HASHTABLEOPEN_HPP
