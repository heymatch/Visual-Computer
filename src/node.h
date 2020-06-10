/**
 * Node
 * - Single Node
 * - Array Node
 */

#ifndef NODE
#define NODE

#include <cstdlib>
#include <iostream>
#include "exception.h"

struct Data{
    Data(int key = 0, int data = 0){
        key_ = key;
        data_ = data;
    }
    bool operator<(const Data &right) const{
        return key_ < right.key_;
    }
    int key_;
    int data_;
};

class Node{
    friend std::ostream &operator<<(std::ostream &out, const Node &right);
public:
    Node(size_t capacity = 0);

    virtual void insert(Data data);
    virtual Node *find(int key);
    virtual void update(int key, int data);
    virtual void erase(int key);

    inline Data getData(int offset = 0) { return data_[offset]; }
    inline size_t getDegree() { return degree_; }
    
    inline bool isFull() { return size_ == capacity_; }
    inline bool isEmpty() { return size_ == 0; }
protected:
    int getOffsetByKey(int key);
    void addEdge();

    Data *data_;
    Node **next_;
private:
    size_t degree_;
    size_t capacity_;
    size_t size_;
};

#endif