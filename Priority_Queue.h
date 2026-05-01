#pragma once
template <typename E>
class Priority_Queue {
public:
    Priority_Queue() {}
    Priority_Queue(const Priority_Queue<E>& other) = delete;
    void operator=(const Priority_Queue<E>&) = delete;
    virtual ~Priority_Queue() {}
    virtual void insert(E element, int priority) = 0;
    virtual E min() = 0;
    virtual E removeMin() = 0;
    virtual void clear() = 0;
    virtual int getSize() = 0;
    virtual bool is_empty() = 0;
    virtual void print() = 0;
};
