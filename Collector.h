#pragma once
#include "Node.h"
#include <iostream>

class Address{
private:
    void* dir;
    Address* next= NULL;
public:
    Address();
    void SetDir(void* dir);
    void SetNext(Address* next);
    Address* GetNext();
    void* GetDir();
};

class Collector {
private:
    Address *start = NULL;
    Address *end = NULL;
    static Collector* instance;

public:
    //Collector();
    static Collector* GetInstance();
    void Insert(void* em_address);
    void* GetAddress();
    void Show();
    bool isEmpty();

};



