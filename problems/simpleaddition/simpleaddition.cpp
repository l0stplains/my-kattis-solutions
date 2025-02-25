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
    cin >> a >> b;
    if(a.length() < b.length())
        swap(a, b);
    int carry = 0;
    for (int i = 0; i < (int) b.length(); i++) {
        int ad = a[a.length() - 1 - i] - '0', bd = b[b.length() - 1 - i] - '0';
        int sum = carry + ad + bd;
        if(sum > 9){
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;

        a[a.length() - 1 - i] = (char)((int) sum + '0');
    }

    for (int i = b.length(); i < (int) a.length(); i++){
        if(!carry)
            break;
        int sum = carry + (int) a[a.length() - 1 - i] - '0';
        if(sum > 9){
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;

        a[a.length() - 1 - i] = (char)((int) sum + '0');
    }
    string ans = "";
    if(carry)
        ans += '1';

    ans += a;
    cout << ans;

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

