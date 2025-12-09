#include <iostream>
#include <cstdlib>
#include <vector>
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
#define INPUT_OUTPUT()
    do {                                \
    } while (false);
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
#define N (int) 1e9
#define INF (ll) 4e18

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(N);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        if (a == b) continue;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    ll distance[N];
    fill_n(distance, N, INF);

    bool visited[N];
    fill_n(visited, N, false);

    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, 1));
    distance[1] = 0;

    int prev[N];
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (int i=0; i < adj[u].size(); i++) {
            int v = adj[u][i].F, w = adj[u][i].S;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push(make_pair(distance[v] * -1, v));
                prev[v] = u;
            }
        }
    }

    if (distance[n] == INF) {
        cout << -1;
        return;
    }
    
    int curr = n;
    vi answer;
    while (curr != 0) {
        answer.pb(curr);
        curr = prev[curr];
    }
    
    for(ll i=answer.size()-1;i>=0;i--) {
        cout << answer[i] << " ";
    }
}

int main() {
    INPUT_OUTPUT()
    return 0;
}