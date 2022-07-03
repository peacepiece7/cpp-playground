#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int v[10];
int main() {
	// 빠르지만 순서가 보장되지 않음!
	unordered_map<string, int> umap;

	umap.insert({ "test", 1 });
	umap.emplace("test2", 2);
	umap["test3"] = 3; // recommaned


	for (pair<string, int> element : umap)
	{
		cout << element.first << " : " << element.second << endl;
	}

	// find메소드가 주어진 인자를 찾지 못하면 end()이터레이터를 반환함
	auto query = umap.find("test3");

	if (query != umap.end())
	{
		// 변수 "query"를 직접적으로 호출할 수 없음.. 이런 애들이 몇 개 있던데 이 친구는 이터레이터라고함
		cout << "Address : " << &query << endl;
		cout << "FOUND :" << query->first << " : " << (*query).second << endl;
	}
	else
	{
		cout << "NOT FOUND" << endl;
	}


	printf("%s\n", "key의 value을 직접적으로 증감할 수 있음");
	cout << umap["test3"] << endl;
	umap["test3"]++;
	cout << umap["test3"] << endl;


	printf("%s\n", "size(). erase()");
	cout << "same " << umap.size() << " as " << sizeof(umap) << endl;
	umap.erase("test1");
	cout << "same " << umap.size() << " as " << sizeof(umap) << endl;
}
