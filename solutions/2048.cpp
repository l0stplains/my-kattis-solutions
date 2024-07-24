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

    vector < vector<int> > arr(6, vector<int> (6, -1));
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> arr[i][j];
        }
    }
    int opt;
    cin >> opt;
    int x, y, mx, my;
    if(opt == 0){x = 1; y = 1; mx = 1; my = 1;}
    if(opt == 1){x = 4; y = 1; mx = -1; my = 1;}
    if(opt == 2){x = 4; y = 4; mx = -1; my = -1;}
    if(opt == 3){x = 1; y = 4; mx = 1; my = -1;}
    

    for (int i = x; i % 5 != 0; i += mx) {
        vector < vector<int> > table(6, vector <int> (6, 0));
        for (int j = y; j % 5 != 0; j += my) {
            int it = i, jt = j;
            if(opt == 1 || opt == 3) swap(it, jt);
            if(arr[it][jt] == 0) continue;
            for (int k = j; k % 5 != 0; k += my * -1) {
                int a = i, b = k, c = i, d = k + my * -1;
                if(opt == 1 || opt == 3){
                    swap(a,b);
                    swap(c, d);
                }

                int &cur = arr[a][b], &bef = arr[c][d];
                if(bef == 0){
                    swap(cur, bef);
                    swap(table[a][b], table[c][d]);
                } else if(bef == cur && !table[a][b] && !table[c][d]){
                    bef += cur;
                    cur = 0;
                    table[a][b] = 0;
                    table[c][d] = 1;
                    
                } else {
                    break;
                }
            }
        }
    }

    for (int i = 1; i < 5; i++) {
       for (int j = 1; j < 5; j++) {
            cout << arr[i][j] << " ";
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

