#include <bits/stdc++.h>
#include <vector>

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

  int n, cnt = 1;
  while (cin >> n) {
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int m;
    cin >> m;
    int q[m];
    for (int i = 0; i < m; i++) {
      cin >> q[i];
    }

    int size = n * (n + 1) / 2 - n;
    int com[size];
    int p = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        com[p] = arr[i] + arr[j];
        p++;
      }
    }
    sort(com, com + size);

    int ans[m];
    for (int i = 0; i < m; i++) {
      ans[i] = com[0];
      int diff = abs(com[0] - q[i]);
      for (int j = 0; j < size; j++) {
        int tempdiff = abs(com[j] - q[i]);
        if (tempdiff <= diff) {
          ans[i] = com[j];
          diff = tempdiff;
        } else {
          break;
        }
      }
    }

    cout << "Case " << cnt << ":" << el;
    for (int i = 0; i < m; i++) {
      cout << "Closest sum to " << q[i] << " is " << ans[i] << "." << el;
    }
    cnt++;
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
