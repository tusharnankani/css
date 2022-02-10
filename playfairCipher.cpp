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
    string input;
    cin >> input;

    string key;
    cin >> key;

    // MATRIX 
    char matrix[5][5];
    vector<char> matrixVector;
 
    mcl mapCharCnt;
    f(i, 0, key.length()) {
        char currChar = key[i];
        if(currChar == 'j') {
            currChar = 'i';
        }

        if (!mapCharCnt[currChar]) {
            matrixVector.pb(currChar);
            mapCharCnt[currChar] += 1;
        }
    }   

    for(char c = 'a'; c <= 'z'; c++) {
        if(mapCharCnt[c] || c == 'j') {
            continue;
        }

        matrixVector.pb(c);
        mapCharCnt[c] += 1;
    }

    // deba(matrixVector)

    map<char, pair<ll, ll>> coordinates;

    ll k = 0;
    // cout << "~ matrix ~" << endl;
    f(i, 0, 5) {
        f(j, 0, 5) {
            matrix[i][j] = matrixVector[k++];
            coordinates[matrix[i][j]] = {i, j};
            // cout << matrix[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;

    // ENCRYPTION

    string bogusChar = "x";
    ll inputLen = input.length();
    f(i, 0, input.length() - 1) {
        string curr = input;
        if(input[i] == input[i + 1]) {
            input = curr.substr(0, i + 1);
            input += bogusChar;
            input += curr.substr(i + 1, inputLen);
            inputLen += 1;
        }
    }
    

    // Length check

    if(input.length() % 2) {
        input += bogusChar;
    }

    deb(input)
    
    string encrypted = "";

    f(i, 0, input.length() - 1) {
        ll firstChar = input[i];
        ll secChar = input[i + 1];

        ll firstCharX = coordinates[firstChar].ff;
        ll firstCharY = coordinates[firstChar].ss;

        ll secCharX = coordinates[secChar].ff;
        ll secCharY = coordinates[secChar].ss;

        // deb2(firstCharX, firstCharY)
        // deb2(secCharX, secCharY)

        if(firstCharX == secCharX) {
            ll first = firstCharY + 1;
            ll sec = secCharY + 1;
            first %= 5;
            sec %= 5;
            encrypted += matrix[firstCharX][first];
            encrypted += matrix[secCharX][sec];
        }
        else if(firstCharY == secCharY) {
            ll first = firstCharX + 1;
            ll sec = secCharX + 1;
            first %= 5;
            sec %= 5;
            encrypted += matrix[first][firstCharY];
            encrypted += matrix[sec][secCharY];
        } 
        else {
            encrypted += matrix[firstCharX][secCharY];
            encrypted += matrix[secCharX][firstCharY];
        }
        i += 1;
    }
    cout << "encrypted: " << encrypted << endl << endl;
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

3
abc
college
hammer
college
tushar
nankani

*/