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

    string a,b;
    while(cin >> a >> b){
        if(a == "0" && b == "0")
            return;
        if(a.length() < b.length())
            swap(a, b);

        int cnt = 0, carry = 0;
        for (int i = 0; i < (int) b.length(); i++) {
            int ad = (int) a[a.length() - 1 - i] - '0', bd = (int) b[b.length() - 1 - i] - '0';
            if(ad + bd + carry > 9){
                carry = 1;
                cnt++;
            } else
                carry = 0;

        }
        for (int i = (int) b.length(); i < (int) a.length(); i++) {
            int ad = (int) a[a.length() - 1 - i] - '0';
            if(!carry)
                break;
            if(ad + carry > 9)
                cnt++;
            else
                carry = 0;
        }
        if(!cnt)
            cout << "No carry operation." << el;
        else  if(cnt == 1){
            cout << cnt << " carry operation." << el;
        } else 
            cout << cnt << " carry operations." << el; 
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
