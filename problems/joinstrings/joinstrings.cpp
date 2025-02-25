#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 

#define el "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fast cin.sync_with_stdio(0); cin.tie(0);

const ll INF = numeric_limits<int>::max();
const ll MOD = 1e9 + 7;
const int mod = 99824435;

void solve() {

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<list<int> > ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].pb(i);
    }
    int last = 0;
    for (int i = 0; i < n - 1; i++) {
        int a ,b;
        cin >> a >> b;
        ans[a - 1].splice(ans[a - 1].end(), ans[b - 1]);
        list<int>().swap(ans[b - 1]);
        last = a - 1;
    }
    for(auto idx : ans[last]){
        cout << arr[idx];
    }



    return;
}

int main(){
    fast;
    int TC = 1;  // cin >> TC;
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


