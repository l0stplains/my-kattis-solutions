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

    int aa,ab,ba,bb;

    while(true){
        cin >> aa >> ab >> ba >> bb;
        if (!aa && !ab && !ba && !bb) return;
        

        string ans = "";
        if (aa + ab == 3){
            if(ba + bb == 3) ans = "Tie.";
            else ans = "Player 1 wins.";
        }
        else if (ba + bb == 3) ans = "Player 2 wins.";
        else if (aa == ab){
            if (bb == ba){
                if(ab > ba) ans = "Player 1 wins.";
                else if (ab < ba) ans = "Player 2 wins.";
                else ans = "Tie.";
            }
            else ans = "Player 1 wins.";
        } else if (ba == bb) ans = "Player 2 wins.";
        else {
            int c = max(ab, aa) * 10 + min(ab, aa);
            int d = max(ba, bb) * 10 + min(bb, ba);
            if(c > d) ans = "Player 1 wins.";
            else if (c < d) ans = "Player 2 wins.";
            else ans = "Tie.";
        }
        cout << ans << el;
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
