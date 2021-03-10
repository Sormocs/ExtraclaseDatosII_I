#include <iostream>
#include "List.h"
int main() {

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
    std::cout << "borrado" << std::endl;
    lista->Show();
    lista->ShowC();
    lista->Insert(6);
    std::cout << "6 Metido" << std::endl;
    lista->Show();
    //std::cout << "6 insertado" << std::endl;
    //lista->ShowC();
    std::cout << "terminado" << std::endl;


    return 0;
}
