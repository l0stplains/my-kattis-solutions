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

    string table[9];
    string temp(9, '.');
    for (int i = 0; i < 1; i++) {
        table[i] = temp;
    }
    for (int i = 2; i<7; i++){
        string temp2(2, '.');
        cin >> table[i];
        table[i] = temp2 + table[i] + temp2;
    }
    for (int i = 7; i < 9; i++) {
        table[i] = temp;
    }

    bool yes = true;
    int c = 0;
    for(int i = 2; i<7; i++){
        for(int j = 2; j<7;j++){
            if(table[i][j]!='k')
                continue;
            c++;
            if(yes)
                yes = table[i + 1][j + 2] != 'k';
            if(yes)
                yes = table[i + 1][j - 2] != 'k';
            if(yes)
                yes = table[i + 2][j + 1] != 'k';
            if(yes)
                yes = table[i + 2][j - 1] != 'k';
            if(yes)
                yes = table[i - 1][j + 2] != 'k';
            if(yes)
                yes = table[i - 1][j - 2] != 'k';
            if(yes)
                yes = table[i - 2][j + 1] != 'k';
            if(yes)
                yes = table[i - 2][j - 1] != 'k';
        }
    }
    if(yes && c == 9)
        cout << "valid";
    else 
        cout << "invalid";





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

