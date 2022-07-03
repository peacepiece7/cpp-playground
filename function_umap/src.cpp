#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int v[10];
int main() {
	// �������� ������ ������� ����!
	unordered_map<string, int> umap;

	umap.insert({ "test", 1 });
	umap.emplace("test2", 2);
	umap["test3"] = 3; // recommaned


	for (pair<string, int> element : umap)
	{
		cout << element.first << " : " << element.second << endl;
	}

	// find�޼ҵ尡 �־��� ���ڸ� ã�� ���ϸ� end()���ͷ����͸� ��ȯ��
	auto query = umap.find("test3");

	if (query != umap.end())
	{
		// ���� "query"�� ���������� ȣ���� �� ����.. �̷� �ֵ��� �� �� �ִ��� �� ģ���� ���ͷ����Ͷ����
		cout << "Address : " << &query << endl;
		cout << "FOUND :" << query->first << " : " << (*query).second << endl;
	}
	else
	{
		cout << "NOT FOUND" << endl;
	}


	printf("%s\n", "key�� value�� ���������� ������ �� ����");
	cout << umap["test3"] << endl;
	umap["test3"]++;
	cout << umap["test3"] << endl;


	printf("%s\n", "size(). erase()");
	cout << "same " << umap.size() << " as " << sizeof(umap) << endl;
	umap.erase("test1");
	cout << "same " << umap.size() << " as " << sizeof(umap) << endl;
}
