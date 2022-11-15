/*
https://www.acmicpc.net/problem/2588

- 곱하는 과정을 순서대로 출력하면 되는 문제 (3)(4)(5)는 각 자리수의 곱, (6)은 전체를 곱한 결과

출력
첫째 줄부터 넷째 줄까지 차례대로 (3), (4), (5), (6)에 들어갈 값을 출력한다.

예제 입력 1 
472
385
예제 출력 1 
2360
3776
1416
181720
*/

#include <stdio.h>
using namespace std;
// 세자리 * 세자리
int a,b;
int main()
  {
    scanf("%d\n %d", &a, &b);
    int c = b;
    for(int i = 0 ; i < 3; i++)
    {
        printf("%d\n", a * (b % 10));
        b = b / 10;
    }
    printf("%d", a*c);
    return 0;
  }