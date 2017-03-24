#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct party {
    int num;
    char name;
    party(int num, char name): num(num), name(name) {}
};

struct cmp {
    bool operator() (const party a, const party b) {
        return a.num < b.num;
    }
};

int main(int argc, const char * argv[]) {
    int T;
    freopen("A-large-practice.in.txt","r",stdin);
    freopen("A-large-practice.out.txt","w",stdout);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, P;
        cin >> N;
        priority_queue<party, vector<party>, cmp> q;
        for (int i = 0; i < N; i++) {
            cin >> P;
            q.push(party(P, 'A' + i));
        }
        cout << "Case #" << t << ":";
        while (!q.empty()) {
            party x = q.top();
            q.pop();
            party y = q.top();
            q.pop();
            if (q.empty()) {
                if (x.num == y.num) {
                    x.num--;
                    y.num--;
                    cout << " " << x.name << y.name;
                } else {
                    x.num -= 1;
                    cout << " " << x.name;
                }
            } else if (x.num == 1 and (int)q.size() == 1) {
                x.num--;
                cout << " " << x.name;
            } else {
                x.num--;
                y.num--;
                cout << " " << x.name << y.name;
            }
            if (x.num > 0) q.push(x);
            if (y.num > 0) q.push(y);
        }
        cout << endl;
    }
    return 0;
}
