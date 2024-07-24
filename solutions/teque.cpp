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
    deque<int> depan;
    deque<int> belakang;
    for (int i = 0; i < n; i++) {
        string s; int x;
        cin >> s >> x;
        if(s == "push_back"){
            belakang.push_back(x);
            if(belakang.size() > depan.size()){
                depan.push_back(belakang.front());
                belakang.pop_front();
            }
        }
        if(s == "push_front"){
            depan.push_front(x);
            if(depan.size() > belakang.size() + 1){
                belakang.push_front(depan.back());
                depan.pop_back();
            }
        }
        if(s == "push_middle"){
            if(depan.size() > belakang.size())
                belakang.push_front(x);
            else
                depan.push_back(x);
        }
        if(s == "get"){
            if(x >= (int) depan.size())
                cout << belakang[x - (int) depan.size()] << el;
            else
                cout << depan[x] << el;
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

