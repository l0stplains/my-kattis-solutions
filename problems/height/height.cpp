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

void solve(int TT) {

    int c;
    cin >> c;
    int arr[20];
    int ans = 0;
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }

    for (int i = 19; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] > arr[i]){
                for(int k = j + 1; k <=i; k++){
                    swap(arr[k], arr[k - 1]);
                    ans++;
                }
            }
        }
    }
    cout << c  << " "<< ans << el;

    return;
}

int main(){
    fast;
    int TC = 1;   cin >> TC;
    for(int i = 1; i <= TC; i++){
        solve(TC);
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
