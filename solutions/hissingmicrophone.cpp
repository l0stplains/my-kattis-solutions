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
    
    string s;
    cin >> s;
    bool isHiss = false;

    for (int i= 1; i < s.length(); i++) {
        if(s[i] == 's' && s[i - 1] == 's') isHiss = true;
    }

    if(isHiss) cout << "hiss";
    else cout << "no hiss";

    return;
}

int main(){
    fast;
    int TC = 1;   // cin >> TC;
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
