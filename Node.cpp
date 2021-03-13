/**
 * @file Node.cpp
 * @brief Definicion de los metodos de la clase nodo declarada en Node.cpp
 */

#include "Node.h"
#include <stdlib.h>

/**
 * @brief Constructor de la clase nodo.
 */
Node::Node() {
}

/**
 * @brief Metodo para obtener el int que almacena el nodo.
 * @return int
 */
int Node::GetNum() {
    return num;
}

/**
 * @brief Metodo para asignar un numero al nodo, ya sea por primera vez o cambiarlo. Recibe el numero.
 * @param in_num
 */
void Node::SetNum(int in_num) {
    num = in_num;
}

/**
 * @brief Asigna la referencia al siguiente nodo de la lista. Recibe la direccion al nodo que le sigue como parametro.
 * @param in_node
 */
void Node::SetNext(Node * in_node) {
    next = in_node;
}

/**
 * @brief Metodo para obtener el siguiente nodo de la lista.
 * @return Objeto tipo Nodo
 */
Node * Node::GetNext() {
    return next;
}

/**
 * @brief Metodo de overload del metodo new para que seleccione una direccion del collector o genere una nueva
 * si no hay, recibe el size por default y el address de parte del collector. Esta es NULL si esta vacio.
 * @param size
 * @param address
 * @return Direccion en memoria para el objeto instanciado.
 */
void * Node::operator new(size_t size, void* address) {

    if (address == NULL){
        Node* new_node = ::new Node();
        return new_node;
    } else{
        return address;
    }
}
