//
// Created by 李林 on 2021/2/1.
//

#ifndef C___GRAPH_H
#define C___GRAPH_H

#include <iostream>
#include <vector>
using namespace std;
class Graph
{
public:
    Graph(int v);
    ~Graph();
    void addEdge(int v,int w);
    void adj(int v, vector<int> &vOutPoint);
    int getEdgeCount();
    int getVertexCount();

private:
    int m_EdgeCount;
    int m_MaxVertex;
    vector<int> *m_Adj;
};

void testGraph();
#endif //C___GRAPH_H
