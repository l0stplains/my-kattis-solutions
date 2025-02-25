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
    int arr[n] = {};
    int lookup[n] = {};
    
    arr[0] = 0; lookup[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        lookup[i] = i + 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if(arr[j] > arr[j + 1]){ swap(arr[j], arr[j + 1]); swap(lookup[j], lookup[j + 1]);}
        }
    }

    for(auto x:lookup){
        cout << x << " " ;
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

