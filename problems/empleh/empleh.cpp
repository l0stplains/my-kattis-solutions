#include<bits/stdc++.h>
#include <string.h>
#include <stdio.h>

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
    
    string white, black;
    string dump;
    getline(cin, dump);
    if(dump.length() == 7) white = "";
    else white = dump.substr(7);
    char *token = strtok((char*) white.c_str(), ",");

    vector <string> whitepos;

    while(token != NULL){
        whitepos.pb(token);
        token = strtok(NULL, ",");
    }

    vector <string> blackpos;
    getline(cin, dump);
    if(dump.length() == 7) black = "";
    else black = dump.substr(7);

    token = strtok((char*) black.c_str(), ",");
    while(token != NULL){
        blackpos.pb(token);
        token = strtok(NULL, ",");
    }
    vector <string> ans;

    string bor = "+---+---+---+---+---+---+---+---+";
    string bora = "|...|:::|...|:::|...|:::|...|:::|";
    string borb = "|:::|...|:::|...|:::|...|:::|...|";
    ans.pb(bor);
    for (int i = 0; i < 8; i++) {
        if(i%2)
            ans.pb(borb);
        else
            ans.pb(bora);
        ans.pb(bor);
    }

    for(auto k: whitepos){
        int cd = 0;
        if(k.length() > 2) cd = 1;
        int x = (int) k[cd] - 'a';
        int y = 7 - ((int) k[cd+1] - '1');

        
        for (int i = 1; i < (int) size(ans); i+=2) {
            for (int j = 2; j < (int) size(ans[0]); j+=4) {
                if(y == (i - 1) / 2 && x == (j-2) / 4){
                    if(!cd) ans[i][j] = 'P';
                    else ans[i][j] = k[0];
                }
            }
        }
        
    }

    for(auto k: blackpos){
        int cd = 0;
        if(k.length() > 2) cd = 1;
        int x = (int) k[cd] - 'a';
        int y = 7 - ((int) k[cd+1] - '1');

        
        for (int i = 1; i < (int) size(ans); i+=2) {
            for (int j = 2; j < (int) size(ans[0]); j+=4) {
                if(y == (i - 1) / 2 && x == (j-2) / 4){
                    if(!cd) ans[i][j] = 'p';
                    else ans[i][j] = tolower(k[0]);
                }
            }
        }
        
    }
    for(auto m: ans) cout << m << el;

    
    return;
}

int main(){
    fast;
    int TC = 1; // cin >> TC;
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

