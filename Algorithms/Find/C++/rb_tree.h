//
// Created by 李林 on 2020/6/8.
//

#ifndef C___RB_TREE_H
#define C___RB_TREE_H

template <class TYPE_KEY,class TYPE_VAL>
class rbTree
{
private:
    /* 定义颜色 */
    typedef enum
    {
        COLOUR_UNDEF,
        COLOUR_RED,
        COLOUR_BLACK
    }COLOUR;
    struct RBNode
    {
        TYPE_KEY key;
        TYPE_VAL val;
        RBNode *pLeft;
        RBNode *pRight;
        COLOUR colour;
        int N;
        RBNode():pLeft(nullptr),pRight(nullptr),colour(COLOUR_UNDEF),N(0){};        //默认构造函数
        RBNode(const TYPE_KEY &k,const TYPE_VAL &v, RBNode *pL, RBNode *pR): key(k),val(v),colour(COLOUR_RED),pLeft(pL),pRight(pR),N(1){}
    };
    RBNode * root;
    RBNode * NIL;       //哨兵节点
public:
    rbTree();
    ~rbTree();
    int size();
    void put(const TYPE_KEY &key, const TYPE_VAL &val);
    bool getVal(const TYPE_KEY &key, TYPE_VAL &val);
    void deleteKey(const TYPE_KEY &key);
    void clear();

private:
    bool isRed(RBNode *pNode);
    bool isBlack(RBNode *pNode);
    int size(RBNode *pNode);
    RBNode *rotateLeft(RBNode *pNode);
    RBNode *rotateRight(RBNode *pNode);
    void flipColour(RBNode *pNode);
    RBNode *put(RBNode *pNode, const TYPE_KEY &key, const TYPE_VAL &val);
    RBNode *get(RBNode *pNode, const TYPE_KEY &key);
    RBNode *deleteKey(RBNode *pNode, const TYPE_KEY &key);
    RBNode *balance(RBNode *pNode);
    RBNode *clear(RBNode *pNode);
};

template<class TYPE_KEY, class TYPE_VAL>
rbTree<TYPE_KEY, TYPE_VAL>::rbTree()
{
    NIL = new RBNode();
    root = NIL;
}

template<class TYPE_KEY, class TYPE_VAL>
rbTree<TYPE_KEY, TYPE_VAL>::~rbTree()
{
    //clear();
    delete NIL;
}

template<class TYPE_KEY, class TYPE_VAL>
int rbTree<TYPE_KEY, TYPE_VAL>::size()
{
    return size(root);
}

template<class TYPE_KEY, class TYPE_VAL>
void rbTree<TYPE_KEY, TYPE_VAL>::put(const TYPE_KEY &key, const TYPE_VAL &val)
{
    root = put(root, key, val);
    root->colour = COLOUR_BLACK;
}

template<class TYPE_KEY, class TYPE_VAL>
bool rbTree<TYPE_KEY, TYPE_VAL>::getVal(const TYPE_KEY &key, TYPE_VAL &val)
{
    RBNode *pNode = get(root,key);
    if(pNode == NIL)
        return false;
    val = pNode->val;
    return true;
}

template<class TYPE_KEY, class TYPE_VAL>
void rbTree<TYPE_KEY, TYPE_VAL>::deleteKey(const TYPE_KEY &key)
{
    root = deleteKey(root,key);
    root->colour = COLOUR_BLACK;
}

template<class TYPE_KEY, class TYPE_VAL>
void rbTree<TYPE_KEY, TYPE_VAL>::clear()
{
    clear(root);
    root = NIL;
}

template<class TYPE_KEY, class TYPE_VAL>
bool rbTree<TYPE_KEY, TYPE_VAL>::isRed(rbTree::RBNode *pNode)
{
    if(pNode == NIL)
        return false;
    return pNode->colour == COLOUR_RED;
}

template<class TYPE_KEY, class TYPE_VAL>
bool rbTree<TYPE_KEY, TYPE_VAL>::isBlack(rbTree::RBNode *pNode)
{
    if(pNode == NIL)
        return false;
    return pNode->colour == COLOUR_BLACK;
}

template<class TYPE_KEY, class TYPE_VAL>
int rbTree<TYPE_KEY, TYPE_VAL>::size(rbTree::RBNode *pNode)
{
    return pNode->N;
}

