#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define el "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fast                                                                   \
  cin.sync_with_stdio(0);                                                      \
  cin.tie(0);

const ll INF = numeric_limits<int>::max();
const ll MOD = 1e9 + 7;
const int mod = 99824435;

void solve() {

  vector<int> ans(5, 0);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      int temp;
      cin >> temp;
      ans[i] += temp;
    }
  }

  int maksi = 0;
  for (int i = 0; i < 5; i++) {
    maksi = (ans[i] > ans[maksi]) ? i : maksi;
  }
  cout << maksi + 1 << " " << ans[maksi] << el;

  return;
}

int main() {
  fast;
  int TC = 1; // cin >> TC;
  for (int i = 1; i <= TC; i++) {
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
