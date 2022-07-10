#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef tree<pair<long long,long long>, null_type, less<pair<long long,long long>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define ll long long
#define mod 1000000007
#define inf 1000000000000000005
#define vi vector<int>
#define vll vector<long long>
#define vpll vector<pair<ll,ll>>
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pb push_back
#define pii pair<int, int>

int num_bits(ll n) {int max_bits = 0; for(int i=0;i<64;i++) {if((n & (1ll<<i))) max_bits = i;} return max_bits + 1;}


vector<int> dx{0, 0, -1, 1};
vector<int> dy{-1, 1, 0, 0};
// left,right,up,down

ll binpow(ll a, ll n)           // binary exponentiation
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        ll value = binpow(a, n / 2);
        return (value * value) ;
    }
    else
    {
        ll value = binpow(a, n / 2);
        return (((value * value)) * a);
    }
}


ll ceiling(const ll &a, const ll &b)
{
    if(a%b == 0)
        return a/b;
    return a/b +1;
}


int oneBits(ll n) {
    int cnt = 0;
    while(n)
    {
        cnt++;
        n &= (n-1);
    }
    return cnt;
}

bool check(ll n)
{
    vector<int> ternarybits(40,0);
    int cnt = 0;
    while(n){
        if(n % 3 == 0)
        {
            cnt++;
            n /= 3;
        }
        else if(n % 3 == 2)
        {
            return false;
        }
        else{
            ternarybits[cnt]++;
            if(ternarybits[cnt] > 1)
            {
                return false;
            }
//            cnt = 0;
            n--;
        }
    }
    return true;
}

int postorder(int node,vector<vector<int>> adjlist,map<int,int> &cnt,int parent)
{
    if(adjlist[node].size() == 1 && node != 1)
    {
        return cnt[node] = 0;
    }
    else{
        int calc = 0;
        for(auto i:adjlist[node])
        {
            if(i == parent)
            {
                continue;
            }
            else{
                calc += 1 + postorder(i,adjlist,cnt,node);
            }
        }
        return cnt[node] = calc;
    }
}

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (auto &i: arr) {
        cin >> i;
    }
    sort(all(arr));
    reverse(all(arr));
    vector<long long> attackprefix(n, 0), defencesuffix(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            attackprefix[i] = arr[0];
        } else {
            attackprefix[i] = attackprefix[i - 1] + arr[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            defencesuffix[i] = 1000 - arr[i];
        } else {
            defencesuffix[i] = defencesuffix[i + 1] + 1000 - arr[i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        ans = max(ans, attackprefix[i] * defencesuffix[i+1]);
    }
    cout<<ans<<"\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

