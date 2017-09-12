
#include <bits/stdc++.h>
using namespace std;

//typedef long long ll;

const int MAX_N = 300005; // max input size;
const int MAX_Q = 2000006; // max number of queries
const int SQRTN = 175;  // sqrt(MAX_N)

int input[MAX_N]; //input array;
int q_ans[MAX_Q]; //answer of i'th query

struct query {
    int l, r, q_idx, block_idx; // left of query , right of query, index of query before sorting, block index of l;

    query() {}
    query(int left, int right, int query_index) { // left & right are one indexed
        l = left - 1, r = right - 1, q_idx = query_index, block_idx = left / SQRTN;
    }
    bool operator <(const query &y) const {
        if (block_idx != y.block_idx) // if not tie
            return block_idx < y.block_idx;
        return r < y.r;
    }
};

query queries[MAX_Q]; // array of queries.

// You need to update following data structure per problem (e.g. use multiset) ***********
int cnt[10000007]; // where values of input are in [0,1000000] inclusive.
int result = 0; // global variable edited by add & remove methods , used to calculate the answer for each query
//****************************************************************************************

// You need to update add & remove methods per a problem ***
void add(int idx) {
    cnt[input[idx]]++;
    if (cnt[input[idx]] == 3)
        result++;
}

void remove(int idx) {
    cnt[input[idx]]--;
    if (cnt[input[idx]] == 2)
        result--;
}
//**********************************************************

void process(int m) {  // don't change
    sort(queries, queries+m); // sorting queries;

        int curL = 1, curR = 0; // tricky initialization and indexing
        for (int i = 0; i < m; i++) { // iterate over all m queries.
            while (curL < queries[i].l) remove(curL++);
            while (curL > queries[i].l) add(--curL);
            while (curR < queries[i].r) add(++curR);
            while (curR > queries[i].r) remove(curR--);
            q_ans[queries[i].q_idx] = result; // save the answer in the original index
        }
    }


int main() {
    int n, m; // input size,  number of queries
    scanf("%d", &n); // input size;
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);

    scanf("%d", &m); // number of queries
    for (int i = 0; i < m; i++) {
        int left, right;
        scanf("%d%d", &left, &right); // one indexed
        queries[i] = query(left, right, i);
    }
    process(m);

    for (int i = 0; i < m; i++)
        printf("%d\n", q_ans[i]);
}
