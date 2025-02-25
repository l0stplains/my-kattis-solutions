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

    string ope;
    cin >> ope;
    int n;
    cin >> n;
    string temp;
    cin >> temp;

    deque<int> arr;

    string tempe = "";
    for (int i = 1; i < (int) temp.length(); i++) {
        if(temp[i] >= '0' && temp[i] <= '9')
            tempe+=temp[i];
        else if(tempe.length()){
            arr.push_back(stoi(tempe));
            tempe = "";
        }
    }

    bool r = false;
    for (int i = 0; i < (int) ope.length(); i++) {
        if(ope[i] == 'R')
            r = !r;
        if(ope[i] == 'D'){
            if(!arr.size()){
                cout << "error" << el;
                return;
            }
            if(r)
                arr.pop_back();
            else
                arr.pop_front();
        }
    }
    cout << '[';
    for (int i = 0; i < (int) arr.size(); i++) {
        cout << (r ? arr[(int) arr.size()  - 1 - i] : arr[i]);
        if(i != (int) arr.size() - 1)
            cout << ',';
    }
    cout << ']';
    cout << el;

    
    return;
}

int main(){
    fast;
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

