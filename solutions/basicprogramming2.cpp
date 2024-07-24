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

    int n,t;
    cin >>n >> t;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    if(t == 1){
        bool yes = false;
        for (int i = 0; i < n; i++) {
           for (int j = i + 1; j < n; j++) {
                if(arr[i] + arr[j] == 7777)
                    yes = true;
                else if(arr[i] + arr[j] > 7777)
                    break;
           }
           if(yes)
               break;
        }
        if(yes)
            cout << "Yes";
        else
            cout << "No";
    }
    if(t == 2){
        bool yes = true;
        for (int i = 0; i < n - 1; i++) {
            if(arr[i] == arr[i + 1])
                yes = false;
        }
        if(yes)
            cout << "Unique";
        else
            cout << "Contains duplicate";

    }
    if(t == 3){
        int ans = -1;
        for(int i = n / 2; i < n; i++){
            if(arr[i] == arr[i - n / 2])
                ans = arr[i];
        }
        cout << ans;

    }
    if(t == 4){
        if(n % 2 == 0)
            cout << arr[n / 2 - 1] << " " << arr[n / 2];
        else
            cout << arr[n / 2];
    }
    if(t == 5){
        for (int i = 0; i < n; i++) {
            if(arr[i] >= 100 && arr[i] <= 999)
                cout << arr[i] << " ";
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

