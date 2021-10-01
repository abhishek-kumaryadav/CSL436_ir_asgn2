#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define all(c) c.begin(), c.end()
#define sz(c) c.size()
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())

class KmpClass
{
public:
    string pattern;
    string text;
    vector<int> lps;
    KmpClass(string t = "helloworld", string p = "world")
    {
        text = t;
        pattern = p;
        createLps();
        // printLps();
    }
    vector<int> runSearch()
    {
        int i = 0; // for text
        int j = 0; // for pattern
        int sz_te = text.size();
        int sz_p = pattern.size();
        vector<int> index;
        while (i < sz_te)
        {
            if (pattern[j] == text[i])
            {
                i++;
                j++;
            }
            if (j == sz_p)
            {
                index.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < sz_te && pattern[j] != text[i])
            {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return index;
    }
    void createLps()
    {
        lps = vector(pattern.size(), 0);
        int i = 1;
        int previous_lps = 0;
        int sz = pattern.size();
        while (i < sz)
        {
            if (pattern[i] == pattern[previous_lps])
            {
                previous_lps += 1;
                lps[i] = previous_lps;
            }
            else
            {
                if (previous_lps != 0)

                {
                    previous_lps = lps[previous_lps - 1];
                    i -= 1;
                }
                else
                    lps[i] = 0;
            }
            i += 1;
        }
        // printLps();
        // lps = {1, 2, 3};
        // printLps();
    }
    void printLps()
    {
        forn(i, lps.size())
                cout
            << lps[i] << " ";
    }
    void takeInputs(string t = "-1", string p = "-1")
    {
        text = t;
        pattern = p;
        while (!checkGoodInputs(text, pattern))
        {
            cout << "All inputs should be A-Z or a-z" << endl;
            cout << "Enter the input text: ";
            cin >> text;
            cout << "Enter the pattern to be searched: ";
            cin >> pattern;
        }
        createLps();
    }
    bool checkGoodInputs(string t, string p)
    {
        if (t == "-1" || p == "-1")
            return false;
        if (t.size() < p.size())
            return false;
        return checkGoodInput(t) && checkGoodInput(p);
    }
    bool checkGoodInput(string x)
    {
        forn(i, x.size())
        {
            if ((int)x[i] < 65 || (int)x[i] > 122 || ((int)x[i] > 90 && (int)x[i] < 97))
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    // fast_cin();
    // cout << argc;
    KmpClass kmpObject;
    if (argc == 1)
    {
        kmpObject.takeInputs();
        // kmpObject.printLps();
    }
    else if (argc == 3)
    {
        kmpObject.takeInputs(argv[1], argv[2]);
        // kmpObject.printLps();
    }
    else
    {
        cout << "Input example:" << endl;
        cout << "./a.out"
             << "    or" << endl;
        cout << "./a.out text pattern" << endl;
        exit(0);
    }
    vector<int> result = kmpObject.runSearch();
    cout << "Number of patterns found: " << result.size() << endl;
    if (result.size() > 0)
    {
        cout << "Pattern found at: ";
        for (auto i : result)
        {
            cout << i << " ";
        }
    }
    // KmpClass kmpObject("AAAAABAAABA", "AABAACAABAA");
    // kmpObject.createLps();
    return 0;
}