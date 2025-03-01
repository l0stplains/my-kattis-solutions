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

  int n;
  cin >> n;
  vector<int> inp(n);
  vector<int> arr(7, 0);

  for (int i = 0; i < n; i++) {
    cin >> inp[i];
    arr[inp[i]]++;
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    if (arr[inp[i]] == 1) {
      if (ans == -1) {
        ans = i;
      } else {
        ans = ((inp[i] > inp[ans]) ? i : ans);
      }
    }
  }

  if (ans != -1) {
    cout << ans + 1;
  } else {
    cout << "none";
  }
  cout << el;

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
