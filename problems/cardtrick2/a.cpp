#include <bits/stdc++.h>
#include <queue>

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

  int n;
  cin >> n;

  vector<vector<int>> ans;

  // preproccess

  queue<int> q;
  for (int i = 1; i <= 13; i++) {
    q = {}; // clear
    vector<int> tempans(i);
    // fill
    for (int j = 0; j < i; j++) {
      q.push(j);
    }

    // first iter
    for (int j = 1; j <= i; j++) {
      for (int k = 0; k < j; k++) {
        int temp = q.front();
        q.pop();
        q.push(temp);
      }
      int temp = q.front();
      tempans[temp] = j;
      q.pop();
    }
    ans.pb(tempans);
  }

  while (n--) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      cout << ans[k - 1][i] << " ";
    }
    cout << el;
  }

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
