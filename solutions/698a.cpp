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
#define mk make_pair

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

    int i, result = INT_MAX, a, v[100];
    f(i, 0, n) {
        cin >> a;
        v[i] = a;
    };

    mii d{ {0, 'r'}, {1, 'c'}, {2, 'g'}, {3, 'a'} };
    // count, curr_i, prev;
    priority_queue<
        pair< int, pair< int, char > >,
        vector< pair< int, pair< int, char > > >,
        greater< pair< int, pair< int, char > > >
    > q;
    set<pii> visited;
    q.push(mk(0, mk(0, 'r')));
    while (!q.empty()) {
        auto [count, p] = q.top(); q.pop();
        auto [curr_i, prev] = p;
        char curr = d[v[curr_i]];
        // printf("count = %d, curr_i = %d, prev = %c, curr = %c\n", count, curr_i, prev, curr);
        if (curr_i == n) {
            result = count;
            break;
        };
        if (curr == 'r' || curr == prev) {
            if (visited.count(mk(curr_i + 1, 'r')) == 0) {
                visited.insert(mk(curr_i + 1, 'r'));
                q.push(mk(count + 1, mk(curr_i + 1, 'r')));
            };
            continue;
        }
        
        if (curr != 'a') {
            if (visited.count(mk(curr_i + 1, curr)) == 0) {
                visited.insert(mk(curr_i + 1, curr));
                q.push(mk(count, mk(curr_i + 1, curr)));
            };
        } else {
            switch (prev) {
                case 'r':
                    if (visited.count(mk(curr_i + 1, 'r')) == 0) {
                        visited.insert(mk(curr_i + 1, 'r'));
                        q.push(mk(count + 1, mk(curr_i + 1, 'r')));
                    };
                    if (visited.count(mk(curr_i + 1, 'c')) == 0) {
                        visited.insert(mk(curr_i + 1, 'c'));
                        q.push(mk(count, mk(curr_i + 1, 'c')));
                    };
                    if (visited.count(mk(curr_i + 1, 'g')) == 0) {
                        visited.insert(mk(curr_i + 1, 'g'));
                        q.push(mk(count, mk(curr_i + 1, 'g')));
                    };
                    break;
                case 'g':
                    if (visited.count(mk(curr_i + 1, 'r')) == 0) {
                        visited.insert(mk(curr_i + 1, 'r'));
                        q.push(mk(count+1, mk(curr_i + 1, 'r')));
                    };
                    if (visited.count(mk(curr_i + 1, 'c')) == 0) {
                        visited.insert(mk(curr_i + 1, 'c'));
                        q.push(mk(count, mk(curr_i + 1, 'c')));
                    };
                    break;
                case 'c':
                    if (visited.count(mk(curr_i + 1, 'r')) == 0) {
                        visited.insert(mk(curr_i + 1, 'r'));
                        q.push(mk(count+1, mk(curr_i + 1, 'r')));
                    };
                    if (visited.count(mk(curr_i + 1, 'g')) == 0) {
                        visited.insert(mk(curr_i + 1, 'g'));
                        q.push(mk(count, mk(curr_i + 1, 'g')));
                    };
                    break;
            };
        };
    };

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    INPUT_OUTPUT()
    solve();
    return 0;
}
