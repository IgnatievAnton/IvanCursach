#include "hashtableopen.hpp"

//TODO можно сделать список который динамический но я не уверен что это будет хэщ таблица тогда лучше будет вектор.
hashTableOpen::hashTableOpen()
{
    for (int i = 0; i < 21; i++)
    {
        shit[i] = false;
    }
    cout << "test" << endl;
//    table = new hashNode[300];
}

hashTableOpen::~hashTableOpen()
{

}

//TODO ну тут все понятно но надо сделать покрасивей что то не нравится.
void hashTableOpen::insert(Passenger *passanger)
{
    int key = hash_function(passanger->getFirstSecondName());
    cout << key << endl;
    hashNode node;
    node.key = key;
    node.passanger = passanger;
    if (shit[key] == false)
        table[0] = node;
//    else

}



int hashTableOpen::hash_function(string key)
{
    int hash = toupper(key[0])-'A';
    return hash;
}

void hashTableOpen::chain(hashNode node, hashNode *nodeTree)
{
    if (nodeTree->Node == nullptr)
        nodeTree->Node = &node;
    else
        chain(node,nodeTree->Node);

}