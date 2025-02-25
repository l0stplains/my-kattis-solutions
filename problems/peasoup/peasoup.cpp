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
    string ans = "";
    while(n--){
        bool s = false,c = false;
        int m;
        cin >> m;
        string name;
        cin.ignore();
        getline(cin, name);
        while(m--){
            string menu;
            getline(cin, menu);
            if(menu == "pea soup") s = true;
            if(menu =="pancakes") c = true;

        }

        if (s && c && ans == "") ans = name;


    }

    if(ans != "") cout << ans;
    else cout << "Anywhere is fine I guess";

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
