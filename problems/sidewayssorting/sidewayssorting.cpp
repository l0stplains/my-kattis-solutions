#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 

#define el "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fast cin.sync_with_stdio(0); cin.tie(0);

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int mod = 99824435;

void solve() {

    int n,m;
    while(true){
        cin >> n >> m;
        if(!n && !m)
            break;

        string arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m - 1 - i; j++) {
                for (int k = 0; k < n; k++) {
                    int val1, val2;
                    if(isupper(arr[k][j]))
                        val1 = arr[k][j] - 'A';
                    else
                        val1 = arr[k][j] - 'a';
                    if(isupper(arr[k][j + 1]))
                        val2 = arr[k][j + 1] - 'A';
                    else
                        val2 = arr[k][j + 1] - 'a';

                    if(val1 > val2){
                        for (int l = 0; l < n; l++) {
                            swap(arr[l][j], arr[l][j + 1]);
                        }
                        break;
                    } else if(val1 < val2)
                        break;
                    else
                        continue;
                }

            }
        }

        for(auto s: arr){
            cout << s << el;
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
