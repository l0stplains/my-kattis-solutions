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

    string s;
    getline(cin, s);

    list<char> str;
    list<char>::iterator cursor = str.begin();
    for (char ch : s) {
        if (ch == '[') {
            cursor = str.begin();
        } else if (ch == ']') {
            cursor = str.end();
        } else if (ch == '<') {
            if (cursor != str.begin()) {
                cursor = str.erase(prev(cursor));
            }
        } else {
            str.insert(cursor, ch);
        }
    }

    for(auto c : str){
        cout << c;
    }

    cout << el;

    return;
}

int main(){
    fast;
    int TC = 1;   cin >> TC;
    cin.ignore();
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

