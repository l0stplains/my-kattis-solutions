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

    int n; char s;

    scanf("%d %c\n" , &n, &s);

    int dom[] = {11,4,3,20,10,14,0,0};
    int non[] = {11,4,3,2,10,0,0,0};
    char lookup[] = {'A', 'K', 'Q', 'J','T', '9','8','7'};

    int ans = 0;

    n*=4;
    while(n--){
        char x,y;
        scanf("%c%c\n", &x, &y);
        int idx = 0;
        
        for (int i = 0; i < 8; i++) {
            if(x == lookup[i])
                idx = i;
        }
        ans += (y == s ? dom[idx] : non[idx]);
    }

    cout << ans;

    return;
}

int main(){
    // fast;
    int TC = 1;//    cin >> TC;
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

