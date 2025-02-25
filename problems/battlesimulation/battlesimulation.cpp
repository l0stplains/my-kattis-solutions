#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 

#define el "\n"
#define F first
#define S second
#define pb push_back
#define fast cin.sync_with_stdio(0); cin.tie(0);

const int INF = numeric_limits<int>::max();

string cek(char x){
    if(x == 'R') return "S";
    else if(x == 'B') return  "K";
    else if(x == 'L') return "H";
}

void solve() {

    string s, ans = "";
    cin >> s;
    if(s.length() < 3){
        for (int i = 0; i < s.length(); i++) {
            ans += cek(s[i]);
        }
    }
    else {
        int idx = 0;
        for (int i = 0; i < s.length() - 2; i++) {
            if((int) s[i] + s[i + 1] + s[i + 2] == (int) 'R' + 'B' + 'L') {ans += "C"; i += 2;idx+=2;}
            else ans += cek(s[i]);
            idx++;
        }
        for (idx; idx < s.length(); idx++) {
            ans += cek(s[idx]);
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
