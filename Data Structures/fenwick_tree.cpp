template<typename T> class fenwick_tree {
private: vector<T> FT;
public:
	fenwick_tree(int N) { FT.assign(N + 5, 0); }
	void update(int x, T val) { if (++x) for (; x < FT.size(); x += x & -x) FT[x] += val; }
	T query(int x) { T ret = 0; if (++x) for (; x; x -= x & -x) ret += FT[x]; return ret; }
	T query(int x, int y) { return query(y) - query(x - 1); }
};