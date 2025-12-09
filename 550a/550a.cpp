#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <functional>
#include <limits>

using namespace std;

#ifndef ONLINE_JUDGE
#define INPUT_OUTPUT()                  \
    freopen("input.txt", "r", stdin);   \
    freopen("output.txt", "w", stdout); 
#else
#define INPUT_OUTPUT()                  \
    while (false) {};
#endif

#define FAST_EXECUTION
#ifdef FAST_EXECUTION
  #pragma GCC optimize("O3")
#endif

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define sc set<char>

#define F first
#define S second

/* FUNCTIONS */
#define f(i,s,e) for(auto i=s;i<e;i++)
#define cf(i,s,e) for(auto i=s;i<=e;i++)
#define rf(i,e,s) for(auto i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define N (int) 1e6
#define INF (ll) 4e18

void solve() {
    string s;
    getline(cin, s);
    int i = 0;
    int ab = -1, ba = -1;

    // find AB -> BA
    f(i, 1, s.size()) {
        if (s[i - 1] == 'A' && s[i] == 'B' && ab == -1) {
            ab = i;
        }
        if (s[i - 1] == 'B' && s[i] == 'A') {
            ba = i;
        }
        if (ba != -1 && ab != -1 && ba - ab > 1) {
            cout << "YES";
            return;
        }
    }

    ba = -1; ab = -1;

    // find BA -> AB
    f(i, 1, s.size()) {
        if (s[i - 1] == 'B' && s[i] == 'A' && ba == -1) {
            ba = i;
        }
        if (s[i - 1] == 'A' && s[i] == 'B') {
            ab = i;
        }
        if (ba != -1 && ab != -1 && ab - ba > 1) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    INPUT_OUTPUT()
    solve();
    return 0;
}