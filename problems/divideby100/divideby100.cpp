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

    string s, t;
    cin >> s >> t;
    string ans = "";
    if(t == "1"){
        cout << s;
        return;
    }
    int l = 0;
    bool found = false;
    string x (max(0, (int) (t.length() - s.length())), '0');
    x += s;
    for (int i = (int) x.length() - 1; i >= 0; i--) {
        if(x[i] != '0' || found){
            found = true;
            ans+=x[i];
        }
        l++;
        if(l == (int) t.length() - 1){
            if(found)
                ans += '.';
            found = true;
        }
    }
    
    for (int i = (int) ans.length() - 1; i >= 0 ; i--) {
        cout << ans[i];
    }
    return;
}

int main(){
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
