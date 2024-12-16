#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define ll long long
#define ld long double
#define endl "\n"
#define mod 1000000007
const int N = 1e7;

int n , ans = 0;
vector<vector<char>>res;
bool isValid(int r , int c) {
    for(int r1 = r - 1 , c1  = c - 1 ; c1 >=0 && r1 >= 0 ; r1-- , c1--) if(res[r1][c1]=='Q') return false;
    for(int r1 = r - 1 , c1  = c + 1 ; c1 < n && r1 >= 0 ; r1-- , c1++) if(res[r1][c1]=='Q') return false;
    for(int r1 = r - 1 , c1 = c ;  r1 >= 0 ; r1-- ) if(res[r1][c1]=='Q') return false;
    return true;
}
void rec(int idx) {
    if(idx == n) {
        ans++;
        cout<<"The Solution Number " << ans <<endl;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cout<<res[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int c = 0 ; c < n ; c++) {
        if(isValid(idx , c)) {
            res[idx][c] ='Q';       
            rec(idx + 1);           //recurse
            res[idx][c] = '.';      //Undo
        }
    }
}
signed main() {
    cout<<"How many times you want to play"<<endl;
    int t;cin>>t;
    while(t--) {
        cout<<"     ((      HERE IS THE GAME      ))     "<<endl;
        cout<<"!! ENTER NUMBER I GET YOU ALL OPTIMAL SOLUTIONS WITHOUT LOSE !!"<<endl;
        ans = 0;
        res.clear(); //clear the board
        cin>>n;
        res = vector<vector<char>>(n, vector<char>(n,'.'));
        rec(0);
    }
    return 0;
}
