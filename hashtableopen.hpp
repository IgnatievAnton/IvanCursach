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
    void remove(int key);
    Passenger search(int key);
private:
    int hash_function(string key);
    struct hashNode
    {
        int key;
        Passenger* passanger;
        hashNode *Node = nullptr;
    };


    void chain(struct hashNode node, hashNode *nodeTree);
    hashNode table[21];
    bool shit[21];

};

#endif // HASHTABLEOPEN_HPP
