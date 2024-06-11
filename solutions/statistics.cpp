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
  
    int n, j = 1;
    while(scanf("%d", &n) != EOF){
        int temp = 0, mini, maks;
        cin >> temp;
        mini = temp; maks = temp;
        for(int i = 1; i<n; i++){
            cin >> temp;
            mini = min(mini, temp);
            maks = max(maks, temp);
        }
        cout << "Case " << j << ": " << mini << " "<< maks << " " << maks - mini << el;
        j++;
    }

    return;
}

int main(){
    // fast;
    int TC = 1;//   cin >> TC;
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
