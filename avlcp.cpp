#include "avlcp.hpp"
using namespace std;

void avltree::insert(aviaReis *r, nodeptr& n, int ky)
{
    if (n == NULL)
    {
        n = new node;
        n->reic = r;
        n->key = ky;
        n->left=NULL;
        n->right = NULL;
        n->height=0;
        if (n==NULL)
        {
            cout<<"Out of Space\n"<<endl;
        }
    }
    else
    {
        if (ky < n->key)
        {
            insert(r,n->left,ky);
            if ((bsheight(n->left) - bsheight(n->right))==2)
            {
                //if (r < n->left->key)
                if(ky < (n->left->key))
                {
                    n = srl(n);
                }
                else
                {
                    n = drl(n);
                }
            }
        }
        else if (ky > (n->key))
        {
            insert(r,n->right,ky);
            if ((bsheight(n->right) - bsheight(n->left))==2)
            {
                if (ky > n->right->key)
                {
                    n = srr(n);
                }
                else
                {
                    n = drr(n);
                }
            }
        }
        else
        {
            cout<<"this number is not empty\n"<<endl;
        }
    }
int z = bsheight(n->left);
int x = bsheight(n->right);
int c = 0;
if (z > x)
    c = z;
else
    c = x;
n->height = c + 1;

}


aviaReis *avltree::find(int x,nodeptr &p)
{
    if (p==NULL)
    {
        cout<<"Простите, но такого элемента нет\n"<<endl;
    }
    else
    {
        if (x < (p->key) )
        {
            find(x,p->left);
        }
        else
        {
            if (x > (p->key))
            {
                find(x,p->right);
            }
            else
            {
                if(p->key == x)
                    return p->reic;
//                cout<<"Элемент, который вы искали есть в дереве!\n"<<endl;
            }
        }
    }
}

// Copy a tree
void avltree::copy(nodeptr &p,nodeptr &p1)
{
    makeempty(p1);
    p1 = nodecopy(p);
}

// Make a tree empty
void avltree::makeempty(nodeptr &p)
{
    nodeptr d;
    if (p != NULL)
    {
        makeempty(p->left);
        makeempty(p->right);
        d=p;
        free(d);
        p=NULL;
    }
}
// Copy the nodes
nodeptr avltree::nodecopy(nodeptr &p)
{
    nodeptr temp;
    if (p==NULL)
    {
        return p;
    }
    else
    {
        temp = new node;
        temp->key = p->key;
        temp->left = nodecopy(p->left);
        temp->right = nodecopy(p->right);
        return temp;
    }
}

// Deleting a node
void avltree::del(int x,nodeptr &p)
{
    nodeptr d;
    if (p==NULL)
    {
        cout<<"no have this reic\n"<<endl;
    }
    else if ( x < p->key)
    {
        del(x,p->left);
    }
    else if (x > p->key)
    {
        del(x,p->right);
    }
    else if ((p->left == NULL) && (p->right == NULL))
    {
        d=p;
        free(d);
        p=NULL;
        cout<<"delited reic"<<endl;
    }
    else if (p->left == NULL)
    {
        d=p;
        free(d);
        p=p->right;
        cout<<"delited reic"<<endl;
    }
    else if (p->right == NULL)
    {
        d=p;
        p=p->left;
        free(d);
        cout<<"delited reic"<<endl;
    }
    else
    {
        p->key = deletemin(p->right);
    }
}

int avltree::deletemin(nodeptr &p)
{
    int c;
    cout<<"Выбрано удаление минимального значения\n"<<endl;
    if (p->left == NULL)
    {
        c=p->key;
        p=p->right;
        return c;
    }
    else
    {
        c=deletemin(p->left);
        return c;
    }
}

void avltree::printAllNode(nodeptr &n)
{
    if (n == NULL)
        return;
    else {
        cout << "-------------------------" <<endl;
        n->reic->print();
        printAllNode(n->left);
        printAllNode(n->right);
    }
}

void avltree::printReic(nodeptr &n,int key)
{
    if(n->key == key)
        n->reic->print();
    else if( n == NULL )
        cout << "no have this reic" << endl;
    else if(key < (n->key))
        printReic(n->left,key);
    else if(key > (n->key))
        printReic(n->right,key);
}

void avltree::preorder(nodeptr p)
{
    if (p!=NULL)
    {
        cout<<p->key<<"\t";
        preorder(p->left);
        preorder(p->right);
    }
}

// Inorder Printing
void avltree::inorder(nodeptr p)
{
    if (p!=NULL)
    {
        inorder(p->left);
        cout<<p->key<<"\t";
        inorder(p->right);
    }
}

// PostOrder Printing
void avltree::postorder(nodeptr p)
{
    if (p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->key<<"\t";
    }
}

int avltree::max(int value1, int value2)
{
    return ((value1 > value2) ? value1 : value2);
}
int avltree::bsheight(nodeptr p)
{
    int t;
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        t = p->height;
        return t;
    }
}

nodeptr avltree:: srl(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->left;
    p1->left = p2->right;
    p2->right = p1;
    p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
    p2->height = max(bsheight(p2->left),p1->height) + 1;
    return p2;
}
nodeptr avltree:: srr(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->right;
    p1->right = p2->left;
    p2->left = p1;
    p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
    p2->height = max(p1->height,bsheight(p2->right)) + 1;
    return p2;
}
nodeptr avltree:: drl(nodeptr &p1)
{
    p1->left=srr(p1->left);
    return srl(p1);
}
nodeptr avltree::drr(nodeptr &p1)
{
    p1->right = srl(p1->right);
    return srr(p1);
}

int avltree::nonodes(nodeptr p)
{
    int count=0;
    if (p!=NULL)
    {
        nonodes(p->left);
        nonodes(p->right);
        count++;
    }
    return count;
}




