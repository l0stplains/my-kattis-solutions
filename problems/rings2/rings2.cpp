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

    int n, m;
    cin >> n >> m;
    string arr[n];
    int map[n][m] = {};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if(arr[i][j] == 'T')
                map[i][j] = -1;
        }
    }
    
    int ring = 0;
    
    for (int t = 1; t <= max(n, m); t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i][j] == 'T' && map[i][j] == -1){
                    int bef = t - 1;
                    if(j != m - 1){
                        if(map[i][j + 1] == bef)
                            bef = t;
                    } else
                        bef = t;
                    if(j){
                        if(map[i][j - 1] == bef)
                            bef = t;
                    } else
                        bef = t;
                    if(i != n - 1){
                        if(map[i + 1][j] == bef)
                            bef = t;
                    } else
                        bef = t;
                    if(i){
                        if(map[i - 1][j] == bef)
                            bef = t;
                    } else
                        bef = t;
                    if(bef == t){
                        map[i][j] = bef;
                        ring = bef;
                    }
                } 
            }
        }
        
    }
    int d  = 2;
    if(ring >= 10){
        d = 3;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j]){
                if(d == 3){
                    if(map[i][j] >= 10)
                        cout << '.';
                    else
                        cout << "..";
                } else
                    cout << '.';
                cout << map[i][j];
            } else{
                for (int k = 0; k < d; k++) {
                    cout << '.';
                }
            }
        }
        cout << el;
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
