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

    int ans = 0;

    int n, k;
    cin >> n >> k;
    unordered_map<string, int> arr;
    
    while(k--){
        int a,b;
        string x,y;
        cin >> a >> b >> x >> y;
        if(x == y) {
            if(arr[x] == INF) ans--;
            arr[x] = -INF;}
        if(arr[x] && arr[x] != a && arr[x] != INF){
            if(arr[x] != -INF){
                ans++;
                arr[x] = INF;
            }
        } else if(arr[x] == 0) arr[x] = a;
        if(arr[y] && arr[y] != b && arr[y] != INF){
            if(arr[y] != -INF){
                ans++;
                arr[y] = INF;

            }
        } else if(arr[y] == 0) arr[y] = b;
    }

    int cnt = 0, ncnt = 0;
    for(auto x:arr){
        if(x.second == INF || x.second == -INF) cnt++;
        else ncnt++;
    }
    if(ncnt*2 == n - cnt* 2) ans+= ncnt;
    else if(ncnt == 2 && n - cnt * 2 == 4) ans+=2;
    else if(n - cnt * 2 == 2) ans++;
    cout << ans;

    return;
}

int main(){
    fast;
    int TC = 1;//    cin >> TC;
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

