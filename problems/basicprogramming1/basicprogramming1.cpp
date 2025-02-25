
// Accepted (95 points)

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

    int n, t;
    cin >> n >> t;

    int arr[n];
    ll sum = 0;
    ll sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if(arr[i] % 2 == 0) sum2 += arr[i];
        if(t == 6){
            int c = arr[i] % 26 + (int) 'a';
            cout << (char) c;
        }
    }

    if(t == 1) cout << 7;
    else if (t == 2){
        if(arr[0] > arr[1]) cout << "Bigger";
        else if (arr[1] == arr[0]) cout << "Equal";
        else cout << "Smaller";
    } else if (t == 3){
        int arr3[3] = {arr[0], arr[1], arr[2]};
        sort(arr3, arr3 + 3);
        cout << arr3[1];
    } else if(t == 4){
        cout << sum;
    } else if (t == 5){
        cout << sum2;
    } else if(t == 7){
        int idx = 0;
        while(true){
            idx = arr[idx];
            if(idx >= n || idx < 0){cout << "Out"; break;}
            if(idx == n - 1){cout << "Done"; break;}
            if(idx == 0){cout << "Cyclic"; break;}
            
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
