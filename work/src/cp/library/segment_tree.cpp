/*
    セグメントツリーは二項演算の定義されたモノイド上で定義される
      二項演算関数 f(x, y) を構造体に渡す
    // Construction
    SegTree(n, f, unity): サイズ n に初期化、f は二項演算、identity は単位元 (min なら INF, + なら 0)
      ex
      ・区間和: SegTree<int> seg(n, [](int a, int b){ return a + b; }, 0);
      ・区間min: SegTree<int> seg(n, [](int a, int b}{ return min(a, b); }, INF);
    // Initialization
    init(n): サイズ n に初期化
    set(a, v): a 番目の値を v にセットする
    build(): set した値を元にセグメントツリー全体を構築する、O(n)

    // Queries
    update(a, v): a 番目の値を v に更新する, O(log n)
    get(a, b): 区間 [a, b) についての演算結果を返す, O(log n)
*/

template<class Monoid> struct SegTree{
	using Func=function<Monoid(Monoid, Monoid)>;
	Func F;
	Monoid IDENTITY;
	int SIZE_R;
	vector<Monoid> dat;

	SegTree() {}
	SegTree(int n,const Func f,const Monoid &identity): F(f),IDENTITY(identity){
		SIZE_R = 1;
		while (SIZE_R < n) SIZE_R *= 2;
		dat.assign(SIZE_R * 2, IDENTITY);
	}
	void init(int n,const Func f,const Monoid &identity){
		IDENTITY = identity;
		F= f;
		SIZE_R = 1;
		while(SIZE_R < n) SIZE_R *= 2;
		dat.assign(SIZE_R * 2, IDENTITY);
	}

	/* set, a is 0-indexed */
	void set(int a, const Monoid &v){ dat[a + SIZE_R] = v; }
	void build(){
		for (int k = SIZE_R - 1; k > 0; --k)
			dat[k] = F(dat[k*2],dat[k*2+1]);
	}

	/* update a, a is 0-indexed */
	void update(int a, const Monoid &v){
		int k = a + SIZE_R;
		dat[k] = v;
		while (k >>= 1) dat[k] = F(dat[k*2],dat[k*2+1]);
	}

	/* get [a, b), a and b are 0-indexed */
	Monoid get(int a, int b){
		Monoid vleft = IDENTITY, vright = IDENTITY;
		for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>=1, right >>=1){
			if (left & 1) vleft = F(vleft, dat[left++]);
			if (right & 1) vright = F(dat[--right],vright);
		}
		return F(vleft, vright);
	}
	inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

	/* debug */
	void print() {
		for (int i = 0; i < SIZE_R; ++i) {
			cout << (*this)[i];
			if (i != SIZE_R-1) cout << ",";
		}
		cout << endl;
	}
};

//解説(詰まりそうなところだけ)
/*
このセグ木は、1-indexedな配列で構成されている。このほうが色々と勝手が良いからである。その説明をしていく。
まず1-indexedにしたときの構成を最上段から書いていく。なお2進数表示に注意。
0 :要素1個 :累計要素数1個　:添字0スタート(これは実際にはセグ木に用いられない)

1 :要素1個 :累計要素数10個 :添字1スタート
10,11 :要素10個 :累計要素数100個 :添字10スタート
100,101|110,111 :要素100個 :累計要素数1000個 :添字100スタート
1000,1001|1010,1011||1100,1101|1110,1111 :要素1000個 :累計要素数10000個 :添字1000スタート

親kから見た子:2k,2k+1
子kから見た親:k/2 (切り捨て)
最下段の要素数n個のときの累計要素数:2n
要素数nの段の先頭の添字:n

このように0スタートでやると-1がついたりするけどこんな感じでつけずにキレイに各種パラメーターを書ける。
*/
template<class Monoid> struct SegTree{
	using Func=function<Monoid(Monoid, Monoid)>;
	Func F;
	Monoid IDENTITY;
	int SIZE_R;
	vector<Monoid> dat;

	SegTree() {}
	SegTree(int n,const Func f,const Monoid &identity): F(f),IDENTITY(identity){
		SIZE_R = 1;
		while (SIZE_R < n) SIZE_R *= 2;
		dat.assign(SIZE_R * 2, IDENTITY);
	}
	void init(int n,const Func f,const Monoid &identity){
		IDENTITY = identity;
		F= f;
		SIZE_R = 1;
		while(SIZE_R < n) SIZE_R *= 2;
		dat.assign(SIZE_R * 2, IDENTITY);
	}

	/* set, a is 0-indexed */
	void set(int a, const Monoid &v){ dat[a + SIZE_R] = v; }
	void build(){
		for (int k = SIZE_R - 1; k > 0; --k)
			dat[k] = F(dat[k*2],dat[k*2+1]);
	}

	/* update a, a is 0-indexed */
	void update(int a, const Monoid &v){
		int k = a + SIZE_R;
		dat[k] = v;
		while (k >>= 1) dat[k] = F(dat[k*2],dat[k*2+1]);
	}

	/* get [a, b), a and b are 0-indexed */
	Monoid get(int a, int b){
		Monoid vleft = IDENTITY, vright = IDENTITY;
		//for文の中で、どのようなleft,rightの状況で演算を行うと最低限の演算数になるのか考える。
		//これは当然山の裾のようになっている場合で、rightが右開区間であることに注意すると、その場合はそれぞれ
		//left==1,right==1である。つまりこのような状況になったときのみ、その添字によって指定された要素を演算していけば良い。
		for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>=1, right >>=1){
			//山の左側の裾にいるときはそこだけ考慮して一つ右の親に移動するためにインクリメントを行う
			if (left & 1) vleft = F(vleft, dat[left++]);
			//山の右側の裾にいるときは右開区間であることに注意すると、常にひとつ左の要素を常に見ていることに
			//注意すると裾は、0に対応するがその裾に対応するrightは1で有ることがわかるはず。
			//ということは演算すべきタイミングは、rightが1の時だけ演算していけば最低限の演算が可能
			if (right & 1) vright = F(dat[--right],vright);
		}
		return F(vleft, vright);
	}
	inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

	/* debug */
	void print() {
		for (int i = 0; i < SIZE_R; ++i) {
			cout << (*this)[i];
			if (i != SIZE_R-1) cout << ",";
		}
		cout << endl;
	}
};
