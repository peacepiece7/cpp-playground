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
	// v.begin() v[0]를 가르키고 있는 포인터; 값은 0 {key : pointer , value : 0}
	for (int i = 0; i < 5; i++)
	{
		cout << i << "번째 요소 :" << *(v.begin() + i) << " " << *v.begin() << " " << *(v.end() - 1) << endl;
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
	printf("arr은 arr[]의 주소를 가르킨다 arr, arr+1, arr+2");
	cout << arr << endl; // 주소가 나오지는 않음
	goarr(arr);
	for (int i : arr) cout << i << endl;

	return 0;
}