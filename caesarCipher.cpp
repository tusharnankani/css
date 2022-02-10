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

void solve()
{
    mcl mapChar;
    map<ll, char> cntMap;
    ll cnt = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        mapChar[c] = cnt;
        cntMap[cnt] = c;
        cnt += 1;
    }

    // STARTS
    ll type;
    cin >> type;
    ll toBeEncrypted = 1;
    ll toBeDecrypted = 2;

    if(type == toBeEncrypted) {
        // Encryption
        string input;
        cin >> input;

        ll key;
        cin >> key;

        string decrypted = "";
        ll encryptedLength = input.length();
        f(i, 0, encryptedLength) {
            if(input[i] == ' ')
                continue;
            decrypted += (cntMap[(mapChar[input[i]] + key) % 26]);
        }
        cout << decrypted << endl;
    } 
    else {
        // Decryption
        string input;
        cin >> input;

        ll key;
        cin >> key;

        string encrypted = "";
        ll decryptedLength = input.length();
        f(i, 0, decryptedLength) {
            if(input[i] == ' ')
                continue;
            ll curr = mapChar[input[i]] - key;
            if(curr < 0) {
                curr += 26;
            }
            encrypted += (cntMap[curr]);
        }
        cout << encrypted << endl;
    }
    cout << endl;
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

/*
6

1
abc
5

1
abc
1

1
tushar
8

2
fgh
5

2
bcd
1

2
bcapiz
8
*/

/*
fgh
bcd
bcapiz
abc
abc
tushar
*/