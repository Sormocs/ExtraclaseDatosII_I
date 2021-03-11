#include "Collector.h"
#include <iostream>

Collector *Collector::instance = nullptr;
Address::Address() {}

void Address::SetNext(Address* next_dir) {
    next = next_dir;
}

void Address::SetDir(void *dir_in) {
    dir = dir_in;
}

Address* Address::GetNext() {
    return next;
}

void * Address::GetDir() {
    return dir;
}

//Collector::Collector() {}

Collector* Collector::GetInstance() {
    if (instance == nullptr){
        instance = new Collector;
    }
    return instance;
}

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

void * Collector::GetAddress() {
    if (start==NULL){
        return NULL;
    }else {
        void *address = start->GetDir();
        start = start->GetNext();
        std::cout << "address returned: " << address << std::endl;
        return address;
    }
}

bool Collector::isEmpty() {
    if (start == NULL){
        return true;
    }
    return false;
}

void Collector::Show() {
    Address *current = start;
    std::cout << "Collector: ";
    while (current != NULL){
        std::cout << current->GetDir() << " ";
        current = current->GetNext();
    }
    std::cout << "" << std::endl;
}
