#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void go(int &idx) {
	idx = 1;
}
void goback(int idx) {
	idx = 100;
}

void goarr(int arr[]) {
	arr[1] = 200;
}

int main() {
	vector<int> v;

	for (int i = 1; i <= 5; i++) v.push_back(i);
	// v.begin() v[0]�� ����Ű�� �ִ� ������; ���� 0 {key : pointer , value : 0}
	for (int i = 0; i < 5; i++)
	{
		cout << i << "��° ��� :" << *(v.begin() + i) << " " << *v.begin() << " " << *(v.end() - 1) << endl;
		cout << &*(v.begin() + i) << endl;
	} 

	// call by reference 
	int index = 2;

	cout << index << endl;
	go(index);
	cout << index << endl;
	goback(index);
	cout << index << endl;

	// array * pointer
	int arr[3] = { 1,2,3 };
	printf("arr�� arr[]�� �ּҸ� ����Ų�� arr, arr+1, arr+2");
	cout << arr << endl; // �ּҰ� �������� ����
	goarr(arr);
	for (int i : arr) cout << i << endl;

	return 0;
}