#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
using namespace std;

int p[8];
int d[4] = {-1, 1, -4, 4};
map<string, int> m;

int dfs() {
    string s = "01234567";
    int count = 0;
    int pos;

    queue<string> q;
    q.push(s);
    m[s] = count;
    while(q.size()) {
        s = q.front(); q.pop();
        count = m[s];
        pos = s.find('0');

        for(int i = 0; i < 4; i++) {
            if(0 <= pos+d[i] && pos+d[i] < 8 &&
            !(pos == 3 && d[i] == 1) && !(pos == 4 && d[i] == -1)) {
                string s_next = s;
                swap(s_next[pos], s_next[pos+d[i]]);
                if(m.find(s_next) == m.end()) {
                    q.push(s_next);
                    m[s_next] = count+1;
                }
            }
        }
    }

    return 0;
}

int main() {
    dfs();

    while(cin >> p[0]) {
        for(int i = 1; i < 8; i++) {
            cin >> p[i];
        }
        stringstream ss;

        for(int i = 0; i < 8; i++) {
            ss << p[i];
        }
        string s = ss.str();

        cout << m[s] << endl;
    }

    return 0;
}
