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

pair<int, int> diag(int x1, int y1, int x2, int y2){
    bool valid = false;
    int ax,by;
    int tx = x1,ty = y1;
    while(!valid && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        if(tx == x2 && ty == y2){valid = true;}
        tx++;
        ty++;
    }

    tx = x1,ty = y1;
    while(!valid && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        if(tx == x2 && ty == y2) valid = true;
        tx--;
        ty++;
    }

    tx = x1,ty = y1;
    while(!valid && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        if(tx == x2 && ty == y2) valid = true;
        tx--;
        ty--;
    }

    tx = x1,ty = y1;
    while(!valid && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        if(tx == x2 && ty == y2) valid = true;
        tx++;
        ty--;
    }
    
    if(valid)
        return mp(x1,y1);
    return mp(0,0);

}


void solve() {
    

    char a; int b;
    int x1,y1,x2,y2;

    cin >> a >> b;
    x1 = a - 'A' + 1;
    y1 = b;
    cin >> a >> b;
    x2 = a - 'A' + 1;
    y2 = b;


    vector <pair<int,int> > ans;
    ans.pb(mp(x1, y1));
    bool yes = false;
    int tx = x1,ty = y1;
    while(!yes && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        pair <int, int> pos = diag(tx,ty,x2,y2);
        if(pos == mp(0,0)) {
            tx--;
            ty++;
            continue;
        }   
        if(pos == mp(x1,y1) && pos == mp(x2, y2)) yes = true;
        else if(pos == mp(x1,y1)) {ans.pb(mp(x2,y2)); yes = true;}
        else {ans.pb(pos); ans.pb(mp(x2,y2)); yes = true; }
    }

    tx = x1,ty = y1;
    while(!yes && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        pair <int, int> pos = diag(tx,ty,x2,y2);
        if(pos == mp(0,0)) {
            tx++;
            ty++;
            continue;
        }   
        if(pos == mp(x1,y1) && pos == mp(x2, y2)) yes = true;
        else if(pos == mp(x1,y1)) {ans.pb(mp(x2,y2)); yes = true;}
        else {ans.pb(pos); ans.pb(mp(x2,y2)); yes = true;}
    }

    tx = x1,ty = y1;
    while(!yes && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        pair <int, int> pos = diag(tx,ty,x2,y2);
        
        if(pos == mp(0,0)) {
            tx--;
            ty--;
            continue;
        }   
        if(pos == mp(x1,y1) && pos == mp(x2, y2)) yes = true;
        else if(pos == mp(x1,y1)) {ans.pb(mp(x2,y2)); yes = true;}
        else {ans.pb(pos); ans.pb(mp(x2,y2)); yes = true;}
    }

    tx = x1,ty = y1;
    while(!yes && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
        pair <int, int> pos = diag(tx,ty,x2,y2);
        
        if(pos == mp(0,0)) {
            tx++;
            ty--;
            continue;
        }   
        if(pos == mp(x1,y1) && pos == mp(x2, y2)) yes = true;
        else if(pos == mp(x1,y1)) {ans.pb(mp(x2,y2)); yes = true;}
        else {ans.pb(pos); ans.pb(mp(x2,y2)); yes = true;}
    }
    if(!yes){ cout << "Impossible" << el; return;}
    cout << (int) size(ans) - 1; 
    for(auto p: ans){
        cout << " " << (char) ('A' + p.F - 1) << " " << p.S; 
    }
    cout << el;


    return;
}

int main(){
    fast;
    int TC = 1;  cin >> TC;
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

