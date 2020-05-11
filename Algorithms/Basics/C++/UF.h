//
// Created by 李林 on 2020/3/29.
//

#ifndef C___UF_H
#define C___UF_H

class UF
{
private:
    int *id;      // id数组
    int count;  // 统计连通区域数量
public:
    explicit UF(int n);
    void quick_union(int a, int b);
    int find(int x);
    bool isConnected(int a, int b);
    ~UF();
};

UF::~UF()
{
    delete [] id;
}

UF::UF(int n)
{
    id = new int[n+1];
    for(int i = 0; i <= n; i++)
        id[i] = i;
    count = n;
}

void UF::quick_union(int a, int b)
{
    int a_root = find(a);
    int b_root = find(b);
    if(a_root == b_root)
        return;
    id[a_root] = b_root;
    count--;
}

int UF::find(int x)
{
    while(x != id[x])
        x = id[x];
    return x;
}

bool UF::isConnected(int a, int b)
{
    return find(a) == find(b);
}


#endif //C___UF_H
