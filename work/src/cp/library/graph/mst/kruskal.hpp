/*
概要:最小全域木を求める。Union-Findを用いて辺集合にある辺を加えて閉路を作らないか判定しながら、
辺を重みが小さい順に走査する。

-kruskal(edges,V):V 頂点の連結な重み付き辺集合edgesからなる重み付き連結グラフの最小全域木を求める。
costには辺の重みの総和、edgesにはそれを構成する辺が格納される。


*/

#pragma once

#include "../graph-template.hpp"
#include "../../structure/union-find/union-find.hpp"

template<typename T>
struct MinimumSpanningTree{
    T cost;
    Edges<T> edges;
};

template<typename T>
MinimumSpanningTree<T> kruskal(Edges<T> &edges,int V){
    sort(begin(edges),end(edges),[](const Edge<T> &a,const Edge<T> &b){
        return a.cost<b.cost;
    });
    UnionFind tree(V);
    //どうやら型名()でその型の0に当るものがもらえるらしい
    T total=T();
    Edges<T> es;
    for(auto &e:edges){
        if(tree.unite(e.from,e.to)){
            es.emplace_back(e);
            total+=e.cost;
        }
    }
    return {total,es};
}

