#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1000;
bool arr[MAX_N + 1000];
int N = 1000;

int main() {
    for(int i = 0; i < MAX_N + 1000; i++) {
        arr[i] = true;
    }

    for(int i = 1; i <= N; i++) {
        if(arr[i]) {
            printf("? %d\n", i); fflush(stdout);
            char judge[2]; scanf("%s", judge);
            if(judge[0] == 'N') {
                for(int j = 1; j <= N; j++) {
                    if(i*j > N) break;
                    arr[i*j] = false;
                }
            }
        }
    }

    int ans = 1;
    for(int i = 1; i <= N; i++) {
        if(arr[i]) ans = i;
    }

    printf("! %d\n", ans); fflush(stdout);

    return 0;
}
