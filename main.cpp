/**
 * @file main.cpp
 * @author Sergio_Martinez
 * @brief Funcion main para correr el programa, crea una lista y le inserta y borra numeros para
 * ejemplificar el funcionamiento de programa.
 */
#include <iostream>
#include "List.h"
/**
 * @brief Funcion main para ejecutar el programa.
 * @return Un entero.
 */
int main() {

    //Lista para probar funcionamiento
    List *lista = new List();
    lista->Insert(2);
    lista->Insert(3);
    lista->Insert(4);
    lista->Insert(5);
    lista->Show();
    lista->InsertFirst(1);
    lista->Show();
    lista->Delete(3);
    lista->Delete(4);
    std::cout << "Elimina 3 y 4" << std::endl;
    lista->Show();
    lista->ShowC();
    lista->Insert(6);
    lista->Insert(7);
    lista->Show();


    return 0;
}
