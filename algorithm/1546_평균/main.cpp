/*
https://www.acmicpc.net/problem/1546
세준이는 기말고사를 망쳤다. 세준이는 점수를 조작해서 집에 가져가기로 했다. 일단 세준이는 자기 점수 중에 최댓값을 골랐다. 
이 값을 M이라고 한다. 그리고 나서 모든 점수를 점수/M*100으로 고쳤다.
예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 50/70*100이 되어 71.43점이 된다.
세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.

첫째 줄에 새로운 평균을 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10-2이하이면 정답이다.

3
40 80 60
-> 75.0

3
10 20 30
-> 666.66667

4
1 100 100 100
75.25
*/

#include<iostream>
using namespace std;
double arr[1004], n, mx;

int main() {
	cin >> n;
	cout.precision(6);
	cout.fixed;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(arr[i], mx);
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i] / mx * 100;
	}
	cout << sum / n << "\n";
}