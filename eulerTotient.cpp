#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;
typedef long double             ld;

typedef pair<ll,ll>             pll;
typedef vector<ll>              vll;
typedef vector<pll>             vpll;
typedef map<ll, ll>             mll;
typedef map<char, ll>           mcl;

#define inf                 1<<30
#define mx9                 1000000007
#define test(t)             int t; cin >> t; while(t--)
#define f(i, a, b)          for(int (i) = (a); (i) < (b); ++(i))
#define all(a)              (a).begin(), (a).end()
#define endl                "\n"
#define ff                  first
#define ss                  second
#define pb                  push_back
#define deb(x)              cout << #x << ": " << x << endl;
#define deb2(x,y)           cout << #x << ": " << x << " ~ " <<  #y << ": " << y << endl;
#define deba(arr)           cout << #arr << " ~ [ "; for(auto n: arr) cout << n << " "; cout << "]" << endl;
#define debap(arr)          cout << #arr << " ~ [ "; for(auto n: arr) cout << n.first << "-" << n.second << " "; cout << "]" << endl;
#define fast                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

ll formula(ll n) {
    if (n == 1) {
        return 1;
    }
    ll curr = n;
    mll mp;
    f(i, 2, sqrt(n) + 2) {
        if(isPrime(curr)) {
            mp[curr] += 1;
            curr = 1;
        }
        while(curr % i == 0) {
            curr /= i;
            mp[i] += 1;
        }
        if(curr == 1) {
            break;
        }
    }
    ld ans = n;
    for(auto it: mp) {
        ld abc = (ld)(1 - (ld)(1.0 / it.ff));
        ans *= (abc);
    }
    return ans;
}

ll eulerTotient(ll n) {
    if(n == 1) {
        return n;
    }
    if(isPrime(n)) {
        return n - 1;
    }
    ll curr = n;
    mll mp;
    f(i, 2, sqrt(n) + 2) {
        if(isPrime(curr)) {
            mp[curr] += 1;
            curr = 1;
        }
        while(curr % i == 0) {
            curr /= i;
            mp[i] += 1;
        }
        if(curr == 1) {
            break;
        }
    }

    ll ans = 1;
    // debap(mp)
    for(auto it: mp) {
        f(i, 0, it.ss)
            ans *= eulerTotient(it.ff);
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    // deb(n)
    cout << formula(n) << endl;
}

int main()
{
    fast;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    test(t)
        solve();
    return 0;
}