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
    

    string s, ans;
    cin >> s;
    vector <pair<int, string> > white;
    vector <pair<int, string> > black;
    for (int i = 0; i < 8; i++) {
        cin >> s;
        for (int j = 2; j < s.length(); j+=4) {
            char c = s[j];
            int val = 0;
            int mul = 1;
            if(c == 'k' || c == 'K') val = 6000;
            else if(c == 'q' || c == 'Q') val = 5000;
            else if(c == 'r' || c == 'R') val = 4000;
            else if(c == 'b' || c == 'B') val = 3000;
            else if(c == 'n' || c == 'N') val = 2000;
            else if(c == 'p' || c == 'P') val = 1000;
            else continue;
            if( (int) c > (int) 'a') mul = -1;
            int v = val + 100 * i * mul - j;
            ans = "";
            if(val != 1000) ans += toupper(c);
            ans += (char) ((int) 'a' + (j-2) / 4);
            ans += (char) ((int) '1' + 7 - i);

            if(mul > 0) white.pb(mp(v, ans));
            else black.pb(mp(v, ans));

        }
        cin >> s;
    }
    sort(white.rbegin(), white.rend());
    sort(black.rbegin(), black.rend());
    int temp = 0;
    cout << "White: ";
    for(auto p:white){ 
        cout << p.S;
        if(temp != (int)size(white) - 1) cout << ',';
        temp++;
    }

    temp = 0;
    cout << el << "Black: ";
    for(auto p:black){
        cout << p.S;
        if(temp != (int)size(black) - 1) cout << ',';
        temp++;
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

