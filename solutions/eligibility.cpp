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
  
    string name;
    int d,m,y, t,b,th, sem;

    cin >> name;
    if (scanf("%d/%d/%d %d/%d/%d %d", &y,&m,&d, &th,&b,&t,&sem)) name = name;

    string status = "eligible";

    if(y < 2010 && th < 1991) {
        if (sem >= 41) status = "ineligible";
        else status = "coach petitions";
    }

    cout << name << " " << status << el;


    return;
}

int main(){
    // fast;
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

