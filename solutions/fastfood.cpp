#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 

#define el "\n"
#define F first
#define S second
#define pb push_back
#define fast cin.sync_with_stdio(0); cin.tie(0);

const int INF = numeric_limits<int>::max();

void solve() {

    int n,m;
    cin >> n >> m;
    vector <vector <int> > arr;
    for (int i = 0; i < n; i++) {
        int k;
        vector <int> wk;
        arr.pb(wk);
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            arr[i].pb(x);
        }
        cin >> k;
        arr[i].pb(k);

    }

    int tiket[m];
    for (int i = 0; i < m; i++) {
        cin >> tiket[i];
    }
    int ans = 0;
    for(auto p:arr){
        int mini = INF;
        for (int i = 0; i < p.size() - 1; i++) {
            mini = min(tiket[p[i] - 1] , mini);
        }

        ans += mini * p[p.size() - 1];
    }

    cout << ans << el;

    return;
}

int main(){
    fast;
    int TC = 1;   cin >> TC;
    for(int i = 1; i <= TC; i++){
        solve();
    }
}

/*
       .-"-.            .-"-.            .-"-.           .-"-.
     _/_-.-_\_        _/.-.-.\_        _/.-.-.\_       _/.-.-.\_
    / __} {__ \      /|( o o )|\      ( ( o o ) )     ( ( o o ) )
   / //  "  \  \    | //  "  \  |      |/  "  \|       |/  "  \|
  / / \'---'/ \ \  / / \'---'/ \ \      \'/^\'/         \ .-. /
  \ \_/'"""'\_/ /  \ \_/'"""'\_/ /      /'\ /'\         /'"""'\
   \           /    \           /      /  /|\  \       /       \

*/

