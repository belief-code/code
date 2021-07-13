/*
概要:負辺のないグラフで単一始点全点間最短路を求めるアルゴリズム。
こころ:最初の頂点を島として最短の部分を島として取り込んでどんどん島から最短のものを
島に取り込んでいくイメージのアルゴリズム
実装の工夫:距離順でソートされたヒープを用いると、効率よく距離を確定していくことが出来る。
･dijkstra(g,s):重み付きグラフgで、頂点sから全点間の最短コストを求める。distには最短コスト
(到達できないときは型の最大値)、fromにはその頂点の直前に訪れた頂点(頂点sまたは到達できない頂点は-1)
、idはその頂点の直前に使った辺番号が格納される。

計算量(ElogV)
*/

#pragma once

#include "../graph-template.hpp"

//経路長を保存する型Tを要求
template<typename T>
struct ShortestPath{
    vector<T> dist;
    vector<int> from, id;
};

template<typename T>
ShortestPath<T> dijkstra(const Graph<T> &g,int s){
    const auto INF=numeric_limits<T>::max();
    vector<T> dist(g.size(),INF);
    vector<int> from(g.size(),-1),id(g.size(),-1);
    using Pi=pair<T,int>;
    priority_queue<Pi,vector<Pi>,greater<>> que;
    dist[s]=0;
    //emplaceは与えた値で型のコンストラクタを呼んでオブジェクトを構成しながらpushしてくれる
    //push(make_pair(a,b))やpush({a,b})と同じ。
    que.emplace(dist[s],s);
    while(!que.empty()){
        T cost;
        int idx;
        //これすげー、こんな書き方出来るんだ
        tie(cost,idx)=que.top();
        que.pop();
        //ここ<=ではなく<になってるのは、初めて=となる時に以下のfor文に入りたいから、
        //for文内で<=で挿入の判定してるから一回しか=になることはない。わかりやすく!=にしたいところだけど<のほうが実行速度早いっぽい
        //ライブラリ貼り付けない時は!=で書いたほうがいいかも
        //少しこのコードが分かりづらいのは、ダイクストラ法が成り立つことを前提として書いてあるコードだからだと思う。

        //whileループを回す度に一つの頂点に対して最短経路を確定させる(すでに決まっている場合はcontinue)
        //その頂点から到達可能な頂点もpriority_queueに候補として入れる。
        //priority_queue内の候補は島の隣接頂点全てを網羅しているので、この中で一番コストが低いものは最短で確定する。
        if(dist[idx]<cost)continue;
        for(auto &e:g.g[idx]){
            auto next_cost=cost+e.cost;
            if(dist[e.to]<=next_cost)continue;
            dist[e.to]=next_cost;
            from[e.to]=idx;
            id[e.to]=e.idx;
            que.emplace(dist[e.to],e.to);
        }
    }
    return {dist,from,id};
}