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

  vector<vector<int>> numbers;
  string line;

  while (getline(cin, line)) {
    istringstream ss(line);
    vector<int> v((istream_iterator<int>(ss)), istream_iterator<int>());
    numbers.push_back(v);
  }

  for (const auto &row : numbers) {
    int maks = -1;
    for (int num : row) {
      maks = ((num > maks) ? num : maks);
    }
    vector<int> arr(maks + 1, 0);
    for (int i = 0; i < (int)size(row); i++) {
      for (int j = i + 1; j < (int)size(row); j++) {
        arr[abs(row[i] - row[j])]++;
      }
    }
    bool golomb = true, miss = false;
    for (int i = 1; i < maks + 1; i++) {
      if (!arr[i]) {
        miss = true;
      }
      if (arr[i] > 1) {
        golomb = false;
      }
    }
    if (!golomb) {
      cout << "not a ruler" << el;
    } else {
      if (!miss) {
        cout << "perfect" << el;
      } else {
        cout << "missing ";
        for (int i = 1; i < maks + 1; i++) {
          if (!arr[i])
            cout << i << " ";
        }
        cout << el;
      }
    }
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
