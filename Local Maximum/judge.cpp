#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int n, a[maxn];

inline int random(int a, int b){
    return rand() % (b - a + 1) + a;
}

int main(){
    srand(time(0));
    n = random(100, maxn);
    cout << n << endl;
    cout.flush();
    for(int i = 0; i < n; i++)
        a[i] = rand();
    int questions = 3 * log2(n) + 10;
    sort(a + n / 2, a + n / 2 + questions);
    sort(a + n / 2 - questions, a + n / 2, greater<int>());
    sort(a, a + questions);
    sort(a + n - questions, a + n, greater<int>());
    while(questions--){
        char c;
        int i;
        if(!(cin >> c)){
            cout << "Insufficient interaction" << endl;
            return 1;
        }
        if(c == '?'){
            if(!(cin >> i)){
                cout << "Wrong or insufficient interaction" << endl;
                return 1;
            }
            if(i < 0 || i >= n){
                cout << "Incorrect indices" << endl;
                return 1;
            }
            cout << a[i] << endl;
            cout.flush();
        }
        else if(c == '!'){
            if(!(cin >> i)){
                cout << "Wrong or insufficient interaction" << endl;
                return 1;
            }
            if(i < 0 || i >= n){
                cout << "Incorrect indices" << endl;
                return 1;
            }
            if((i && a[i-1] > a[i]) || (i < n-1 && a[i+1] > a[i])){
                cout << "Wrong Answer" << endl;
                return 1;
            }
            cout << "Accepted" << endl;
            return 0;
        }
        else{
            cout << "Wrong interaction" << endl;
            return 1;
        }
    }
    cout << "Too many questions" << endl;
    return 1;
}
