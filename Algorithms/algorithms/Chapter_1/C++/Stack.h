//
// Created by 李林 on 2020/3/24.
//

#ifndef C___STACK_H
#define C___STACK_H

template <class T>
class Stack
{
public:
    Stack(){first.next = nullptr;}
    bool isEmpty();
    int size();
    void push(T item);
    T pop();

private:
    class Node
    {
    public:
        T item;
        Node * next;
    };
    int N;          //
    Node first;
};

template<class T>
bool Stack<T>::isEmpty()
{
    return N == 0;
}

template<class T>
int Stack<T>::size()
{
    return N;
}

template<class T>
void Stack<T>::push(T item)
{
    Node *tempItem;
    tempItem = new Node();
    if(tempItem != nullptr)
    {
        tempItem->next = first.next;
        tempItem->item = item;
        first.next = tempItem;
    }
}

template <class T>
T Stack<T>::pop()
{
    T Ret;
    Node * pNode = first.next;
    if(pNode != nullptr)
    {
        Ret = pNode->item;
        first.next = pNode->next;
        delete pNode;
    }
    return Ret;
}

#endif //C___STACK_H
