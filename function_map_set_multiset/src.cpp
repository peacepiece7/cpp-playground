#include <bits/stdc++.h>;
using namespace std;

int main() {
	// map
	printf("%s\n", "map usage, method is same as unordered map");
	map<string, int> _map;
	_map["bar"]++;
	_map["bar"]++;
	_map["foo"]++;
	for (pair<string, int> c : _map) cout << c.first << " : " << c.second << endl;

	// set
	set<pair<string, int>> st;
	printf("%s\n", "unique key & value, duplicated element will be remove");
	st.insert({ "test",1 });
	st.insert({ "test",1 });
	st.insert({ "test",1 });
	st.insert({ "test",1 });
	cout << st.size() << endl;

	set<int> st2;
	st2.insert(1);
	st2.insert(1);
	st2.insert(2);
	st2.insert(1);

	for (int i : st2) cout << i << endl;

	// multiset, set duplicative multi element after sort
	multiset<int> ms;
	ms.insert(12);
	ms.insert(10);
	ms.insert(2);
	ms.insert(90);
	ms.insert(85);
	ms.insert(45);
	ms.insert(14);
	ms.insert(16);
	ms.insert(12);
	ms.insert(11);

	printf("%s\n", "multi set");
	for (auto i = ms.begin(); i != ms.end(); i++) {
		cout << &i << endl;
		cout << *i << endl;
	};

	printf("%s\n", "find");
	auto it1 = ms.find(45);
	auto it2 = ms.find(90);

	// cout << it1 << endl;
	cout << &it1 << endl;
	cout << *it1 << endl;

	cout << &it2 << endl;
	cout << *it2 << endl;

	printf("%s\n", "erase");
	ms.erase(it1, it2); // iterator를 parameter로 받음
						// string을 erase할 경우 정수를 parameter로 받음
	for (auto i = ms.begin(); i != ms.end(); i++)
	{
		cout << *i << endl;
	}

	ms.erase(ms.begin()); // erase first element
	printf("%s\n", "erase after");
	for (auto i = ms.begin(); i != ms.end(); i++)
	{
		cout << *i << endl;
	}
	return 0;
};