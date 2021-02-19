//
// Created by 李林 on 2021/2/2.
//

#include "DepthFirstSearch.h"

DepthFirstPath::DepthFirstPath(const Graph &sGraph):m_Graph(sGraph)
{
    m_EdgeTo = new int[m_Graph.getVertexCount()];
    m_pMarked = new bool [m_Graph.getVertexCount()];
    if(m_EdgeTo == nullptr || m_pMarked == nullptr)
    {
        return;
    }
    memset(m_pMarked,0,m_Graph.getVertexCount());
    memset(m_EdgeTo,0,m_Graph.getVertexCount());
}

DepthFirstPath::~DepthFirstPath()
{
    if(m_pMarked != nullptr)
    {
        delete [] m_pMarked;
        m_pMarked = nullptr;
    }
}

bool DepthFirstPath::bPathTo(int iFrom, int iTo,list<int> &lPath)
{
    memset(m_pMarked,0,m_Graph.getVertexCount());
    memset(m_EdgeTo,0,m_Graph.getVertexCount());
    dfs(iFrom,iTo);
    for(int i = 0; i < m_Graph.getVertexCount(); i++)
    {
        cout<<i<<"???"<<m_pMarked[i]<<endl;
    }
    if(!m_pMarked[iTo])
    {
        return false;
    }

    lPath.clear();
    for(int w = iTo; w != iFrom; w = m_EdgeTo[w])
    {
        lPath.push_front(w);
    }
    lPath.push_front(iFrom);
    return true;
}

void DepthFirstPath::dfs(int iFrom, int iTo)
{
    m_pMarked[iFrom] = true;
    if(iFrom == iTo)
    {

        return;
    }
    vector<int> vAdj;
    m_Graph.adj(iFrom,vAdj);
    for(auto &x : vAdj)
    {
        if(!m_pMarked[x])
        {
            m_EdgeTo[x] = iFrom;
            dfs(x,iTo);
        }
    }
}


void testDepthFirstPath()
{
    Graph g(10);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(8,9);
    g.addEdge(9,7);
    g.addEdge(7,4);
    DepthFirstPath x(g);
    list<int> lPath;
    bool bRet = x.bPathTo(1,6,lPath);
    cout<<"path:"<<bRet<<endl;
    for(auto & temp : lPath)
        cout<<temp<<endl;
}