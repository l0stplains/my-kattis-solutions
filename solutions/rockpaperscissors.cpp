#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 

#define el "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fast cin.sync_with_stdio(0); cin.tie(0);

const int INF = numeric_limits<int>::max();

int check(string a, string b){
    if(a == b)
        return  0;
    if(a == "rock"){
        if(b == "scissors")
            return 1;
        if(b == "paper")
            return -1;
    } 
    if(a == "paper"){
        if(b == "scissors")
            return -1;
        if(b == "rock")
            return 1;
    }
    if(a == "scissors"){
        if(b == "paper")
            return 1;
        if(b == "rock"){
            return -1;
        }
    }
}

void solve() {
    
    while(true){
        int n;
        cin >> n;
        if(!n) return;

        int k;
        cin >> k;

        int win[n+1] = {}, lose[n+1] = {};
        for (int i = 0; i < n*k*(n-1)/2; i++) {
            int a,b;
            string sa, sb;
            cin >> a >> sa >> b >> sb;
            int res = check(sa, sb);
            if(res == 1){
                win[a]++;
                lose[b]++;
            } else if(res == -1){
                lose[a]++;
                win[b]++;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            if(!win[i] && !lose[i]) cout << "-" << el;
            else cout << fixed << setprecision(3) << (double) win[i] / ((double) win[i] + lose[i]) << el;
        }
        cout << el;
    }
        
    return;
}

int main(){
    fast;
    int TC = 1; // cin >> TC;
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

