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
        int table1 = 0, table2 = 0;
        for (int i = 0; i < n; i++) {
            string s; int x;
            cin >> s >> x;
            if(s == "DROP"){
                cout << s << " 1 "<< x << el;
                table1 += x;
            }
            else{
                if(x > table2){
                    if(table2)
                        cout << s << " 2 " <<  table2 << el;
                    x -= table2;
                    cout << "MOVE 1->2 " << table1 << el;
                    table2 = table1;
                    table1 = 0;
                } 
                cout << s << " 2 " << x << el;
                table2 -= x;
                
            }
        }
        cout << el;
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
