#pragma once
#include <iostream>
#include "Collector.h"
//#ifndef UNTITLED_NODE_H
//#define UNTITLED_NODE_H

class Node {

private:
    int num;
    Node *next;


public:
    Node();
    void SetNum(int num);
    int GetNum();
    Node * GetNext();
    void SetNext(Node *node);
    void* operator new(size_t size, void*, int);
    void operator delete(void*);

};


//#endif //UNTITLED_NODE_H
