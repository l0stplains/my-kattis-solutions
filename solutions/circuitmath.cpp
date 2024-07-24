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
    int arr[n] = {};
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if(temp == "T")
            arr[i] = 1;
    }

    vector<string> ope;
    
    string temp;
    cin.ignore();
    getline(cin, temp);
    char *token = strtok((char*) temp.c_str(), " ");
    while(token){
        ope.pb(token);
        token = strtok(NULL, " ");
    }
    
    stack <int> stak;
    for(auto p : ope){
        char x = p[0];
        if(x >= 'A' && x <= 'Z')
            stak.push(arr[(int) x - 'A']);
        else if(x == '*'){
            int a = stak.top();
            stak.pop();
            int b = stak.top();
            stak.pop();
            stak.push((int) (a && b));
        } else if(x == '+'){
            int a = stak.top();
            stak.pop();
            int b = stak.top();
            stak.pop();
            stak.push((int) (a || b));
        } else {
            int a = stak.top();
            stak.pop();
            stak.push((int) (!a));
        }
    }
    cout << (stak.top() ? "T" : "F"); 

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

