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

    int idx = 1;
    while(true){
        int a,b;
        cin >> a >> b;
        if(!a && !b)
            break;
        string map[b];
        for (int i = 0; i < b; i++) {
            cin >> map[i];
        }

        int sx, sy;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                if(map[i][j] == '*'){
                    sx = i;
                    sy = j;
                }
            }
        }

        int mvi = 0, mvj = 0;
        if(sx == 0)
            mvi = 1;
        if(sx == b - 1)
            mvi = -1;
        if(sy == 0)
            mvj = 1;
        if(sy == a - 1)
            mvj = -1;

        char curr = '*';
        while(curr != 'x'){
            sx += mvi; sy += mvj;
            curr = map[sx][sy];
            if(curr == '.')
                continue;
            int mul = 1;
            if(curr == '\\')
                mul = -1;
            if(mvi == 1){
                mvi = 0;
                mvj = -1 * mul;
            } else if(mvi == -1){
                mvi = 0;
                mvj = 1 * mul;
            } else if(mvj == 1){
                mvi = -1 * mul;
                mvj = 0;
            } else if(mvj == -1){
                mvi = 1 * mul;
                mvj = 0;
            }


        }

        cout << "HOUSE " << idx++ << el;
        map[sx][sy] = '&';

        for(auto line:map){
            cout << line << el;
        }

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
