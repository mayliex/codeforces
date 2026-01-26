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
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

template <class T>
void print_a(T &v, int n) { cout << "{"; for (int i=0; i<n; i++) cout << v[i] << ","; cout << "\b}\n"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define N (int) 1e6
#define INF (ll) 4e18

void solve(){
    int i, t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;

        vi robots(n); for (auto& x: robots) cin >> x;
        vi spikes(m); for (auto& x: spikes) cin >> x; 
        sort(spikes.begin(), spikes.end());

        vector<bool> dead(n);
        map<int, vi> death_locations;

        f(i, 0, n) {
            if (spikes[0] < robots[i]) {
                int left_dist = *(lower_bound(spikes.begin(), spikes.end(), robots[i]) - 1) - robots[i];
                death_locations[left_dist].pb(i);
            }
            if (robots[i] < spikes[m-1]) {
                int right_dist = *lower_bound(spikes.begin(), spikes.end(), robots[i]) - robots[i];
                death_locations[right_dist].pb(i);
            }
        }

        //for (auto it: death_locations) {
        //    printf("[%d] ->", it.first);
        //    print_v(it.second);
        //}

        string s;
        cin.ignore();
        getline(cin, s);
        int pos = 0, alive = n;
        f(i, 0, k) {
            pos = s[i] == 'L' ? pos-1 : pos+1;
            for(int robot: death_locations[pos]) {
                if (dead[robot]) continue;
                dead[robot] = true;
                alive--;
            }
            death_locations[pos].clear();
            cout << alive << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    INPUT_OUTPUT()
    solve();
    return 0;
}
