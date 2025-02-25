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
    cin >> n;
    stack<int> a, ax;
    for (int i = 0; i < 2*n; i++) {
        int temp;
        cin >> temp;
        a.push(temp);
    }
    int ans = 0;

    while(a.size()){
        if(!ax.size()){
            ax.push(a.top());
            a.pop();
            ans++;
            continue;
        }
        if(a.top() == ax.top()){
            ans++;
            a.pop();
            ax.pop();
        } else{
            ax.push(a.top());
            a.pop();
            ans++;
        }

    }
    
    if(!ax.size())
        cout << ans;
    else
        cout << "impossible";

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

