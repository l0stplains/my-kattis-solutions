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

bool comp(string a, string b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

void solve() {

    int n;
    while(true){
        cin >> n;
        if(!n)
            break;
        string arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        stable_sort(arr, arr + n, comp);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << el;
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

