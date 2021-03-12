#include <iostream>
#include "List.h"

using namespace std;

List::List() {}

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

void List::Show() {
    Node *current = start;
    cout << "Lista (num) (direccion): ";
    while (current != NULL){
        cout <<  current->GetNum() << " (" << current << ") -> ";
        current = current->GetNext();
    }
    cout << "" << endl;
}

void List::ShowC() {
    Collector::GetInstance()->Show();
}


void Node::operator delete(void * del_dir) noexcept {
    Collector::GetInstance()->Insert((void*)del_dir);
}
