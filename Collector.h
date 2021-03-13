/**
 * @file Collector.h
 * @brief Declaraciones de metodos y atributos para las clases address y collector.
 */

#pragma once
#include "Node.h"
#include <iostream>
/**
 * @brief Clase address que representa los nodos de la lista enlazada que constituye al collector.
 */
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
/**
 * @brief Definicion y metodos de la clase de collector que esta formada por las direcciones de
 * memoria que fueron liberadas.
 */
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



