//
// Created by 李林 on 2020/3/26.
//

#ifndef C___QUEUE_H
#define C___QUEUE_H

template <class T>
class Queue
{
private:
    class Node
    {
    public:
        T item;
        Node * next;
    };
    Node *first;
    Node *end;
    int N;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    int size();
    void push(T temp);
    bool pop(T &temp);
};

template<class T>
void Queue<T>::push(T temp)
{
    if(N == 0)
    {
        first = new Node;
        end = first;
        first->item = temp;
        first->next = nullptr;
    }
    else
    {
        Node * newNode = new Node;
        newNode->item = temp;
        newNode->next = nullptr;
        end->next = newNode;
        end = newNode;
    }
    N++;
}

template<class T>
bool Queue<T>::pop(T &temp)
{
    if(N == 0)
        return false;
    Node * old = first;
    temp = first->item;
    first = first->next;
    delete old;
    N--;
    return true;
}

template<class T>
int Queue<T>::size()
{
    return N;
}

template<class T>
bool Queue<T>::isEmpty()
{
    return N == 0;
}

template<class T>
Queue<T>::Queue()
{
    first = nullptr;
    end = nullptr;
    N = 0;
}

template<class T>
Queue<T>::~Queue()
{
    while(first != nullptr)
    {
        Node * old = first;
        first = first->next;
        delete old;
    }
}


#endif //C___QUEUE_H
