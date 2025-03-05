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

typedef tuple<int, int> ii;

const ll INF = numeric_limits<int>::max();
const ll MOD = 1e9 + 7;
const int mod = 99824435;

void solve() {

  int n, k;
  cin >> n >> k;

  multiset<int> c;
  for (int i = 0; i < k; i++) {
    c.insert(0);
  }

  vector<ii> arr(n);
  for (int i = 0; i < n; i++) {
    int s, f;
    cin >> s >> f;
    arr[i] = {f, s};
  }

  sort(arr.begin(), arr.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto [f, s] = arr[i];
    auto it = c.lower_bound(s);
    if (it == c.begin())
      continue;
    if (*(--it) < s) {
      c.erase(it);
      c.insert(f);
      ans++;
    }
  }
  cout << ans << el;

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
