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
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = 0;
    int cur = -1, mini = INF;

    for (int i = 0; i < n; i++) {
        if(cur == -1){
            mini = arr[i];
            cur = arr[i];
        } else {
            if(arr[i] >= cur){
                ans = max(cur - mini, ans);
                cur = arr[i];
                mini = arr[i];
            } else
                mini = min(mini, arr[i]);
        }
    }

    cur = -1; mini = INF;

    for(int i = n - 1; i >= 0; i--) {
        if(cur == -1){
            mini = arr[i];
            cur = arr[i];
        } else {
            if(arr[i] >= cur){
                ans = max(cur - mini, ans);
                cur = arr[i];
                mini = arr[i];
            } else
                mini = min(mini, arr[i]);
        }
    }

    cout << ans;


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

