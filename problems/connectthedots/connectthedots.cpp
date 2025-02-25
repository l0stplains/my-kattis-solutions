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
    
    vector < vector<string> > images;
    
    string temp;
    int idx = 0;
    vector <string> temparr;
    while(getline(cin, temp)){
        if(!temp.length()){
            idx++;
            images.pb(temparr);
            temparr.clear();
        }
        else
            temparr.pb(temp);
    }
    images.pb(temparr);


    for(auto im:images){
        vector <pair <int, pair<int, int> > > pos;
        for (int i = 0; i < (int) size(im); i++) {
            for (int j = 0; j < (int) size(im[0]); j++) {
                if(im[i][j] != '.'){
                    if(im[i][j] >= '0' && im[i][j] <= '9'){
                        pos.pb(mp((int)im[i][j] - '0', mp(i, j)));
                    } else if (im[i][j] >= 'a' && im[i][j] <= 'z'){
                        pos.pb(mp((int)im[i][j] - 'a' + 100, mp(i,j)));
                    } else if(im[i][j] >= 'A' && im[i][j] <= 'Z'){
                        pos.pb(mp((int)im[i][j] - 'A' + 1000, mp(i, j)));
                    }
                }
            }
        }
        sort(pos.begin(), pos.end());

        for (int i = 1; i < (int) size(pos); i++) {
            if(pos[i].S.S == pos[i - 1].S.S){
                if(pos[i].S.F > pos[i - 1].S.F){
                    for(int j = 1; j < pos[i].S.F - pos[i - 1].S.F; j++ ){
                        if(im[pos[i - 1].S.F + j][pos[i].S.S] == '.')  im[pos[i - 1].S.F + j][pos[i].S.S] = '|';
                        else if(im[pos[i - 1].S.F + j][pos[i].S.S] == '-') im[pos[i - 1].S.F + j][pos[i].S.S] = '+';
                    }

                } else {
                    for(int j = 1; j < pos[i - 1].S.F - pos[i].S.F; j++ ){
                        if(im[pos[i].S.F + j][pos[i].S.S] == '.')  im[pos[i].S.F + j][pos[i].S.S] = '|';
                        else if(im[pos[i].S.F + j][pos[i].S.S] == '-') im[pos[i].S.F + j][pos[i].S.S] = '+';
                    }

                }
            } else{
                if(pos[i].S.S > pos[i - 1].S.S){
                    for(int j = 1; j < pos[i].S.S - pos[i - 1].S.S; j++ ){
                        if(im[pos[i - 1].S.F][pos[i - 1].S.S + j] == '.')  im[pos[i].S.F][pos[i - 1].S.S + j] = '-';
                        else if(im[pos[i - 1].S.F][pos[i - 1].S.S + j] == '|') im[pos[i].S.F][pos[i - 1].S.S + j] = '+';
                    }

                } else {
                    for(int j = 1; j < pos[i - 1].S.S - pos[i].S.S; j++ ){
                        if(im[pos[i - 1].S.F][pos[i].S.S + j] == '.')  im[pos[i].S.F][pos[i].S.S + j] = '-';
                        else if(im[pos[i - 1].S.F][pos[i].S.S + j] == '|') im[pos[i].S.F][pos[i].S.S + j] = '+';
                    }

                }

            }
        }
        for (int i = 0; i < (int) size(im); i++) {
            for (int j = 0; j < (int) size(im[0]); j++) {
                cout << im[i][j];
            }
            cout << el;
        }
        cout << el;
    }
    
   
    
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

