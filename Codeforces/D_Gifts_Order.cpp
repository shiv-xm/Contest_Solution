#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  

using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        treeMax.resize(4 * n, 0);
        treeMin.resize(4 * n, 0);
    }
    
    void build(const vector<int>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            treeMax[v] = arr[tl];
            treeMin[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            treeMax[v] = max(treeMax[v * 2], treeMax[v * 2 + 1]);
            treeMin[v] = min(treeMin[v * 2], treeMin[v * 2 + 1]);
        }
    }

    pair<int, int> query(int v, int tl, int tr, int l, int r) const {
        if (l > r) {
            return {INT_MIN, INT_MAX};  
        }
        if (l == tl && r == tr) {
            return {treeMax[v], treeMin[v]};
        }
        int tm = (tl + tr) / 2;
        auto leftQuery = query(v * 2, tl, tm, l, min(r, tm));
        auto rightQuery = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return {max(leftQuery.first, rightQuery.first), min(leftQuery.second, rightQuery.second)};
    }

    void update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr) {
            treeMax[v] = newVal;
            treeMin[v] = newVal;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, newVal);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, newVal);
            }
            treeMax[v] = max(treeMax[v * 2], treeMax[v * 2 + 1]);
            treeMin[v] = min(treeMin[v * 2], treeMin[v * 2 + 1]);
        }
    }

private:
    int n;
    vector<int> treeMax, treeMin;
};

int calculateConvenience(int l, int r, const SegmentTree& segTree, int n) {
    auto res = segTree.query(1, 0, n - 1, l, r);
    int maxVal = res.first;
    int minVal = res.second;
    return maxVal - minVal - (r - l);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        SegmentTree segTree(n);
        segTree.build(a, 1, 0, n - 1);

        int maxConvenience = INT_MIN;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                maxConvenience = max(maxConvenience, calculateConvenience(l, r, segTree, n));
            }
        }

        cout << maxConvenience << endl;

        while (q--) {
            int p, x;
            cin >> p >> x;
            --p;  
            a[p] = x;
            segTree.update(1, 0, n - 1, p, x);

            maxConvenience = INT_MIN;
            for (int l = 0; l < n; ++l) {
                for (int r = l; r < n; ++r) {
                    maxConvenience = max(maxConvenience, calculateConvenience(l, r, segTree, n));
                }
            }
            cout << maxConvenience << endl;
        }
    }
    return 0;
}
