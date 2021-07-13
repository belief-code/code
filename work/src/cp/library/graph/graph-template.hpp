#pragma once

template <typename T=int>
struct Edge{
    int from,to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx) {}

    operator int() const {return to;}
};


template< typename T=int >
struct Graph{
    //問題の受けを広くするために各頂点からのエッジ情報にわざわざ辺の元情報が載ってる
    vector<vector<Edge<T>>> g;
    int es;

    Graph()=default;

    explicit Graph(int n) :g(n),es(0) {}

    size_t size() const {
        return g.size();
    }

    //有向辺を追加
    void add_directed_edge(int from,int to,T cost=1){
        g[from].emplace_back(from,to,cost,es++);
    }

    void add_edge(int from,int to,T cost=1){
        g[from].emplace_back(from,to,cost,es);
        g[to].emplace_back(to,from,cost,es++);
    }

    //グラフの構成。Mを要素数として色々カスタム可能
    void read(int M,int padding=-1,bool weighted=false,bool directed=false){
        for(int i=0;i<M;i++){
            int a,b;
            cin>>a>>b;
            a+=padding;
            b+=padding;
            T c =T(1);
            if(weighted)cin>>c;
            if(directed)add_directed_edge(a,b,c);
            else add_edge(a,b,c);
            b+=padding;
            T c =T(1);

            if(weighted)cin>>c;
            if(directed)add_directed_edge(a,b,c);
            else add_edge(a,b,c);
        }
    }
};

template<typename T=int>
using Edges = vector<Edge<T>>;

