//
// Created by 李林 on 2021/2/2.
//

#ifndef C___DEPTHFIRSTSEARCH_H
#define C___DEPTHFIRSTSEARCH_H

#include "../Graph/Graph.h"
#include <list>
class DepthFirstPath
{
public:
    explicit DepthFirstPath(const Graph &sGraph);
    ~DepthFirstPath();
    bool bPathTo(int iFrom, int iTo, list<int> &lPath);
private:
    void dfs(int iFrom, int iTo);
    bool *m_pMarked;
    int *m_EdgeTo;
    Graph m_Graph;
};


void testDepthFirstPath();
#endif //C___DEPTHFIRSTSEARCH_H
