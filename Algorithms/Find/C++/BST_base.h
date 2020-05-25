//
// Created by 李林 on 2020/5/24.
//

#ifndef C___BST_BASE_H
#define C___BST_BASE_H

template <class TYPE_KEY,class TYPE_VAL>
class BST_base
{
private:
    struct Node
    {
        TYPE_KEY key;
        TYPE_VAL val;
        int N;          //当前节点作为根时，树的所有节点个数
        Node *pLeft;
        Node *pRight;
        Node():key(TYPE_KEY()),val(TYPE_VAL()),N(0),pLeft(nullptr),pRight(nullptr){}
        Node(const TYPE_KEY &k,const TYPE_VAL &v,const int &n):key(k),val(v),N(n),pLeft(nullptr),pRight(nullptr){}
    };
    Node *root;
public:
    BST_base() = default;
    ~BST_base();
    int size();
    TYPE_VAL get(const TYPE_KEY &key);
    void put(const TYPE_KEY &key, const TYPE_VAL &val);
    TYPE_KEY minKey();
    TYPE_KEY maxKey();
    TYPE_KEY floor(const TYPE_KEY &key);        // 从二叉树中查找最接近指定key的key（向下取整）
    TYPE_KEY select(const int k);
    int rank(const TYPE_KEY &key);
    void deleteMinKey();
    void deleteMaxKey();
    void deleteKey(const TYPE_KEY &key);
private:
    int size(Node *pNode);
    auto get(const Node *pNode, const TYPE_KEY &key);
    auto put(Node *pNode, const TYPE_KEY &key, const TYPE_VAL &val);
    auto minKey(Node *pNode);
    auto maxKey(const Node *pNode);
    auto floor(const Node *pNode, const TYPE_KEY &key);
    auto select(const Node *pNode, const int &k);
    int rank(const Node *pNode, const TYPE_KEY &key);
    auto deleteMinKey(Node *pNode);
    auto deleteMaxKey(Node *pNode);
    auto deleteKey(Node *pNode, const TYPE_KEY &key);
};

template <class TYPE_KEY, class TYPE_VAL>
int BST_base<TYPE_KEY,TYPE_VAL>::size()
{
    return size(root);
}

template<class TYPE_KEY, class TYPE_VAL>
TYPE_VAL BST_base<TYPE_KEY, TYPE_VAL>::get(const TYPE_KEY &key)
{
    const Node *pNode = get(root,key);
    if(pNode == nullptr)
        return TYPE_VAL();
    return pNode->val;
}

template<class TYPE_KEY, class TYPE_VAL>
void BST_base<TYPE_KEY, TYPE_VAL>::put(const TYPE_KEY &key, const TYPE_VAL &val)
{
    root = put(root, key, val);
}

template<class TYPE_KEY, class TYPE_VAL>
TYPE_KEY BST_base<TYPE_KEY, TYPE_VAL>::minKey()
{
    const Node *pNode = minKey(root);
    if(pNode == nullptr)
        return TYPE_KEY();
    return pNode->key;
}

template<class TYPE_KEY, class TYPE_VAL>
TYPE_KEY BST_base<TYPE_KEY, TYPE_VAL>::maxKey()
{
    const Node *pNode = maxKey(root);
    if(pNode == nullptr)
        return TYPE_KEY();
    return pNode->key;
}

template<class TYPE_KEY, class TYPE_VAL>
TYPE_KEY BST_base<TYPE_KEY, TYPE_VAL>::floor(const TYPE_KEY &key)
{
    const Node *pNode = floor(root, key);
    if(pNode == nullptr)
        return TYPE_KEY();
    return pNode->key;
}

template<class TYPE_KEY, class TYPE_VAL>
TYPE_KEY BST_base<TYPE_KEY, TYPE_VAL>::select(const int k)
{
    const Node *pNode = select(root,k);
    if(pNode == nullptr)
        return TYPE_KEY();
    return pNode->key;
}

template<class TYPE_KEY, class TYPE_VAL>
int BST_base<TYPE_KEY, TYPE_VAL>::rank(const TYPE_KEY &key)
{
    return rank(root, key);
}

template<class TYPE_KEY, class TYPE_VAL>
void BST_base<TYPE_KEY, TYPE_VAL>::deleteMinKey()
{
    root = deleteMinKey(root);
}

template<class TYPE_KEY, class TYPE_VAL>
void BST_base<TYPE_KEY, TYPE_VAL>::deleteMaxKey()
{
    root = deleteMaxKey(root);
}

