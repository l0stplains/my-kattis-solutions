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

void solve() {

    int n;
    while(cin >> n){
        int flag[n - 1] = {};
        int curr;
        cin >> curr;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            int val = abs(x - curr);
            if(val > 0 && val < n)
                flag[val - 1] = 1;
            curr = x;
        }

        bool ans = true;
        for (int i = 0; i < n - 1; i++) {
            if(!flag[i]) 
                ans = false;
        }
        cout << (ans ? "Jolly" : "Not jolly") << el;
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

