/**
 * @file Node.h
 * @brief Header donde se declara la clase del nodo que compone a list.
 */

#pragma once
#include <iostream>
#include "Collector.h"
/**
 * @brief Clase nodo que almacena un numero que se inserto en list y contiene una referencia al siguiente nodo de list.
 */
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
    void* operator new(size_t size, void*);
    void operator delete(void*);

};

