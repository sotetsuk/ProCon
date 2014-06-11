#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> cow;
typedef pair<int, int> lotion;

int C, L;
priority_queue<cow> que;
vector<cow> v_cow;
vector<lotion> v_lotion;

int main() {
    // input
    cin >> C >> L;
    int minSPC, maxSPC;
    for(int i = 0; i < C; i++) {
        cin >> minSPC >> maxSPC;
        v_cow.push_back(cow(minSPC, maxSPC));
    }
    int SPC, cover;
    for(int i = 0; i < L; i++) {
        cin >> SPC >> cover;
        v_lotion.push_back(lotion(SPC, cover));
    }

    sort(v_cow.begin(), v_cow.end());
    sort(v_lotion.begin(), v_lotion.end());

    int ix = 0;
    int s = 0;
    priority_queue<cow> que;
    for(int i = 0; i < L; i++) {
        SPC = v_lotion[i].first;
        cover = v_lotion[i].second;

        while(ix < C) {
            minSPC = v_cow[ix].first;
            maxSPC = v_cow[ix].second;
            if(minSPC > SPC) break;
            que.push(cow(-maxSPC, minSPC));
            ix++;
        }

        while(cover > 0 && que.size() > 0) {
            cow c = que.top(); que.pop();
            minSPC = c.second;
            maxSPC = -c.first;
            if(maxSPC >= SPC) {
                s++;
                cover--;
            } else {
                continue;
            }
        }
    }

    cout << s << endl;
    return 0;
}
