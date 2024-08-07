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
    
        
    int up = INF, low = -1;
    while(true){

        int n;
        cin >> n;
        if(!n) return;


        string s;
        cin.ignore();
        getline(cin , s);
        

        if(s == "too high")
            up = min(up, n);
        else if(s == "too low")
            low = max(low, n);
        else{
            if(n >= up || n <= low)
                cout << "Stan is dishonest" << el;
            else cout << "Stan may be honest" << el;
            up = INF; low = - 1; 
        }
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

