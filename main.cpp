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
    lista->Show();
    lista->ShowC();
    lista->Insert(6);
    lista->Insert(7);
    lista->Show();

//    lista->Insert(2);
//    lista->Show();
//    lista->ShowC();
//    lista->Delete(2);
//    lista->ShowC();
//    lista->Insert(2);
//    lista->Show();
//    lista->ShowC();


    return 0;
}
