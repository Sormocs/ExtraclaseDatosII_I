/**
 * @file Collector.cpp
 * @brief Funciones para la lista enlazada que forma al collector, incluye las definiciones del collector (lista)
 * y las direccioens que contiene (nodos de la lista).
 */

#include "Collector.h"
#include <iostream>

Collector *Collector::instance = nullptr;
/**
 * @brief Constructor del address.
 */
Address::Address() {}


/**
 * @brief Agrega referencia a la siguiente direccion almacenada en la lista (al siguiente nodo). Recibe
 * un puntero con la direcci'on al siguiente nodo de la lista.
 * @param next_dir
 */
void Address::SetNext(Address* next_dir) {
    next = next_dir;
}

/**
 * @brief Guarda en el nodo un valor con la direccion de memoria que debe almacenar en su interior.
 * @param dir_in
 */
void Address::SetDir(void *dir_in) {
    dir = dir_in;
}

/**
 * @brief Obtiene la siguiente direccion almacenada en el collector (el siguiente nodo de la lista).
 * @return Objeto del tipo Adress
 */
Address* Address::GetNext() {
    return next;
}

/**
 * @brief Obtiene la direccion de memoria almacenada en el nodo Address.
 * @return Una direccion de memoria que fue utilizada y liberada.
 */
void * Address::GetDir() {
    return dir;
}

//Collector::Collector() {}
/**
 * Metodo para convertir la clase Collecotor en un singleton y que sea una sola lista solamente en el programa.
 * @return Instancia de Collector.
 */
Collector* Collector::GetInstance() {
    if (instance == nullptr){
        instance = new Collector;
    }
    return instance;
}

/**
 * @brief Metodo para insertar una direccion en el collector. Recibe la direccion de memoria que se desea insertar.
 * @param em_address
 */
void Collector::Insert(void* em_address) {

    if (start == NULL ) {

        Address *new_dir = new Address();
        new_dir->SetDir(em_address);
        start = new_dir;
        end = start;
        end->SetNext(NULL);

    } else{

        Address *new_dir = new Address();
        new_dir->SetDir(em_address);
        end->SetNext(new_dir);
    }
}

/**
 * Obtiene la primera direccion que se inserto en el collector, la retorna y elimina de la lista.
 * @return La direccion en moemoria que se encontraba de primera.
 */
void * Collector::GetAddress() {
    if (start==NULL){
        return NULL;
    }else {
        void *address = start->GetDir();
        start = start->GetNext();
        return address;
    }
}
/**
 * @brief Verifica si el collector posee direcciones almacenadas.
 * @return bool
 */
bool Collector::isEmpty() {
    if (start == NULL){
        return true;
    }
    return false;
}
/**
 * @brief Muestra las direcciones almacenadas en el collector.
 */
void Collector::Show() {
    Address *current = start;
    std::cout << "Collector: ";
    while (current != NULL){
        std::cout << current->GetDir() << " ";
        current = current->GetNext();
    }
    std::cout << "" << std::endl;
}
