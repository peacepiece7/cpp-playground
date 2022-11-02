/*
https://www.acmicpc.net/problem/1620

ù° �ٺ��� ���ʴ�� M���� �ٿ� ������ ������ ���� ���� ���������� ���ھ�!!!. 
�Է����� ���ڰ� ���Դٸ� �� ���ڿ� �ش��ϴ� ���ϸ��� �̸���, 
���ڰ� �������� �� ���ϸ��� �̸��� �ش��ϴ� ��ȣ�� ����ϸ� ��. 
�׷� ��ť~

-- �Է�
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
// ������� �ϳ��� �Է��غ���
25
Raichu
3
Pidgey
Kakuna
--

--���
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