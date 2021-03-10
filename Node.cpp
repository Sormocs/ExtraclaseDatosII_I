#include "Node.h"
#include "Collector.h"
#include <stdlib.h>
Node::Node() {
}

int Node::GetNum() {
    return num;
}

void Node::SetNum(int in_num) {
    num = in_num;
}

void Node::SetNext(Node * in_node) {
    next = in_node;
}

Node * Node::GetNext() {
    return next;
}

void * Node::operator new(size_t size, void* address, int num) {

    if (address == NULL){
        Node* new_node = ::new Node();
        return new_node;
    } else{
        std::cout << "address " << address << std::endl;
        return address;
    }
}

void Node::operator delete(void * del_dir) noexcept {
    free(del_dir);
}