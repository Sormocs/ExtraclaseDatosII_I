#include <iostream>
#include "List.h"
#include "Collector.h"

using namespace std;

List::List() {
}

//void List::Insert(int in_num) {
//
//    if (start == NULL) {
//
//        if (collector->isEmpty()) {
//            Node *new_node = ::new Node();
//            new_node->SetNum(in_num);
//            new_node->SetNext(NULL);
//            start = new_node;
//            end = start;
//        } else{
//
//            Node* new_node = new(collector->GetAddress()) Node();
//            new_node->SetNum(in_num);
//            new_node->SetNext(NULL);
//            start = new_node;
//            end = start;
//        }
//
//    } else{
//
//        if (collector->isEmpty()) {
//            Node *new_node = ::new Node();
//            new_node->SetNum(in_num);
//            end->SetNext(new_node);
//            end = new_node;
//            end->SetNext(NULL);
//        } else{
//            void* address = collector->GetAddress();
//            cout << "obtained address: " << address << endl;
//            Node* new_node = new(address,0) Node();
//            new_node->SetNum(in_num);
//            end->SetNext(new_node);
//            end = new_node;
//            end->SetNext(NULL);
//        }
//    }
//}

void List::Insert(int in_num) {

    if (start == NULL){
        Node* new_node = new(collector->GetAddress(),0) Node();
        new_node->SetNum(in_num);
        new_node->SetNext(NULL);
        start = new_node;
        end = start;
    } else {
        void* address = collector->GetAddress();
        Node* new_node = new(address,0) Node();
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
        if (collector->isEmpty()) {
            Node *new_node = ::new Node();
            new_node->SetNum(in_num);
            new_node->SetNext(start);
            start = new_node;
        } else{
            Node* new_node = new(collector->GetAddress(),0) Node();
            new_node->SetNum(in_num);
            new_node->SetNext(start);
            start = new_node;
        }

    }
}

void List::Delete(int num) {
    Node *current = start;
    Node *prev = NULL;
    while(current != NULL){
        int n_num = current->GetNum();
        if (num == n_num){
            prev->SetNext(current->GetNext());
            collector->Insert((void*)current);
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
    while (current != NULL){
        int num = current->GetNum();
        cout <<  num;
        current = current->GetNext();
    }
    cout << "" << endl;
}

void List::ShowC() {
    collector->Show();
}
