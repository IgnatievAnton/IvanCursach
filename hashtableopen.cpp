#include "hashtableopen.hpp"

//TODO можно сделать список который динамический но я не уверен что это будет хэщ таблица тогда лучше будет вектор.
hashTableOpen::hashTableOpen()
{
    for (int i = 0; i < 9; i++)
    {
        shit[i] = false;
    }
//    table = new hashNode[300];
}

hashTableOpen::~hashTableOpen()
{

}

//TODO ну тут все понятно но надо сделать покрасивей что то не нравится.
void hashTableOpen::insert(Passenger *passanger)
{
    cout << "================================" << endl;
    cout << passanger->getFirstSecondName() << endl;
    cout << passanger->getDateB() << endl;
    cout << passanger->getNumberPassport() << endl;;
    cout << passanger->getpathPassport() << endl;;
    cout << "================================" << endl;
    int key = hash_function(passanger->getNumberPassport());
    if (key > 8 || key < 0)
    {
        cout << "No diferent key! Use only english word in name" << endl;
    }

    else
    {

        hashNode node;
        node.key = key;
        node.passanger = passanger;
        node.Node = NULL;

        if (shit[key] == false)
            table[0] = node;
        else
        {
            node.Node = table[key].Node;
            table[key] = node;
        }
        cout << "================================" << endl;
        cout << table[key].passanger->getFirstSecondName() << endl;
        cout << table[key].passanger->getDateB() << endl;
        cout << table[key].passanger->getNumberPassport() << endl;;
        cout << table[key].passanger->getpathPassport() << endl;;
        cout << "================================" << endl;
//        table[key].passanger->
    }
}


void hashTableOpen::remove(int key, Passenger *passanger)
{
    cheinRemove(passanger,table[key],0);
}

Passenger hashTableOpen::search(int key, Passenger *passanger)
{
    return *passanger;
}

void hashTableOpen::printHashNode(int key)
{
    cout << "this key has the following passengers:" << endl;
//    bool a = printH(table[key].Node);
}

void hashTableOpen::printHashNode()
{
    cout << "this table has the following passengers:" << endl;

    for (int i =0 ; i < 9; i++)
    {
        cout << "================================" << endl;
        cout << "Hash key "<< i << ": "<< endl;
        cout << "================================" << endl;
        bool a = printH(i,0);
        if (a == false)
            cout << "huin9 kaka9 to" <<endl;
        cout << "================================" << endl;
    }
}

bool hashTableOpen::printH(int key, int numberOnHash)
{
    if (table[key].passanger == NULL)
        return 0;
    else
    {
        cout <<"the sequence number of the passenger in hash func: " <<numberOnHash << endl;
        cout << table[key].passanger->getFirstSecondName() << endl;
        cout << table[key].passanger->getDateB() << endl;
        cout << table[key].passanger->getNumberPassport() << endl;;
        cout << table[key].passanger->getpathPassport() << endl;;
        cout << "================================" << endl;
        cout <<"the sequence number of the passenger in hash func: " <<numberOnHash++ << endl;
        cout << table[key].Node->passanger->passangergetFirstSecondName() <<endl;
        cout << table[key].Node->passangergetFirstSecondName() << endl;
        cout << table[key].passanger->getDateB() << endl;
        cout << table[key].passanger->getNumberPassport() << endl;;
        cout << table[key].passanger->getpathPassport() << endl;;
        cout << "================================" << endl;
//        if (table[key].Node == NULL)
//        {
//            return 1;
//            cout << "proverka"<<endl;
//        }
//        else
//        {
//            cout << "else" << std::endl;
//            printNextChain(*table[key].Node,1);
//        }
    }


}

void hashTableOpen::printNextChain(hashTableOpen::hashNode node, int i)
{
    cout << "testNextChein"<<endl;
    if (node.passanger != NULL)
    {
        cout <<"the sequence number of the passenger in hash func: " << i << endl;
        cout << node.passanger->getFirstSecondName() << endl;
        cout << node.passanger->getDateB() << endl;
        cout << node.passanger->getNumberPassport() << endl;;
        cout << node.passanger->getpathPassport() << endl;;
        cout << "================================" << endl;
        if (node.Node != NULL)
            printNextChain(node,++i);
    }

}


int hashTableOpen::hash_function(string key)
{
    int hash = toupper(key[0])-'1';
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







