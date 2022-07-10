#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> segtree;
    public:
    SegmentTree(int n)
    {
        segtree.resize(4*n + 1);
    }

    void build(int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            segtree[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        segtree[idx] = min(segtree[2 * idx + 1], segtree[2 * idx + 2]);
        return;
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (high < r || r < low) // non - overlapping
        {
            return INT_MAX;
        }
        else if (low >= l && r >= high)
        {
            return segtree[idx];
        }
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int idx, int low, int high, int ind, int val)
    {
        if (low == high)
        {
            segtree[idx] = val;
        }
        int mid = (low + high) / 2;
        if (ind <= mid)
        {
            update(2 * idx + 1, low, mid, ind, val);
        }
        else
        {
            update(2 * idx + 2, mid + 1, high, ind, val);
        }
        segtree[idx] = min(segtree[2 * idx + 1], segtree[2 * idx + 2]);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree st(n);
    st.build(0, 0, n - 1, arr);
    int queries;
    cin >> queries;
    while (queries--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(0, 0, n - 1, l, r) << "\n";
    }
}
