#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 

#define el "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fast cin.sync_with_stdio(0); cin.tie(0);

const ll INF = numeric_limits<int>::max();
const ll MOD = 1e9 + 7;
const int mod = 99824435;

void solve() {

    string temp;
    int maks = -1;
    vector<string> arr;
    while(getline(cin, temp)){
        if(!temp.length()){
            sort(arr.begin(), arr.end());
            for(auto s : arr){
                cout << string(maks - (int) s.length(), ' ');
                reverse(s.begin(), s.end());
                cout << s << el;
            }
            maks = -1;
            cout << el;
            arr.clear();
            continue;
        }
        maks = max(maks, (int) temp.length());
        reverse(temp.begin(), temp.end());
        arr.pb(temp);
        
    }


    sort(arr.begin(), arr.end());
    for(auto s : arr){
        cout << string(maks - (int) s.length(), ' ');
        reverse(s.begin(), s.end());
        cout << s << el;
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

