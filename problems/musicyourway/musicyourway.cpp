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

map<string, int> attribute;
string attr;

bool comp(vector<string> a, vector<string> b){
    int idx = attribute[attr];
    return a[idx] < b[idx];
}

void solve() {

    string att;
    getline(cin, att);

    char *token = strtok((char*) att.c_str(), " ");
    vector<string> temparr;
    while(token != NULL){
        temparr.pb(token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < (int) temparr.size(); i++) {
        attribute[temparr[i]] = i;
    }

    int n;
    cin >> n;
    vector<vector< string> > arr(n);
    
    for (int i = 0; i < n; i++) {
        vector<string> temp;
        for (int j = 0; j < (int) temparr.size(); j++) {
            string s;
            cin >> s;
            temp.pb(s);
        }
        arr[i] = temp;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> attr;
        stable_sort(arr.begin(), arr.end(), comp);
        for(auto x: temparr){
            cout << x << " ";
        }
        cout << el;
        for (int j = 0; j < (int) arr.size(); j++) {
            for (int k = 0; k < (int)arr[j].size(); k++) {
               cout << arr[j][k] << " "; 
            }
            cout << el;
        }
        cout << el;


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

