//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char dict[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int main(int argc, const char * argv[]) {
    int T,N;
    freopen("A-large-practice.in.txt","r",stdin);
    freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    char S[2010];
    vector<int> m(26, 0);
    for(int t=1;t<=T;t++)
    {
        scanf("%s", S);
        for (int i = 0; S[i] != 0; i++) {
            m[S[i] - 'A']++;
        }
        vector<int> ans(10, 0);
        while (m['Z' - 'A']) {
            for (int i = 0; dict[0][i] != 0; i++) {
                m[dict[0][i] - 'A']--;
            }
            ans[0]++;
        }
        while(m['W' - 'A']) {
            for (int i = 0; dict[2][i] != 0; i++) {
                m[dict[2][i] - 'A']--;
            }
            ans[2]++;
        }
        while(m['X' - 'A']) {
            for (int i = 0; dict[6][i] != 0; i++) {
                m[dict[6][i] - 'A']--;
            }
            ans[6]++;
        }
        while(m['U' - 'A']) {
            for (int i = 0; dict[4][i] != 0; i++) {
                m[dict[4][i] - 'A']--;
            }
            ans[4]++;
        }
        while(m['G' - 'A']) {
            for (int i = 0; dict[8][i] != 0; i++) {
                m[dict[8][i] - 'A']--;
            }
            ans[8]++;
        }
        while(m['F' - 'A']) {
            for (int i = 0; dict[5][i] != 0; i++) {
                m[dict[5][i] - 'A']--;
            }
            ans[5]++;
        }
        while(m['O' - 'A']) {
            for (int i = 0; dict[1][i] != 0; i++) {
                m[dict[1][i] - 'A']--;
            }
            ans[1]++;
        }
        while(m['R' - 'A']) {
            for (int i = 0; dict[3][i] != 0; i++) {
                m[dict[3][i] - 'A']--;
            }
            ans[3]++;
        }
        while(m['V' - 'A']) {
            for (int i = 0; dict[7][i] != 0; i++) {
                m[dict[7][i] - 'A']--;
            }
            ans[7]++;
        }
        while(m['N' - 'A']) {
            for (int i = 0; dict[9][i] != 0; i++) {
                m[dict[9][i] - 'A']--;
            }
            ans[9]++;
        }
        printf("Case #%d: ",t);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < ans[i]; j++) {
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
