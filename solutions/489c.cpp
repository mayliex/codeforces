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
    int m, s;
    cin >> m >> s;

    if (m == 0 || (m > 1 && s == 0)) {
        cout << "-1 -1";
        return;
    };

    char smallest[101];
    memset(smallest, '0', m);
    smallest[m] = '\0';
    int smallest_sum = 0;
    int i = 0;
    int target = s;
    if (s > 0) {
        smallest[0] = '1';
        smallest_sum = 1;
        i = 1;
        s -= 1;
    };
    int j;

    int p = m - 1;
    while (smallest_sum < s && p != -1) {
        smallest_sum -= smallest[p] - '0'; // if we met first '1' and rewrite it
        target += smallest[p] - '0';
        int num = target < 10 ? target : 9;
        smallest_sum += num;
        target -= num;
        smallest[p] = '0' + num;
        p--;
    };

    if (smallest_sum != s) {
        cout << "-1 -1";
        return;
    };

    char highest[101] = {'0'};
    highest[m] = '\0';
    int highest_sum = 0;
    target = s;
    p = 0;
    while(highest_sum != s && p != m) {
        int num = target < 10 ? target : 9;
        highest_sum += num;
        target -= num;
        highest[p] = '0' + num;
        p++;
    };

    f(i, p, m) highest[i] = '0';

    cout << smallest << " " << highest;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    INPUT_OUTPUT()
    solve();
    return 0;
}
