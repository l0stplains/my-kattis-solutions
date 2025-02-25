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

    int n;
    string a,b;
    cin >> n >> a >> b;

    int r = 0, s = 0;
    int arr[(int)'Z' - 'A' + 1] = {};
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i])
            r++;
        else
            arr[(int)a[i] - 'A']++;
    }

    for (int i = 0; i < n; i++) {
        if(a[i] != b[i]){
            if(arr[(int) b[i] - 'A']){
                s++;
                arr[(int) b[i] - 'A']--;
            }

        }
    }
    cout << r << " " << s;
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
