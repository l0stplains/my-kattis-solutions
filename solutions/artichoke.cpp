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

    int p,a,b,c,d, n;
    cin >> p >> a >> b >> c >> d >> n;
    
    double maksi, maksid = 0;

    maksi = p * ((double) sin(a * 1 + b) + cos(c * 1 + d) + 2);
    for(int i=2; i<=n;i++){
        double temp = p * ((double) sin(a * i + b) + cos(c * i + d) + 2);
        
        if(temp < maksi) maksid = max(maksid, maksi - temp);
        
        maksi = max(maksi, temp);
    }

    cout << fixed << setprecision(9)<< maksid;

        

    return;
}

int main(){
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
