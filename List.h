#pragma once
#include "Node.h"
#include "Collector.h"
//#ifndef UNTITLED_LIST_H
//#define UNTITLED_LIST_H


class List {

private:
    Node *start = NULL;
    Node *end = NULL;
    //static Collector *collector;
public:

    List();
    void Insert(int num);
    void InsertFirst(int num);
    void Delete(int num);
    void Show();
    void ShowC();
    static Collector* GetCollector();
};


//#endif //UNTITLED_LIST_H
