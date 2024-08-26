#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
int n;
ll k;
int needed[7];
bool can (int have[], int needed[], int price[], ll mid){
    ll money = k;
    for (int i = 0; i < 7; i++){
            ll required = needed[i] * mid;
        //if (required < have[i]){
        //    continue;
        //}
        if (required > have[i]){
            money -= (required - have[i]) * price[i];
        }
    }
    if (money >= 0) {
        return true;
    }
    else {
        return false;
    }
}

/*
bread = B
sausage = S
cheese = C
tomato = T
lettuce = L
pickles = P
onions = O


The ingredients in the recipe go from bottom to top,
for example, recipe "ВSCBS" represents the hamburger where the ingredients
go from bottom to top as bread, sausage, cheese, bread and sausage again.

thinking of defining the ingredients where the user will set the ingredients and the character representing them
ex: pickles = P
bread = B
so on...
till they say "recipe:"
then the code runs normally



*/

int main()
{
ios::sync_with_stdio(0); cin.tie(0);
 /*
string inp;
map <string, char> ingr;
string ingredient;
char symbl;
map <char, int> letter;
int cntr = 0;
while (inp != "recipe:"){
    getline(cin, inp);
    for (int i = 0; i < inp.size(); i++){
        if (inp[i] != "=" && inp[i] != " "){
            ingredient += inp[i];
        }
        else {
            if (inp[i + 1] != " "){symbl = inp[i +1];}
            else {symbl = inp[i +1];  }
             ingr[ingredient] = cntr;

             letter[cntr] = symbl;
             cntr++;
            continue;
        }
    }
}



*/

string s;
cin >> s;
for (int i = 0; i < s.size(); i++){
    if (s[i] == 'B'){
        needed[0]++;
    }
    else if (s[i] == 'S'){
        needed[1]++;
    }
    else if (s[i] == 'C'){
        needed[2]++;
    }
 else if (s[i] == 'T'){
        needed[3]++;
    }
     else if (s[i] == 'L'){
        needed[4]++;
    }
     else if (s[i] == 'P'){
        needed[5]++;
    }
     else if (s[i] == 'O'){
        needed[6]++;
    }
}
int have[7];
int price[7];
for (int i = 0; i < 3; i++){
    cin >> have[i];
}
for (int i = 0; i < 3; i++){
    cin >> price[i];
}
cin >> k;
ll l = 0, r = 1e15;
ll mid;
ll ans = 0;
while (l <= r){
    mid = (l + r) / 2;
    if (can(have, needed, price, mid)){
        ans = mid;
        l = mid + 1;
    }
    else {
        r = mid - 1;
    }
}
cout << ans << endl;

    return 0;

}
