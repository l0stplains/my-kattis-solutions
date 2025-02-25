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
    int maks;
    bool val = true;
    int idx = 1;
    cin >> maks;
    int sum = maks;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x > maks){
            maks = x;
            val = true;
            idx = i + 1;
        }
        else if(x == maks) val = false;
        sum += x;

    }
    if(!val) cout << "no winner" << el;
    else if(2*maks > sum) cout << "majority winner " << idx << el;
    else cout << "minority winner " << idx << el;

    return;
}

int main(){
    fast;
    int TC = 1;   cin >> TC;
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

