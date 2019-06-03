#ifndef AVLCP_H
#define AVLCP_H

#include <iostream>
#include<ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <aviaticket.hpp>
using namespace std;

struct node
{
    aviaReis* reic = NULL;
    int key = 0;
    node *left = NULL;
    node *right = NULL;
    int height = 0 ;
};

 typedef struct node *nodeptr;

class avltree
{
    public:
        void insert(aviaReis* r, nodeptr& n, int ky);
        void del(int, nodeptr &);
        int deletemin(nodeptr &);
        void printAllNode(nodeptr &);
        void printReic(nodeptr &n, int key);

        aviaReis* find(int a, nodeptr &n);
        nodeptr findmin(nodeptr);
        nodeptr findmax(nodeptr);
        void makeempty(nodeptr &);
        void copy(nodeptr &,nodeptr &);
        nodeptr nodecopy(nodeptr &);
        void preorder(nodeptr);
        void inorder(nodeptr);
        void postorder(nodeptr);
        int bsheight(nodeptr);
        nodeptr srl(nodeptr &);
        nodeptr drl(nodeptr &);
        nodeptr srr(nodeptr &);
        nodeptr drr(nodeptr &);
        int max(int,int);
        int nonodes(nodeptr);
};

#endif // AVLCP_H
