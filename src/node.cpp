#include "node.h"

Node::Node(size_t capacity) : capacity_(capacity){
    data_ = new Data[capacity_];
    next_ = new Node*[10];
    size_ = 0;
    degree_ = 0;
}

std::ostream &operator<<(std::ostream &out, const Node &right){
    out << "{";
    bool first = true;
    for(int i = 0; i < right.size_; ++i){
        if(first)first = false;
        else out << " ";
        out << right.data_[i].key_;
    }
    out << "}";
    for(int i = 0; i < right.degree_; ++i){
        if(right.next_[i] != nullptr)
            out << *right.next_[i] << " ";
    }

    return out;
}

void Node::insert(Data data){
    if(size_ == capacity_){
        throw Exception();
    }
    data_[size_++] = data;
}

void Node::erase(int key){
    int offset = getOffsetByKey(key);
    for(int i = offset; i < size_-1; ++i){
        data_[i] = data_[i+1];
    }
    --size_;
}

Node *Node::find(int key){
    for(int i = 0; i < size_; ++i){
        if(data_[i].key_ == key)
            return this;
    }
    return NULL;
}

void Node::update(int key, int data){
    int offset = getOffsetByKey(key);
    data_[offset] = data;
}

int Node::getOffsetByKey(int key){
    for(int i = 0; i < size_; ++i){
        if(data_[i].key_ == key)
            return i;
    }
    throw Exception();
}

void Node::addEdge(){
   next_[++degree_] = nullptr;
}