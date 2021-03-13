/**
 * @file List.cpp
 * @brief Definiciones de los metodos de la clas lista declarada en Lista.h
 */

#include <iostream>
#include "List.h"

using namespace std;
/**
 * @brief Constructor de la clase lista.
 */
List::List() {}

/**
 * @brief Inserta el numero introducido a la lista enlazada. Recibe un entero.
 * @param in_num
 */
void List::Insert(int in_num) {

    if (start == NULL){
        Node* new_node = new(Collector::GetInstance()->GetAddress()) Node();
        new_node->SetNum(in_num);
        new_node->SetNext(NULL);
        start = new_node;
        end = start;
    } else {
        void* address = Collector::GetInstance()->GetAddress();
        Node* new_node = new(address) Node();
        new_node->SetNum(in_num);
        end->SetNext(new_node);
        end = new_node;
        end->SetNext(NULL);
    }
}

/**
 * @brief Misma funcionalidad del metodo regular de Insert, pero esta lo inserta al inicio de la lista. Recibe el int.
 * @param in_num
 */
void List::InsertFirst(int in_num) {

    if (start == NULL){
        Insert(in_num);
    } else{
        if (Collector::GetInstance()->isEmpty()) {
            Node *new_node = new(Collector::GetInstance()->GetAddress()) Node();
            new_node->SetNum(in_num);
            new_node->SetNext(start);
            start = new_node;
        } else{
            Node* new_node = new(Collector::GetInstance()->GetAddress()) Node();
            new_node->SetNum(in_num);
            new_node->SetNext(start);
            start = new_node;
        }

    }
}

/**
 * @brief Metodo delete para eliminar un numero de la lista y enviar la direccion que contenia su nodo al collector
 * para que sea reciclada. Recibe el numero que se desea eliminar.
 * @param num
 */
void List::Delete(int num) {

    Node *current = start;
    Node *prev = start;
    while(current->GetNext() != NULL){
        int n_num = current->GetNum();
        if (num == n_num){
            prev->SetNext(current->GetNext());
            delete current;
            break;
        } else{
            prev = current;
            current = current->GetNext();
        }
    }
}
/**
 * @brief Metodo show para mostrar los elementos de la lista junto con la direccion de memoria en la que se encuentran.
 */
void List::Show() {
    Node *current = start;
    cout << "Lista (num) (direccion): ";
    while (current != NULL){
        cout <<  current->GetNum() << " (" << current << ") -> ";
        current = current->GetNext();
    }
    cout << "" << endl;
}

/**
 * @brief Metodo que llama al metodo show del collector para mostrar las direcciones dentro de collector.
 */
void List::ShowC() {
    Collector::GetInstance()->Show();
}

/**
 * @brief Overload del metodo delete declarado en Node.h
 * @param del_dir
 */
void Node::operator delete(void * del_dir) noexcept {
    Collector::GetInstance()->Insert((void*)del_dir);
}
