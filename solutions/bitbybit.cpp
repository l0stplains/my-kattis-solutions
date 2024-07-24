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
    while(cin >> n){
        if(!n)
            return;
        string ans = string(32, '?');
        for (int i = 0; i < n; i++) {
            string s; int idx;
            cin >> s >> idx;
            idx = 31 - idx;
            if(s == "SET")
                ans[idx] = '1';
            if(s == "CLEAR")
                ans[idx] = '0';
            if(s == "AND"){
                int jdx;
                cin >> jdx;
                jdx = 31 - jdx;
                if(ans[idx] == '0' || ans[jdx] == '0'){
                    ans[idx] = '0';
                } else if(ans[idx] == '?' || ans[jdx] == '?')
                    ans[idx] = '?';
            }
            if(s == "OR"){
                int jdx;
                cin >> jdx;
                jdx = 31 - jdx; 
                if(ans[idx] == '1' || ans[jdx] == '1'){
                    ans[idx] = '1';
                }
                else if(ans[idx] == '0' || ans[jdx] == '0'){
                    if(ans[idx] == '?' || ans[jdx] == '?')
                        ans[idx] = '?';
                    else
                        ans[idx] = '0';

                }
            }
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

