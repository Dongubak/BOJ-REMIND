#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d_remain = 0, p_remain = 0;  // 배달 및 수거 남은 개수
    
    for (int i = n - 1; i >= 0; i--) {  // 가장 먼 위치부터 탐색
        d_remain += deliveries[i];
        p_remain += pickups[i];
        
        while (d_remain > 0 || p_remain > 0) {  // 처리할 택배가 남아 있으면
            answer += (i + 1) * 2;  // 왕복 거리 추가
            d_remain -= cap;  // 트럭 용량만큼 배달
            p_remain -= cap;  // 트럭 용량만큼 수거
        }
    }
    
    return answer;
}