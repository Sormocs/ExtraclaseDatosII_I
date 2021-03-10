#pragma once
#include "Node.h"
#include "Collector.h"
//#ifndef UNTITLED_LIST_H
//#define UNTITLED_LIST_H


class List {

private:
    Node *start = NULL;
    Node *end = NULL;
    Collector *collector = new Collector();
public:
    List();
    void Insert(int num);
    void InsertFirst(int num);
    void Delete(int num);
    void Show();
    void ShowC();
};


//#endif //UNTITLED_LIST_H
