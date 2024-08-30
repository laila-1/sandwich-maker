#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<char, int> symb_idx;
vector<int> needed;
vector<int> have;
vector<int> price;
ll k;

bool can(const vector<int>& have, const vector<int>& needed, const vector<int>& price, ll mid) {
    ll money = k;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (symb_idx.find(c) != symb_idx.end()) {
            int idx = symb_idx[c];
            ll required = needed[idx] * mid;
            if (required > have[idx]) {
                money -= (required - have[idx]) * price[idx];
            }
        }
    }
    return money >= 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cout << "Please enter the number of ingredients for your sandwich!!" << endl;
    cin >> num;

    symb_idx.clear();
    needed.resize(num, 0);
    have.resize(num, 0);
    price.resize(num, 0);

    cout << "Please enter the symbols representing each ingredient and their price:" << endl;
    for (int i = 0; i < num; i++) {
        char symbol;
        int p;
        cout << "Symbol " << (i + 1) << ": " << endl;
        cin >> symbol;
        cout << "Price for " << symbol << ": " << endl;
        cin >> p;
        symb_idx[symbol] = i;
        price[i] = p;
    }

    string s;
    cout << "Please enter the recipe using the symbols: " << endl;
    cin >> s;

    for (char c : s) {
        if (symb_idx.find(c) != symb_idx.end()) {
            needed[symb_idx[c]]++;
        }
    }

    cout << "Please enter the amount you have of each ingredient (in the same order as entered):" << endl;
    for (int i = 0; i < num; i++) {
        cout << "Quantity for ingredient " << (i + 1) << ": " << endl;
        cin >> have[i];
    }

    cout << "Please enter the budget!" << endl;
    cin >> k;

    // binary search to find the maximum number of sandwiches u can make
    ll l = 0, r = 1e12;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (can(have, needed, price, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << "Maximum number of sandwiches you can make: "<< endl << ans << endl;

    return 0;
}
