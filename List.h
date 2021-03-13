/**
 * @file List.h
 * @brief Declaracion de la clase lista, que conforma la lista enlazada que contiene los numeros.
 */

#pragma once
#include "Node.h"
#include "Collector.h"

/**
 * @brief Declaracion de la clase lista, que contiene a los numeros que se ingresen en la misma. Contiene instancaias
 * de la clase nodo.
 */
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