template<class TYPE_KEY, class TYPE_VAL>
typename rbTree<TYPE_KEY, TYPE_VAL>::RBNode *rbTree<TYPE_KEY, TYPE_VAL>::rotateLeft(rbTree::RBNode *pNode)
{
    RBNode *tNode = pNode->pRight;
    pNode->pRight = tNode->pLeft;
    tNode->pLeft = pNode;
    tNode->colour = pNode->colour;
    pNode->colour = COLOUR_RED;
    tNode->N = pNode->N;
    pNode->N = 1 + size(pNode->pLeft) + size(pNode->pRight);
    return tNode;
}

template<class TYPE_KEY, class TYPE_VAL>
typename rbTree<TYPE_KEY, TYPE_VAL>::RBNode *rbTree<TYPE_KEY, TYPE_VAL>::rotateRight(rbTree::RBNode *pNode)
{
    RBNode *tNode = pNode->pLeft;
    pNode->pLeft = tNode->pRight;
    tNode->pRight = pNode;
    tNode->colour = pNode->colour;
    pNode->colour = COLOUR_RED;
    tNode->N = pNode->N;
    pNode->N = 1 + size(pNode->pLeft) + size(pNode->pRight);
    return tNode;
}

template<class TYPE_KEY, class TYPE_VAL>
void rbTree<TYPE_KEY, TYPE_VAL>::flipColour(rbTree::RBNode *pNode)
{
    pNode->colour = COLOUR_RED;
    pNode->pLeft->colour = COLOUR_BLACK;
    pNode->pRight->colour = COLOUR_BLACK;
}

template<class TYPE_KEY, class TYPE_VAL>
typename rbTree<TYPE_KEY, TYPE_VAL>::RBNode *rbTree<TYPE_KEY, TYPE_VAL>::put(rbTree::RBNode *pNode, const TYPE_KEY &key, const TYPE_VAL &val)
{
    if(pNode == NIL)
        return new RBNode(key,val,NIL,NIL);
    if(key < pNode->key)
        pNode->pLeft = put(pNode->pLeft, key, val);
    else if(pNode->key < key)
        pNode->pRight = put(pNode->pRight, key, val);
    else
        pNode->val = val;

    if(isRed(pNode->pRight) && isBlack(pNode->pLeft))
        pNode = rotateLeft(pNode);
    if(isRed(pNode->pLeft) && isRed(pNode->pLeft->pLeft))
        pNode = rotateRight(pNode);
    if(isRed(pNode->pLeft) && isRed(pNode->pRight))
        flipColour(pNode);
    pNode->N = 1 + size(pNode->pLeft) + size(pNode->pRight);
    return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
typename rbTree<TYPE_KEY, TYPE_VAL>::RBNode *rbTree<TYPE_KEY, TYPE_VAL>::get(rbTree::RBNode *pNode, const TYPE_KEY &key)
{
    if(pNode == NIL)
        return NIL;
    if(key < pNode->key)
        return get(pNode->pLeft,key);
    else if(pNode->key < key)
        return get(pNode->pRight,key);
    else
        return pNode;
}

template<class TYPE_KEY, class TYPE_VAL>
typename rbTree<TYPE_KEY, TYPE_VAL>::RBNode *rbTree<TYPE_KEY, TYPE_VAL>::balance(rbTree::RBNode *pNode)
{
    if(pNode == NIL)
        return pNode;

    if(isRed(pNode->pRight) && isBlack(pNode->pLeft))
        pNode = rotateLeft(pNode);
    if(isRed(pNode->pLeft) && isRed(pNode->pLeft->pLeft))
        pNode = rotateRight(pNode);
    if(isRed(pNode->pLeft) && isRed(pNode->pRight))
        flipColour(pNode);
    pNode->N = 1 + size(pNode->pLeft) + size(pNode->pRight);
    return nullptr;
}

template<class TYPE_KEY, class TYPE_VAL>
typename rbTree<TYPE_KEY, TYPE_VAL>::RBNode *rbTree<TYPE_KEY, TYPE_VAL>::deleteKey(rbTree::RBNode *pNode, const TYPE_KEY &key)
{

    return nullptr;
}


#endif //C___RB_TREE_H
