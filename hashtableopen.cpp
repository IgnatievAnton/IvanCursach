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
    if (key > 21 || key < 0)
    {
        cout << "No diferent key! Use only english word in name" << endl;
    }
    else
    {
        hashNode node;
        node.key = key;
        node.passanger = passanger;
        if (shit[key] == false)
            table[0] = node;
        else
        {

        }
//        else
//        {
//            if
//        }
    }
//    else

}


void hashTableOpen::remove(int key, Passenger *passanger)
{
    cheinRemove(passanger,table[key],0);
}

Passenger hashTableOpen::search(int key, Passenger *passanger)
{

}


int hashTableOpen::hash_function(string key)
{
    int hash = toupper(key[0])-'A';
    return hash;
}

void hashTableOpen::cheinRemove(Passenger *passanger, hashTableOpen::hashNode node, int pos)
{
    if (pos == 0 && (node.passanger == passanger))
    {
        table[node.key] = *node.Node;
    }
    else
    {
        if (node.passanger == passanger)
        {
//                table[]
        }
        else
        {

        }
    }

}

void hashTableOpen::chain(hashNode node, hashNode *nodeTree)
{
    if (nodeTree->Node == nullptr)
        nodeTree->Node = &node;
    else
        chain(node,nodeTree->Node);
}




hashTableOpen::hashNode *hashTableOpen::next(hashTableOpen::hashNode* node)
{
    return node->Node;
}

hashTableOpen::hashNode *hashTableOpen::prev(hashTableOpen::hashNode *node)
{
    for (int i =0 ; i < 21; i++)
    {
        if (table[i].Node == node)
            return table[i-1].Node;
    }
}







