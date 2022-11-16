/*
https://www.acmicpc.net/submit/2309/46252179

����
�պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�. �ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.

��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. �پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.

��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
��ȩ ���� �ٿ� ���� �����̵��� Ű�� �־�����. �־����� Ű�� 100�� ���� �ʴ� �ڿ����̸�, ��ȩ �������� Ű�� ��� �ٸ���, ������ ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.

���
�ϰ� �������� Ű�� ������������ ����Ѵ�. �ϰ� �����̸� ã�� �� ���� ���� ����.
*/

#include<bits/stdc++.h>
using namespace std;
int arr[10];
vector<int> v;
int x;
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			int sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j) sum += arr[k];
				if (sum > 100) break;
			}
			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) v.push_back(arr[k]);
				}
				break;
			}
		}
		if (v.size() != 0) break;
	}
	
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << "\n";
	return 0;
}


/*
* next-permutation���� ���� �����
#include<bits/stdc++.h>;
using namespace std;

int p[9];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) cin >> p[i];
	sort(p, p+9);
	int k = 0;
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++)	sum += p[i];
		if (sum == 100) break;

	} while (next_permutation(p,p + 9));


	for (int i = 0; i < 7; i++)
	{
		cout << p[i] << "\n";
	}
	return 0;
}

*/