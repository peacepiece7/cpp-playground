/*
https://www.acmicpc.net/problem/1620

첫째 줄부터 차례대로 M개의 줄에 각각의 문제에 대한 답을 말해줬으면 좋겠어!!!. 
입력으로 숫자가 들어왔다면 그 숫자에 해당하는 포켓몬의 이름을, 
문자가 들어왔으면 그 포켓몬의 이름에 해당하는 번호를 출력하면 돼. 
그럼 땡큐~

-- 입력
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
// 여기부터 하나씩 입력해보자
25
Raichu
3
Pidgey
Kakuna
--

--출력
Pikachu
26
Venusaur
16
14
--
*/

#include<map>
#include<iostream>
#include<string>
using namespace std;
int n, m;
string s;
map<int, string> mpIntKey;
map<string, int> mpStrKey;

void match(int a) {
	cout << mpIntKey[a] << "\n";
}
void match(string a) {
	cout << mpStrKey[a] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		mpIntKey[i] = s;
		mpStrKey[s] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (atoi(s.c_str())) match(atoi(s.c_str()));
		else match(s);
	}

}