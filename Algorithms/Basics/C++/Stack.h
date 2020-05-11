//
// Created by 李林 on 2020/3/24.
//

#ifndef C___STACK_H
#define C___STACK_H

template <class T>
class Stack
{
public:
    Stack(){first.next = nullptr; N = 0;}
    bool isEmpty();
    int size();
    void push(T item);
    bool pop(T &item);

private:
    class Node
    {
    public:
        T item;
        Node * next;
    };
    int N{};          //
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
    tempItem->next = first.next;
    tempItem->item = item;
    first.next = tempItem;
}

template <class T>
bool Stack<T>::pop(T &item)
{
    Node * pNode = first.next;
    if(pNode != nullptr)
    {
        item = pNode->item;
        first.next = pNode->next;
        delete pNode;
        return true;
    }
    return false;
}

#endif //C___STACK_H
