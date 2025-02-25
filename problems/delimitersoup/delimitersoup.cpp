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

    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);

    stack <char> stak;
    bool valid = true;
    for (int i = 0; i < n; i++) {
        if(s[i] == ' ')
            continue;
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            stak.push(s[i]);
        else {
            if(!stak.size()){
                cout << s[i] << " " << i;
                valid = !valid;
                break;
            }
            char top = stak.top();
            if(s[i] == ')'){
                if(top != '('){
                    cout << s[i] << " " << i;
                    valid = !valid;
                    break;
                } else {
                    stak.pop();
                }
            }
            if(s[i] == ']'){
                if(top != '['){
                    cout << s[i] << " " << i;
                    valid = !valid;
                    break;
                } else {
                    stak.pop();
                }
            }
            if(s[i] == '}'){
                if(top != '{'){
                    cout << s[i] << " " << i;
                    valid = !valid;
                    break;
                } else {
                    stak.pop();
                }
            }
        }
    }
    if(valid)
        cout << "ok so far";


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
