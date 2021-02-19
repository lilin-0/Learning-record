//
// Created by 李林 on 2021/2/1.
//

#include "Graph.h"

Graph::Graph(int v)
{
    m_Adj = new vector<int> [v];
    if(m_Adj == nullptr)
    {
        return;
    }
    m_MaxVertex = v;
    for(int i = 0; i < v; i++)
    {
        m_Adj[i].clear();
    }
}

Graph::Graph(const Graph &x)
{
    m_Adj = new vector<int> [x.m_MaxVertex];
    if(m_Adj == nullptr)
    {
        return;
    }
    m_MaxVertex = x.m_MaxVertex;
    for(int i = 0; i < m_MaxVertex; i++)
    {
        m_Adj[i] = x.m_Adj[i];
    }
    m_EdgeCount = x.m_EdgeCount;
}

Graph::~Graph()
{
    delete [] m_Adj;
}

void Graph::addEdge(int v, int w)
{
    if(v >= m_MaxVertex || w >= m_MaxVertex)
    {
        cout<<"error. v:"<<v<<" w:"<<w<<endl;
        return;
    }
    m_Adj[v].push_back(w);
    m_Adj[w].push_back(v);
    m_EdgeCount++;
}

void Graph::adj(int v, vector<int> &vOutPoint) const
{
    if(v >= m_MaxVertex)
    {
        return;
    }
    vOutPoint = m_Adj[v];
}

int Graph::getEdgeCount() const
{
    return m_EdgeCount;
}

int Graph::getVertexCount() const
{
    return m_MaxVertex;
}

void testGraph()
{
    Graph w(10);
    w.addEdge(1,3);
    w.addEdge(2,3);
    w.addEdge(3,8);
    w.addEdge(5,4);
    w.addEdge(7,4);
    w.addEdge(7,9);
    vector<int> out;
    w.adj(7,out);
    for_each(out.begin(),out.end(),[](int x){cout<<x<<endl;});
}