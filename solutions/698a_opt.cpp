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
    int n;
    cin >> n;

    int v[101], i;
    f(i, 0, n) {
        cin >> v[i];
    }

    int prev[3], curr[3], j;
    f(i, 0, 3)
        curr[i] = INT_MAX;

    prev[0] = prev[1] = prev[2] = 0;
    f(i, 1, n+1) {
        // rest
        curr[0] = min({prev[0], prev[1], prev[2]}) + 1;
        
        // contest
        if (v[i-1] & 1)
            curr[1] = min(prev[0], prev[2]);
        else
            curr[1] = INT_MAX;

        // gym
        if (v[i-1] & 2)
            curr[2] = min(prev[0], prev[1]);
        else
            curr[2] = INT_MAX;

        prev[0] = curr[0];
        prev[1] = curr[1];
        prev[2] = curr[2];
    };

    cout << min({curr[0], curr[1], curr[2]});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    INPUT_OUTPUT()
    solve();
    return 0;
}
