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

    int n;
    string s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int ans = 0;
    
    int narr[n];
    for (int i = 0; i < n; i++) {
        narr[i] = arr[i];
    }

    if(s == "out"){
        int fs,bs;
        fs = n / 2 + n % 2;
        bs = n - fs;

        while(1){
            ans ++;
            int farr[fs];
            int barr[bs];
            for (int i = 0; i < fs; i++) {
                farr[i] = narr[i];
            }
            for (int i = fs; i < n; i++) {
                barr[i - fs] = narr[i];
            }

            for (int i = 0; i < 2*bs; i+=2) {
                narr[i] = farr[(int)i / 2];
                narr[i + 1] = barr[(int)i / 2];
            }
            if(n%2) narr[n - 1] = farr[fs - 1];
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if(narr[i] != arr[i])
                    valid = false;
            }
            if(valid) break;
        }
    }

    if(s == "in"){
        int fs,bs;
        bs = n / 2 + n % 2;
        fs = n - bs;

        while(1){
            ans ++;
            int farr[fs];
            int barr[bs];
            for (int i = 0; i < fs; i++) {
                farr[i] = narr[i];
            }
            for (int i = fs; i < n; i++) {
                barr[i - fs] = narr[i];
            }

            for (int i = 0; i < 2*fs; i+=2) {
                narr[i] = barr[(int)i / 2];
                narr[i + 1] = farr[(int)i / 2];
            }
            if(n%2) narr[n - 1] = barr[bs - 1];
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if(narr[i] != arr[i])
                    valid = false;
            }
            if(valid) break;
        }
    }
    cout << ans;

    return;
}

int main(){
    fast;
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

