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

    int n;
    cin >> n;
    vector<int> arr;
    
    int maks = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x > maks){
            arr.pb(x);
            maks = x;
        }
    }

    cout << arr.size() << el;

    for(auto x:arr){
        cout << x << " " ;
    }

    return;
}

int main(){
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

