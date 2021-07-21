/*
概要
-unite(x,y):集合xとyを併合する。併合済みのときfalse,未併合のときtrueを返す。
-find(k):要素kが属する集合を求める
-size(k):要素kが属する集合の要素の数を求める
-same(x,y):要素x,yが同じ集合に属するか判定する
-groups():各集合に含まれる要素を返す

計算量
-クエリ:ならしO(α(N))(αはアッカーマンの逆関数)
*/



struct UnionFind{
    vector<int> data;

    Unionfind()=data;

    explicit UnionFind(size_t sz):data(sz,-1) {}

    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return false;
        if(data[x]>data[y])swap(x,y);
        data[x]+=data[y];
        data[y]=x;
        return true;
    }

    int find(int k){
        if(data[k]<0) return (k);
        return data[k]=find(data[k]);
    }

    int size(int k){
        return -data[find(k)];
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }

    vector<vector<int>> groups(){
        int n=(int) data.size();
        vector<vector<int>> ret(n);
        for(int i=0;i<n;i++){
            ret[find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret),end(ret),[&](const vector<int> &v){
            return v.empty();
        }));
        return ret;
    }
};