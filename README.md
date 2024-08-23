# BOJ REMIND
 >boj문제 다시 풀이 <br />
 >입출력 기본문제들은 풀이X

 
# 문제 풀이 기록

| 문제 번호 | 문제 이름 | 티어 | 알고리즘 분류          | 코멘트                                                     |
|-----------|----------|-----------|------------------------|------------------------------------------------------------|
| 1002 | 터렛 | Silver 3 | 기하 | 원의 위치에 따른 관계를 잘 파악해야 함 내부에서 작은원이 접하는 경우도 고려 |
| 1003 | 피보나치함수 |Silver 3 | DP |적절한 캐시와 구현 필요(DP누적), 0의 개수와 1의 개수의 규칙을 찾아도 됨|
| 1004 | 어린 왕자 |Silver 3 | 기하 | 원의 방정식과 부등식 |
| 1010 | 다리놓기 |Silver 5 | DP | 조합수를 구할 때 cache로 최적화 하기 |
| 1012 | 유기농 배추 |Silver 5 | BFS | nr, nc, 행과 열을 제대로 작성해야함 |
| 11660 | 구간합 구하기 5 |Silver 1 | prefix sum | 2차원 행렬에서의 각 행에 대한 구간 합을 구함 dp풀이는 아직 시기 상조인 듯|
| 1018 | 체스판 다시 칠하기 |Silver 4 | prefix sum | 나중에 풀이|
| 1026 | 보물 |Silver 4 | sort | 두 배열의 0부터 끝까지 원소들의 곱의 합이 최소가 되도록 하는 조건|
| 1049 | 기타줄 |Silver 4 | Greedy | 묶음으로 몫 + 1만큼 구매하는 경우, 낱개로만 구매하는 경우, 묶음 + 낱개로 구매하는 경우 중 최솟값|
| 1051 | 숫자 정사각형 |Silver 3 | BruteForce | 정사각형을 찾는 과정에서 인덱스가 오버되는 경우를 예외처리 해주는 것 |
| 16134 | 조합(Combination) |Gold 1 | 정수론 | 모듈러 역수, 분할 정복을 통한 빠른 거듭제곱 |
| 1065 | 한수 |Silver 4 | BruteForce | 실수한 부분 : 특정한 수에 대해서 선형조사를 한 후 모두 만족한 경우에 대해서 카운트 해야함 |
| 1138 | 한줄로서기 |Silver 2 | Greedy? | `A[i]`만큼 이동한 뒤 그 곳에 값이 있다면 비어있는 곳을 찾아감, 단 왼쪽에 있는 수들 중 현재 수보다 큰 수들의 개수도 맞아야함 맞지 않다면 맞을 때 까지 이동하기|
| 1149 | RGB거리 |Silver 1 | DP | 각각의 색상을 N번째에 칠 했을 경우에 대해 최솟값들을 저장, xor최적화 불가|
| 1158 | 요세푸스문제 |Silver 4 | datastructure | 큐를 사용하는 것이 더 쉬울 듯 하면 큐를 먼저 사용해보기 |
| 1181 | 단어정렬 |Silver 5 | sort | set을 사용하지 않고 람다표현식을 이용하여 sort하기, set사용시 시간과 메모리 너무 많이 먹음 |
| *1182 | 부분수열의 합 |Silver 2 | bruteforce | 생짜 브루트 포스로 구현할 때 파라미터 설정 잘하기(타뷸레이션, offset을 이용한 dp로의 최적화는 다음에 해보기) |
| 1629 | 곱셈 |Silver 1 | divconq | 분할정복을 이용한 거듭제곱 O(logn)최적화 |
| 11401 | 이항계수3 |Gold 1 | 정수론, divconq | 모듈러 역수, 분할정복 최적화 |
| 10830 | 행렬제곱 |Gold 4 | linear Algebra, divconq | 분할정복, 행렬의 0제곱 단위행렬, 곱셈과 다르게 `(i - 1) / 2`를 안하고 홀수인 경우에 그냥 A한번더 곱해줌 |
| 11444 | 피보나치수 6 |Gold 2 | linear Algebra, divconq, matrix | 피보나치 수열 N의 크기가 매우 큰 경우 효율적으로 계산하기 위한 행렬 제곱계산 M = ((1, 1), (1, 0)), M^n =((f(n + 1), f(n)), (f(n), f(n - 1))|
| 1780 | 종이의 개수 |Silver 2 | divconq | 실수한 부분 : 주어진 행렬을 9개씩 분할하는 경우 한변의 길이는 1/3씩 줄어야 함|
| 1753 | 최단경로 |Gold 4 | dijkstra | previous sht와 current sht가 서로 다른 경우 중복된 연산을 방지할 수 있음|
| 1238 | 파티 |Gold 3 | dijkstra | 모든 정점에 대해서 sht를 작성한 뒤 각 정점에 대해서 K까지의 거리와 정점에서 K까지의 거리 합의 최댓값을 구하는 문제|
| 12015 | 가장 긴 증가하는 부분수열 2 |gold 2 | binarySearch | dp배열의 마지막 원소보다 큰 경우 dp배열에 추가하며 아닌 경우 이분탐색으로 적절한 원소의 위치를 찾아 수정함(가장 긴 부분수열의 길이만 구할 수 있음)|
| 1219 | 오민식의 고민 |platinum 5 | dijkstra, BellmanFord, BFS | 다익스트라 알고리즘을 통해 longestpath를 구한 뒤 Bellmanford를 통해 longest path를 w값을 이용하여 업데이트하며. 이때 양수 가중치 사이클을 검사하고 사이클이 발생한 정점들에 대해서 기록한다. 각각의 정점들에서 BFS탐색을 통해 도착정점으로의 경로가 존재하면 양수 가중치 사이클이 존재하는 것이다.|
| 1920 | 수 찾기 |silver 4 | 이분탐색 기초 문제, 정렬된 배열에 대해서 이분탐색 가능함(monotonous)|
| 16916 | 부분문자열 |Bronze 2 | 문제의 난이도 상 Bruteforce로 풀린다. 하지만 부분문자열을 O(|s| * |p|)가 아닌 O(|s| + |p|)로 찾을 수 있는 KMP 알고리즘을 사용할 수 있다. 실패함수로 failure array를 작성한 뒤 접두사와 접미사가 같은 최대 길이를 통해 연산을 줄인다.|
# 기하학, 정수론
https://github.com/Dongubak/DataStructureAndAlgorithm/tree/main/%EA%B8%B0%ED%95%98%ED%95%99

# 다익스트라, 벨만포드, 코사라주
https://github.com/Dongubak/DataStructureAndAlgorithm/tree/main/%EA%B7%B8%EB%9E%98%ED%94%84%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98