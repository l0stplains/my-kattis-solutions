#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define el "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fast cin.sync_with_stdio(0); cin.tie(0);

bool comp(pair<string, string> a, pair<string, string> b){
    if (a.S == b.S) {
        return a.F < b.F;
    }
    return a.S > b.S;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<string, string>> arr(n);
    for (int i = 0; i < n; i++) {
        string name, rank, temp;
        cin >> name >> rank >> temp;
        name.pop_back();  // remove colon from name
        stringstream ss(rank);
        string token;
        vector<string> levels;
        while (getline(ss, token, '-')) {
            levels.pb(token);
        }

        string rankact = "";
        for (auto x : levels) {
            if (x == "upper")
                rankact += '3';
            if (x == "middle")
                rankact += '2';
            if (x == "lower")
                rankact += '1';
        }
        reverse(rankact.begin(), rankact.end());
        arr[i] = mp(name, rankact);
    }

    // Normalize lengths by padding with '2's (middle)
    int max_length = 0;
    for (auto& p : arr) {
        max_length = max(max_length, (int)p.S.length());
    }
    for (auto& p : arr) {
        while (p.S.length() < max_length) {
            p.S += '2';
        }
    }

    sort(arr.begin(), arr.end(), comp);

    for (auto x : arr) {
        cout << x.F << el;
    }
    cout << string(30, '=') << el;
}

int main() {
    fast;
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        solve();
    }
}


