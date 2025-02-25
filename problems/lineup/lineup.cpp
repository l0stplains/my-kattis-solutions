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
    
    int n;
    cin >> n;
    bool isIncrease = true, isDecrease = true;

    string s, temp;
    cin >> temp;
    for (int i = 1; i < n; i++) {
        cin >> s;
        if(s <= temp){isIncrease = false;}
        if(s >= temp){isDecrease = false;}
        temp = s;
    }
    if(isIncrease) cout << "INCREASING";
    if(isDecrease) cout << "DECREASING";
    if(!isIncrease && !isDecrease) cout << "NEITHER";
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