template<class TYPE_KEY, class TYPE_VAL>
void BST_base<TYPE_KEY, TYPE_VAL>::deleteKey(const TYPE_KEY &key)
{
    root = deleteKey(root,key);
}
/**************************分割线，私有函数**************************/
template<class TYPE_KEY, class TYPE_VAL>
int BST_base<TYPE_KEY, TYPE_VAL>::size(BST_base::Node *pNode)
{
    if(pNode == nullptr)
        return 0;
    return pNode->N;
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::get(const BST_base::Node *pNode, const TYPE_KEY &key)
{
    if(pNode == nullptr)
        return pNode;
    if(key < pNode->key)
        return get(pNode->pLeft, key);
    else if(pNode->key < key)
        return get(pNode->pRight, key);
    else
        return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::put(Node *pNode, const TYPE_KEY &key, const TYPE_VAL &val)
{
    if(pNode == nullptr)
        return new Node(key, val, 1);
    if(key < pNode->key)
        pNode->pLeft = put(pNode->pLeft, key, val);
    else
        pNode->pRight = put(pNode->pRight, key, val);
    pNode->N = size(pNode->pLeft) + size(pNode->pLeft) + 1;
    return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::minKey(BST_base::Node *pNode)
{
    if(pNode == nullptr)
        return pNode;
    if(pNode->pLeft == nullptr)
        return pNode;
    return minKey(pNode->pLeft);
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::maxKey(const BST_base::Node *pNode)
{
    if(pNode == nullptr)
        return pNode;
    if(pNode->pRight == nullptr)
        return pNode;
    return maxKey(pNode->pRight);
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::floor(const BST_base::Node *pNode, const TYPE_KEY &key)
{
    if(pNode == nullptr)
        return pNode;
    if(key < pNode->key)
        return floor(pNode->pLeft, key);
    else if(pNode->key < key)
    {
        /* 从右子树中查找key，当没有找到的时候，当前节点的key为符合条件的key */
        const Node *tNode = floor(pNode->pRight, key);
        if(tNode != nullptr)
            return tNode;
        return pNode;
    }
    else
        return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::select(const Node *pNode, const int &k)
{
    if(pNode == nullptr)
        return pNode;
    int tSize = size(pNode->pLeft);
    if(tSize == k)
        return pNode;
    else if(tSize < k)
        return select(pNode->pRight, k - tSize - 1);
    return select(pNode->pLeft, k);
}

template<class TYPE_KEY, class TYPE_VAL>
int BST_base<TYPE_KEY, TYPE_VAL>::rank(const BST_base::Node *pNode, const TYPE_KEY &key)
{
    if(pNode == nullptr)
        return -1;

    if(key < pNode->key)
        return rank(pNode->pLeft, key);
    else if(pNode->key < key)
        return rank(pNode->pRight, key) + size(pNode);
    else
        return size(pNode->pLeft);
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::deleteMinKey(BST_base::Node *pNode)
{
    if(pNode == nullptr)
        return pNode;
    if(pNode->pLeft == nullptr)
    {
        Node *tNode = pNode->pRight;
        delete pNode;
        return tNode;
    }
    pNode->pLeft = deleteMinKey(pNode->pLeft);
    pNode->N = size(pNode->pLeft) + size(pNode->pRight) + 1;
    return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::deleteMaxKey(BST_base::Node *pNode)
{
    if(pNode == nullptr)
        return pNode;
    if(pNode->pRight == nullptr)
    {
        Node *tNode = pNode->pLeft;
        delete pNode;
        return tNode;
    }

    pNode->pRight = deleteMaxKey(pNode->pRight);
    pNode->N = size(pNode->pLeft) + size(pNode->pRight) + 1;
    return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
auto BST_base<TYPE_KEY, TYPE_VAL>::deleteKey(BST_base::Node *pNode,const TYPE_KEY &key)
{
    if(pNode == nullptr)
        return pNode;
    if(pNode->key < key)
        pNode->pRight = deleteKey(pNode->pRight, key);
    else if(key < pNode->key)
        pNode->pLeft = deleteKey(pNode->pLeft, key);
    else
    {
        if(pNode->pRight == nullptr)
        {
            Node *tNode = pNode->pLeft;
            delete pNode;
            return tNode;
        }
        if(pNode->pLeft == nullptr)
        {
            Node *tNode = pNode->pLeft;
            delete pNode;
            return pNode->pRight;
        }
        Node *tNode = pNode;
        pNode = minKey(tNode->pRight);
        pNode->pRight = deleteMinKey(tNode->pRight);
        pNode->pLeft = tNode->pLeft;
    }
    pNode->N = size(pNode->pLeft) + size(pNode->pRight) + 1;
    return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
BST_base<TYPE_KEY, TYPE_VAL>::~BST_base()
{
    while(size(root))
        deleteMinKey();
}


#endif //C___BST_BASE_H
