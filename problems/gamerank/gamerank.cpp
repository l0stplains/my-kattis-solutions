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
    
        
    string s;
    cin >> s;
    
    int rank = 25, streak = 0, star = 0;

    for (int i = 0; i < s.length(); i++) {
        if(rank == 0) break;
        if(s[i] == 'W'){
            int minstar, plus = 1;
            streak++;
            if(rank > 20) minstar = 2;
            else if (rank > 15) minstar = 3;
            else if(rank > 10) minstar = 4;
            else if(rank > 0) minstar = 5;
            if(streak >= 3 && rank > 5) 
                plus++;
            if(star + plus > minstar){
                star = star + plus - minstar;
                rank--;
            } else {
                star += plus;
            }
        } else {
            streak = 0;
            if(star == 0){
                if(rank < 20){
                    rank++;
                    if(rank > 15) star = 2;
                    else if(rank > 10) star = 3;
                    else if(rank > 0) star = 4;
                }
            } else if (rank <= 20){
                star--;
            }
        }
    }

    if(rank) cout << rank;
    else cout << "Legend";
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
